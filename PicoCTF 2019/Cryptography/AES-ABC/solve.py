#!/usr/bin/env python3
from Cryptodome.Util.number import bytes_to_long, long_to_bytes
UMAX = 256**16
def pad(block):
	return b"\x00"*(16-len(block))+block
data = open("body.enc","rb").read()
img = b""
for i in range(16,len(data),16):
	img += pad(long_to_bytes(bytes_to_long(data[i:i+16]) - bytes_to_long(data[i-16:i]) % UMAX))
open("body.ecb.ppm","wb").write(b"P6\n1895 820\n255\n"+img)