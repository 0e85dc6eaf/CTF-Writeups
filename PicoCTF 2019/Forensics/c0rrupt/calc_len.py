#!/usr/bin/env python3
data = open('mystery3.png','rb').read()
print(hex(len(data.split(b'IDAT')[1])-8))