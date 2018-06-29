#!/usr/bin/env python3
with open('pieces/broken','rb') as file:
	payload = b''
	for i in [8,7,1,5,6,2,3,4]:
		with open('pieces/fragment_%d.dat'%i,'rb') as fragment:
			payload += fragment.read()
			fragment.close()
	content = bytearray(file.read())
	content[content.find(b'X'*807):content.find(b'X'*807)+807] = bytearray(payload)
	with open('fixed','wb') as fixed:
		fixed.write(content)
		fixed.close()
	file.close()