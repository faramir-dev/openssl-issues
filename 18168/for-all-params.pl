#!/usr/bin/env perl

use strict;
use warnings;

my@params=qw(no-shared no-module -DPEDANTIC enable-tls1_3 enable-weak-ssl-ciphers enable-rc5 enable-md2 enable-ssl3 enable-ssl3-method enable-nextprotoneg enable-ec_nistp_64_gcc_128);

while (@params > 0) {
	print "X:params: @params;";
	system 'make distclean >/dev/null 2>/dev/null';
	system '../openssl.18168/Configure >/dev/null 2>/dev/null --debug ' . join(' ', @params);
	system 'make -j16 >/dev/null 2>/dev/null';
	system 'LD_LIBRARY_PATH=. apps/openssl rsa -in poc -out /tmp/foo';
	last if ($? >> 8) == 0;
	pop @params;
}

print "Y:params: @params;";
