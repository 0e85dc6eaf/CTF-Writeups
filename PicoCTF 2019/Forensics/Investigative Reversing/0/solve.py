#!/usr/bin/env python3
flag = bytearray(open('./mystery.png','rb').read()[-26:])
for i in range(6,15):
	flag[i]-=5
flag[15]+=3
print(flag.decode('utf-8'))