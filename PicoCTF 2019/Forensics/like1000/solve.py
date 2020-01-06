#!/usr/bin/env python3
import tarfile
import shutil
import os
shutil.copyfile('original.tar','1000.tar')
for i in range(1000,0,-1):
	tar = tarfile.open("./%d.tar"%(i))
	if i == 1:
		tar.extract('flag.png')
	else:
		tar.extract('%d.tar'%(i-1))
	tar.close()
	os.remove("./%d.tar"%(i))