#!/usr/bin/env python3
import socket
import time
import collections

def recvuntil(sock,text):
	text = text.encode("utf-8")
	result = sock.recv(1024)
	while not text in result:
		result += sock.recv(1024)
	return result.decode("utf-8")

def send(sock,text):
	text = (text+"\n").encode('utf-8')
	sock.send(text)

def main():
	signatures = collections.OrderedDict()
	for x in open("primes.txt").read().splitlines():
		signatures[int(x)]=0
	primesCount = len(signatures)
	e = 65537
	N = 0
	challenge = 0
	signature = 1
	timeout = time.time() + 57
	maxPrime = 0

	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	server_address = ("shell2017.picoctf.com", 27525)
	sock.connect(server_address)
	text = recvuntil(sock,"Enter a number to sign (-1 to stop):")
	N = int(text.splitlines()[1].split(':')[1])
	
	for prime in signatures:
		if time.time() >= timeout:
			break
		send(sock,str(prime))
		text = recvuntil(sock,"Enter a number to sign (-1 to stop):")
		signatures[prime]=int(text.splitlines()[0].split(':')[1])
		maxPrime = prime

	send(sock,"-1")
	text = recvuntil(sock,"Enter the signature of the challenge:")
	challenge = int(text.splitlines()[0].split(':')[1])

	for prime in signatures:
		if challenge == 1 or prime > maxPrime:
			break
		while challenge % prime == 0:
			challenge //= prime
			signature = (signature * signatures[prime])%N

	if challenge == 1:
		send(sock,str(signature))
		print(sock.recv(1024).decode("utf-8"))
		print(sock.recv(1024).decode("utf-8"))
		return True
	print("Challenge failed. Retrying")

while True:
	if main()==True:
		break