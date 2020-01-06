#!/usr/bin/env python3
files = ["Item01_cp.bmp","Item02_cp.bmp","Item03_cp.bmp","Item04_cp.bmp","Item05_cp.bmp"][::-1]
flag_parts = [b"",b"",b"",b"",b""]
for idx in range(5):
	file = files[idx]
	f = open(file,'rb').read()
	i = 2019
	while len(flag_parts[idx])<8*10:
		for _ in range(8):
			flag_parts[idx] += bytes([f[i]])
			i+=1
		i+=4
binflag = ""
for c in b"".join(flag_parts):
	if (c&1) == 1:
		binflag += "1"
	else:
		binflag += "0"
flag = ""
for i in range(0,len(binflag),8):
	flag += chr(int(binflag[i:i+8][::-1],2))
print(flag)