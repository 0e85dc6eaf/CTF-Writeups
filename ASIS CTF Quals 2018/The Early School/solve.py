#!/usr/bin/env python2
from Crypto.Util.number import *
def decrypt(msg):
	msg = bin(bytes_to_long(msg))[2:]
	dec = [msg[i] + (msg[i+1] if len(msg)-1 > i + 1 else '') for i in range(0, len(msg), 3)]
	return ''.join(dec)

with open('the_early_school/FLAG.enc','r') as flag:
	c = flag.read()
	flag.close()
	while "ASIS{" not in c:
		c = long_to_bytes(int(decrypt(c),2))
	print c