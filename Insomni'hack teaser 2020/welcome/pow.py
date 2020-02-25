#!/usr/bin/python3

import base64
import hashlib
import os
import sys

target = sys.argv[1]
i = 0

def pow():
    global i, target
    while True:
        m = hashlib.md5()
        m.update(str(i).encode())
        h = m.hexdigest()
        if h[:6] == target:
            print(i)
            exit(0)
        i += 1

if __name__ == '__main__':
    pow()