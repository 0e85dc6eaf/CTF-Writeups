#!/usr/bin/env python3
key = "SOLVECRYPTO"
message = "UFJKXQZQUNB"
flag = "picoCTF{"
for ch1,ch2 in zip(key,message):
	flag += chr((ord(ch2)-ord(ch1))%26+65)
flag += "}"
print(flag)