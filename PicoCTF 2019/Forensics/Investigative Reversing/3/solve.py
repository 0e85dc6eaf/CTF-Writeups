#!/usr/bin/env python3
f = open('encoded.bmp','rb').read()
flag = b""
i = 723
while len(flag)<8*50:
	for _ in range(8):
		flag += bytes([f[i]])
		i+=1
	i+=1
binflag = ""
for c in flag:
	if (c&1) == 1:
		binflag += "1"
	else:
		binflag += "0"
flag = ""
for i in range(0,len(binflag),8):
	flag += chr(int(binflag[i:i+8][::-1],2))
print(flag)