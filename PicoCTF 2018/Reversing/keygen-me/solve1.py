#!/usr/bin/env python3
import os
import sys
import string
def bruteForceChecksum(code):
	for c in string.digits + string.ascii_uppercase:
		if "Product Activated Successfully" in os.popen("qemu-i386 ./activate %s%s"%(code,c)).read():
			return code+c
print(bruteForceChecksum(sys.argv[1]))