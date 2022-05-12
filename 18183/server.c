#include <openssl/ct.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 24323

unsigned char serverinfo18[] = {
    //0x00, 0x00, 0x11, 0x80,
    0x00, 0x12,
    0x00, 0x03,
    0x04, 0x05, 0x06
};

int main() {
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Unable to bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 1) < 0) {
        perror("Unable to listen");
        exit(EXIT_FAILURE);
    }

    SSL_CTX *ctx = SSL_CTX_new(TLS_server_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    SSL_CTX_set_mode(ctx, SSL_MODE_AUTO_RETRY);

    SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);

    SSL_CTX_set_options(ctx, SSL_OP_NO_RENEGOTIATION);

    if (SSL_CTX_use_certificate_file(ctx, "tmp.crt", SSL_FILETYPE_PEM) <= 0) {
	fprintf(stderr, "Unable to use certificate:\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_PrivateKey_file(ctx, "tmp.key", SSL_FILETYPE_PEM) <= 0 ) {
	fprintf(stderr, "Unable to use key:\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_serverinfo(ctx, serverinfo18, sizeof(serverinfo18)) != 1) {
    //if (SSL_CTX_use_serverinfo_ex(ctx, SSL_SERVERINFOV2,
    //                              serverinfo18, sizeof(serverinfo18)) != 1) {
	fprintf(stderr, "Unable to use serverinfo18:\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    while (1) {
        struct sockaddr_in saddr;
        unsigned int len = sizeof(saddr);
        SSL *ssl;

        int client = accept(sock, (struct sockaddr*)&saddr, &len);
        if (client < 0) {
            perror("Unable to accept");
            continue;
        }

        ssl = SSL_new(ctx);
        if (ssl == NULL) {
            ERR_print_errors_fp(stderr);
            goto err;
        }

        if (SSL_set_fd(ssl, client) != 1) {
            ERR_print_errors_fp(stderr);
            goto err;
        }

        SSL_set_accept_state(ssl);

        if (SSL_do_handshake(ssl) <= 0) {
            ERR_print_errors_fp(stderr);
            goto err;
        }

        char reply[] = "hello, client\n";

        if (SSL_write(ssl, reply, sizeof(reply)) <= 0) {
            ERR_print_errors_fp(stderr);
            goto err;
        }
err:    
        SSL_shutdown(ssl);
        SSL_free(ssl);
    }
}
