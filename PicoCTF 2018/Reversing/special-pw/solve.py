#!/usr/bin/env python3
import struct
import binascii
pw_hash = bytearray(binascii.unhexlify("bd0e501bef9e16d17de5c155c97fcf21c59951d57dc9c59d21d37dc1cdd9958f919997c5f5d12dd5"))

#rol and ror from https://www.falatic.com/index.php/108/python-and-bitwise-rotation
rol = lambda val, r_bits, max_bits: \
    (val << r_bits%max_bits) & (2**max_bits-1) | \
    ((val & (2**max_bits-1)) >> (max_bits-(r_bits%max_bits)))
ror = lambda val, r_bits, max_bits: \
    ((val & (2**max_bits-1)) >> r_bits%max_bits) | \
    (val << (max_bits-(r_bits%max_bits)) & (2**max_bits-1))

def decrypt_pw(pw):
	for i in range(len(pw)-4,-1,-1):
		pw[i:i+4] = struct.pack("<I",ror(struct.unpack("<I",pw[i:i+4])[0],10,32))
		pw[i:i+2] = struct.pack("<H",rol(struct.unpack("<H",pw[i:i+2])[0],15,16))
		pw[i]^=0x66
	return bytes(pw)

print(decrypt_pw(pw_hash).decode("utf-8"))