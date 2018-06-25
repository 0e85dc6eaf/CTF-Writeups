#!/usr/bin/python
import hashlib
import sys
def crack(arg):
	your_list = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(){}[];:"\'\\|<,>.?/'
	for i in your_list:
		for j in your_list:
			for k in your_list:
				for l in your_list:
					guess = (i+j+k+l)
					hash = hashlib.sha256(guess.encode('utf-8')).hexdigest()[-6:]
					if hash == arg:
						return guess
						
if __name__ == "__main__":
	print "Cracking \"%s\""%sys.argv[1]
	print crack(sys.argv[1])