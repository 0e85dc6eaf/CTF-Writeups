#!/usr/bin/env python2
import sys
num = sys.argv[1:]
print("".join([chr(int(x,int(8))) for x in num]))