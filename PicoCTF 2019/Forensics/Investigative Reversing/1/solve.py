#!/usr/bin/env python3
d1 = bytearray(open('./mystery.png','rb').read()[-16:])
d2 = bytearray(open('./mystery2.png','rb').read()[-2:])
d3 = bytearray(open('./mystery3.png','rb').read()[-8:])
flag = chr(d2[0]-21) + d3[:2].decode('utf-8') + chr(d2[1]-4) + chr(d1[0]) + chr(d3[2]) + d1[1:5].decode('utf-8') + d3[3:].decode('utf-8') + d1[5:].decode('utf-8')
print(flag)