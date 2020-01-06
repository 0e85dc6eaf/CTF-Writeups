#!/usr/bin/env python3
f = open('encoded.bmp','rb').read()
flag = f[2000:2400]
binflag = ""
for c in flag:
	if (c&1) == 1:
		binflag += "1"
	else:
		binflag += "0"
flag = ""
for i in range(0,len(binflag),8):
	flag += chr(int(binflag[i:i+8][::-1],2)+5)
print(flag)