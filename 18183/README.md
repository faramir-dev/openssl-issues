Without workaround, `Extesion 18` is not present:


```
/opt/openssl.18183.dbg# LD_LIBRARY_PATH=lib64 bin/openssl s_client -connect 127.0.0.1:24323 -no_tls1_3 -serverinfo 18
Connecting to 127.0.0.1
CONNECTED(00000003)
80629BECFF7E0000:error:0A000438:SSL routines:ssl3_read_bytes:tlsv1 alert internal error:../openssl.18183/ssl/record/rec_layer_s3.c:1584:SSL alert number 80
---
no peer certificate available
---
No client certificate CA names sent
---
SSL handshake has read 7 bytes and written 198 bytes
Verification: OK
---
New, (NONE), Cipher is (NONE)
Secure Renegotiation IS NOT supported
Compression: NONE
Expansion: NONE
No ALPN negotiated
SSL-Session:
    Protocol  : TLSv1.2
    Cipher    : 0000
    Session-ID:
    Session-ID-ctx:
    Master-Key:
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    Start Time: 1652362566
    Timeout   : 7200 (sec)
    Verify return code: 0 (ok)
    Extended master secret: no
---
/opt/openssl.18183.dbg# LD_LIBRARY_PATH=lib64 bin/openssl s_client -connect 127.0.0.1:24323 -serverinfo 18
Connecting to 127.0.0.1
CONNECTED(00000003)
Can't use SSL_get_servername
depth=0 CN=server.example
verify error:num=20:unable to get local issuer certificate
verify return:1
depth=0 CN=server.example
verify error:num=21:unable to verify the first certificate
verify return:1
depth=0 CN=server.example
verify return:1
---
Certificate chain
 0 s:CN=server.example
   i:CN=Root CA
   a:PKEY: rsaEncryption, 2048 (bit); sigalg: RSA-SHA256
   v:NotBefore: Jan 14 22:29:46 2016 GMT; NotAfter: Jan 15 22:29:46 2116 GMT
---
Server certificate
-----BEGIN CERTIFICATE-----
MIIDJTCCAg2gAwIBAgIBAjANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290
IENBMCAXDTE2MDExNDIyMjk0NloYDzIxMTYwMTE1MjIyOTQ2WjAZMRcwFQYDVQQD
DA5zZXJ2ZXIuZXhhbXBsZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB
ANVdYGrf/GHuSKqMEUhDpW22Ul2qmEmxYZI1sfw6BCUMbXn/tNXJ6VwcO+Crs7h9
o95tveDd11q/FEcRQl6mgtBhwX/dE0bmCYUHDvLU/Bpk0gqtIKsga5bwrczEGVNV
3AEdpLPvirRJU12KBRzx3OFEv8XX4ncZV1yXC3XuiENxD8pswbSyUKd3RmxYDxG/
8XYkWq45QrdRZynh0FUwbxfkkeqt+CjCQ2+iZKn7nZiSYkg+6w1PgkqK/z9y7pa1
rqHBmLrvfZB1bf9aUp6r9cB+0IdD24UHBw99OHr90dPuZR3T6jlqhzfuStPgDW71
cKzCvfFu85KVXqnwoWWVk40CAwEAAaN9MHswHQYDVR0OBBYEFMDnhL/oWSczELBS
T1FSLwbWwHrNMB8GA1UdIwQYMBaAFHB/Lq6DaFmYBCMqzes+F80k3QFJMAkGA1Ud
EwQCMAAwEwYDVR0lBAwwCgYIKwYBBQUHAwEwGQYDVR0RBBIwEIIOc2VydmVyLmV4
YW1wbGUwDQYJKoZIhvcNAQELBQADggEBAHvTBEN1ig8RrsT716Ginv4gGNX0LzGI
RrZ1jO7lm5emuaPNYJpGw0iX5Zdo91qGNXPZaZ75X3S55pQTActq3OPEBOll2pyk
iyjz+Zp/v5cfRZLlBbFW5gv2R94eibYr4U3fSn4B0yPcl4xH/l/HzJhGDsSDW8qK
8VIJvmvsPwmL0JMCv+FR59F+NFYZdND/KCXet59WUpF9ICmFCoBEX3EyJXEPwhbi
X2sdPzJbCjx0HLli8e0HUKNttLQxCsBTRGo6iISLLamwN47mGDa9miBADwGSiz2q
YeeuLO02zToHhnQ6KbPXOrQAqcL1kngO4g+j/ru+4AZThFkdkGnltvk=
-----END CERTIFICATE-----
subject=CN=server.example
issuer=CN=Root CA
---
No client certificate CA names sent
Peer signing digest: SHA256
Peer signature type: RSA-PSS
Server Temp Key: X25519, 253 bits
---
SSL handshake has read 1365 bytes and written 387 bytes
Verification error: unable to verify the first certificate
---
New, TLSv1.3, Cipher is TLS_AES_256_GCM_SHA384
Server public key is 2048 bit
This TLS version forbids renegotiation.
Compression: NONE
Expansion: NONE
No ALPN negotiated
Early data was not sent
Verify return code: 21 (unable to verify the first certificate)
---
---
Post-Handshake New Session Ticket arrived:
SSL-Session:
    Protocol  : TLSv1.3
    Cipher    : TLS_AES_256_GCM_SHA384
    Session-ID: A4A2B9263BEDAB9F2278F4E4CD3D123D01D28DED8A74FDF8AFF26358B93657EB
    Session-ID-ctx:
    Resumption PSK: A1EC4980E5AF391D78615203269139FFAACA5BCD43E0561FC583153D50496DE50784D8393F10833F49A84588536367D9
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 7200 (seconds)
    TLS session ticket:
    0000 - c2 52 35 8f 4e c2 51 93-ae 57 f5 35 8d 3d 8b 51   .R5.N.Q..W.5.=.Q
    0010 - 8d 69 5c e6 cf 03 bc bc-fb 2a 96 d2 ce 2d 9d 99   .i\......*...-..
    0020 - 5a 4e 59 f2 01 69 25 70-a6 63 9e c4 de 41 c6 58   ZNY..i%p.c...A.X
    0030 - 1d 05 a3 de 00 f6 1f b2-2d c7 a1 e4 29 0a bb 62   ........-...)..b
    0040 - 27 65 9c 43 e0 82 13 fc-db 1c a7 04 87 ee f2 d8   'e.C............
    0050 - 97 38 5f d2 95 2f af e2-2c 67 8c 2a f2 ab 89 07   .8_../..,g.*....
    0060 - 90 54 d3 95 41 df b9 01-86 45 5a 90 35 1b 99 2e   .T..A....EZ.5...
    0070 - c8 54 a7 c7 92 27 a1 50-23 d2 5b ea 2b b2 f1 c8   .T...'.P#.[.+...
    0080 - 6d c9 7e e9 c3 8e c6 8a-04 74 d4 f0 6a 59 fd 90   m.~......t..jY..
    0090 - ad 8b 7e b1 27 b0 39 9c-1b 0a c2 d3 12 ff 12 eb   ..~.'.9.........
    00a0 - 5d ad c5 d7 3c 3f e1 44-3c 0d 39 f2 b7 51 0d 6c   ]...<?.D<.9..Q.l
    00b0 - 16 97 cc ba f2 f0 64 86-91 ca d5 94 87 ea 17 d4   ......d.........
    00c0 - 79 73 73 12 e3 9e e9 ec-00 99 43 a6 aa 70 ab 81   yss.......C..p..

    Start Time: 1652362569
    Timeout   : 7200 (sec)
    Verify return code: 21 (unable to verify the first certificate)
    Extended master secret: no
    Max Early Data: 0
---
read R BLOCK
---
Post-Handshake New Session Ticket arrived:
SSL-Session:
    Protocol  : TLSv1.3
    Cipher    : TLS_AES_256_GCM_SHA384
    Session-ID: 7937097A51D26B8E2C4364BEC9A1331A97DB6A2C7574A6F68D2F59D7800C0E3F
    Session-ID-ctx:
    Resumption PSK: B53B564A189334CF2A0AE3B464E608CDFD4844D5B938F8F7E8DBEB5C745AA68E9D3C72F270C6DD19C5E797F5934AB97A
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 7200 (seconds)
    TLS session ticket:
    0000 - c2 52 35 8f 4e c2 51 93-ae 57 f5 35 8d 3d 8b 51   .R5.N.Q..W.5.=.Q
    0010 - 26 df 09 b9 81 dc 1a c0-04 59 b3 fa 9e 41 2f 76   &........Y...A/v
    0020 - f5 c7 f9 ec 2a af e6 f2-03 82 dc d5 f5 84 50 93   ....*.........P.
    0030 - 1e f1 49 15 5e 5c 52 d1-ba 5d f9 a9 6c e4 76 9e   ..I.^\R..]..l.v.
    0040 - f8 91 86 6a 79 c4 72 fa-71 48 6e c3 10 93 4d fb   ...jy.r.qHn...M.
    0050 - 07 aa 79 8d c6 fd 30 a3-da d0 3a 57 77 2c d9 86   ..y...0...:Ww,..
    0060 - 96 0c 92 8e 86 41 ce 2c-4c 42 19 9c 6e af b1 ee   .....A.,LB..n...
    0070 - d9 bb b6 a3 b7 20 50 34-47 cb d4 85 84 26 e4 f9   ..... P4G....&..
    0080 - f0 a5 7b d6 8a 5e 55 f4-4e 0d a7 0a 73 73 10 03   ..{..^U.N...ss..
    0090 - 88 d5 14 7e 94 92 51 b7-92 ab 8e c0 9a 1a 62 f4   ...~..Q.......b.
    00a0 - dc 5e eb fd d4 ab 1f 2f-4b 38 44 35 98 aa d5 98   .^...../K8D5....
    00b0 - 4d 96 23 22 48 37 b5 27-af 20 97 47 0d 64 63 f0   M.#"H7.'. .G.dc.
    00c0 - 15 75 78 84 d1 ef 48 0e-50 c0 72 30 9c ea 46 5d   .ux...H.P.r0..F]

    Start Time: 1652362569
    Timeout   : 7200 (sec)
    Verify return code: 21 (unable to verify the first certificate)
    Extended master secret: no
    Max Early Data: 0
---
read R BLOCK
hello, client
closed
```

