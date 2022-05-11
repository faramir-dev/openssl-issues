.PHONY: build
build:
	gcc -I/opt/openssl.18183.dbg/include -c server.c
	gcc -I/opt/openssl.18183.dbg/include -L/opt/openssl.18183.dbg/lib64 -o server server.o -lcrypto -lssl

.PHONY: run
run: build
	LD_LIBRARY_PATH=/opt/openssl.18183.dbg/lib64 ./server

.PHONY: clean
clean:
	rm -fv server.o server
