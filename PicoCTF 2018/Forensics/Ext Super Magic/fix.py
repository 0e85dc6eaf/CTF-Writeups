#!/usr/bin/env python3
data = open("ext-super-magic.img","rb").read()
open("fixed.img","wb").write(data[:1024+56] + b"\x53\xef" + data[1024+56+2:])