------------------------------

If workaround is present, then `EXTENSION 18` is present if **TLS 1.2** is used.

```
# LD_LIBRARY_PATH=lib64 bin/openssl s_client -connect 127.0.0.1:24323 -no_tls1_3 -serverinfo 18
Connecting to 127.0.0.1
CONNECTED(00000003)
-----BEGIN SERVERINFO FOR EXTENSION 18-----
ABIAAwQFBg==
-----END SERVERINFO FOR EXTENSION 18-----
Can't use SSL_get_servername
depth=0 CN=server.example
verify error:num=20:unable to get local issuer certificate
verify return:1
depth=0 CN=server.example
verify error:num=21:unable to verify the first certificate
verify return:1
depth=0 CN=server.example
verify return:1
---
Certificate chain
 0 s:CN=server.example
   i:CN=Root CA
   a:PKEY: rsaEncryption, 2048 (bit); sigalg: RSA-SHA256
   v:NotBefore: Jan 14 22:29:46 2016 GMT; NotAfter: Jan 15 22:29:46 2116 GMT
---
Server certificate
-----BEGIN CERTIFICATE-----
MIIDJTCCAg2gAwIBAgIBAjANBgkqhkiG9w0BAQsFADASMRAwDgYDVQQDDAdSb290
IENBMCAXDTE2MDExNDIyMjk0NloYDzIxMTYwMTE1MjIyOTQ2WjAZMRcwFQYDVQQD
DA5zZXJ2ZXIuZXhhbXBsZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB
ANVdYGrf/GHuSKqMEUhDpW22Ul2qmEmxYZI1sfw6BCUMbXn/tNXJ6VwcO+Crs7h9
o95tveDd11q/FEcRQl6mgtBhwX/dE0bmCYUHDvLU/Bpk0gqtIKsga5bwrczEGVNV
3AEdpLPvirRJU12KBRzx3OFEv8XX4ncZV1yXC3XuiENxD8pswbSyUKd3RmxYDxG/
8XYkWq45QrdRZynh0FUwbxfkkeqt+CjCQ2+iZKn7nZiSYkg+6w1PgkqK/z9y7pa1
rqHBmLrvfZB1bf9aUp6r9cB+0IdD24UHBw99OHr90dPuZR3T6jlqhzfuStPgDW71
cKzCvfFu85KVXqnwoWWVk40CAwEAAaN9MHswHQYDVR0OBBYEFMDnhL/oWSczELBS
T1FSLwbWwHrNMB8GA1UdIwQYMBaAFHB/Lq6DaFmYBCMqzes+F80k3QFJMAkGA1Ud
EwQCMAAwEwYDVR0lBAwwCgYIKwYBBQUHAwEwGQYDVR0RBBIwEIIOc2VydmVyLmV4
YW1wbGUwDQYJKoZIhvcNAQELBQADggEBAHvTBEN1ig8RrsT716Ginv4gGNX0LzGI
RrZ1jO7lm5emuaPNYJpGw0iX5Zdo91qGNXPZaZ75X3S55pQTActq3OPEBOll2pyk
iyjz+Zp/v5cfRZLlBbFW5gv2R94eibYr4U3fSn4B0yPcl4xH/l/HzJhGDsSDW8qK
8VIJvmvsPwmL0JMCv+FR59F+NFYZdND/KCXet59WUpF9ICmFCoBEX3EyJXEPwhbi
X2sdPzJbCjx0HLli8e0HUKNttLQxCsBTRGo6iISLLamwN47mGDa9miBADwGSiz2q
YeeuLO02zToHhnQ6KbPXOrQAqcL1kngO4g+j/ru+4AZThFkdkGnltvk=
-----END CERTIFICATE-----
subject=CN=server.example
issuer=CN=Root CA
---
No client certificate CA names sent
Peer signing digest: SHA256
Peer signature type: RSA-PSS
Server Temp Key: X25519, 253 bits
---
SSL handshake has read 1441 bytes and written 291 bytes
Verification error: unable to verify the first certificate
---
New, TLSv1.2, Cipher is ECDHE-RSA-AES256-GCM-SHA384
Server public key is 2048 bit
Secure Renegotiation IS supported
Compression: NONE
Expansion: NONE
No ALPN negotiated
SSL-Session:
    Protocol  : TLSv1.2
    Cipher    : ECDHE-RSA-AES256-GCM-SHA384
    Session-ID: 0E7408A2EECEB4FF0A244930472F0CC5F06360AA384E55F6DFB87EC244C4D006
    Session-ID-ctx:
    Master-Key: 94B4EF96515A2F21E7322A2DCF7C6B2132760FBCE6689C8C95CE311B3E4478FF789AF4D28CA3AD283AE6FD2F66742678
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 7200 (seconds)
    TLS session ticket:
    0000 - 18 3e cf 04 c7 2a 9f b7-0b b5 a5 59 da 54 d9 ae   .>...*.....Y.T..
    0010 - cd f2 ff 1c 43 bb 18 f0-82 21 c6 c7 55 61 05 3e   ....C....!..Ua.>
    0020 - 53 d2 86 e0 67 a7 40 46-cf 7a 31 33 49 82 84 23   S...g.@F.z13I..#
    0030 - 29 32 3e 1f 0d 0b 10 8a-05 fa 50 7a de 9b d4 ba   )2>.......Pz....
    0040 - 52 1c 69 fe 22 82 e2 a7-ae 78 d6 a1 0a a6 8d 96   R.i."....x......
    0050 - 3d dd 1c 8a ff 7c 89 dd-55 3c cf c7 15 2d 26 ee   =....|..U<...-&.
    0060 - 9f 96 67 da 5c 6e 35 5f-c6 f4 a8 4d c0 bb ff a3   ..g.\n5_...M....
    0070 - 84 c3 ca 35 6d 77 2e 6c-26 c4 71 42 b6 c5 b5 a0   ...5mw.l&.qB....
    0080 - e6 ec bd 0e 4a 41 f6 a6-00 5b 3e 73 cc 70 8b 5e   ....JA...[>s.p.^
    0090 - e0 35 0c 72 a9 aa 23 7e-ae e2 16 54 13 4a a2 42   .5.r..#~...T.J.B

    Start Time: 1652273902
    Timeout   : 7200 (sec)
    Verify return code: 21 (unable to verify the first certificate)
    Extended master secret: yes
---
hello, client
closed
```
