#!/usr/bin/env python3
import struct
import sys
LOCAL_SIG = 0x04034b50
CENTRAL_DIR_SIG = 0x02014b50
END_OF_CENTRAL_DIR = 0x06054b50
with open('b1g_mac.zip','rb') as f:
	data = f.read()
it = 0
def rd():
	global it
	global data
	it+=4
	return struct.unpack("<I",data[it-4:it])[0]
def rw():
	global it
	global data
	it+=2
	return struct.unpack("<H",data[it-2:it])[0]
def rn(x):
	global it
	global data
	it+=x
	return data[it-x:it]
def parseLFH():
	versionToExtract = rw()
	generalPurposeBit = rw()
	compressionMethod = rw()
	fileLastModTime = rw()
	fileLastModDate = rw()
	crc = rd()
	compSz = rd()
	uncompSz = rd()
	fnameLen = rw()
	extraFieldLen = rw()
	fname = rn(fnameLen)
	extraField = rn(extraFieldLen)
	return compSz,fname.decode('utf-8')
def parseCDFH():
	versionMadeBy = rw()
	versionToExtract = rw()
	generalPurposeBit = rw()
	compressionMethod = rw()
	fileLastModTime = rw()
	fileLastModDate = rw()
	crc = rd()
	compSz = rd()
	uncompSz = rd()
	fnameLen = rw()
	extraFieldLen = rw()
	commentLen = rw()
	disk = rw()
	internalFileAttr = rw()
	externalFileAttr = rd()
	lfhOffset = rd()
	fname = rn(fnameLen)
	extraField = rn(extraFieldLen)
	comment = rn(commentLen)
	return fname.decode('utf-8'),extraField
def parseEOCD():
	diskNum = rw()
	startDisk = rw()
	recordsOnThisDisk = rw()
	totalRecords = rw()
	szCD = rd()
	offsetStartCD = rd()
	commentLen = rw()
	comment = rn(commentLen)
flag = ""
while it < len(data):
	sig = rd()
	if sig == LOCAL_SIG:
		sz,file = parseLFH()
		it+=sz
	elif sig == CENTRAL_DIR_SIG:
		file,extraField = parseCDFH()
		if file.endswith("Copy.bmp"):
			flag += extraField[12:14][::-1].decode('utf-8')
	elif sig == END_OF_CENTRAL_DIR:
		parseEOCD()
	else:
		print("Unexpected bytes %x at position %d"%(sig,it))
		sys.exit(1)
print(flag)