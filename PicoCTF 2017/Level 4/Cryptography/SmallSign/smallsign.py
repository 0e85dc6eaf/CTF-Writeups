#!/usr/bin/python -u

from Crypto.PublicKey import RSA
import random
import signal

key = RSA.generate(2048)
flag = open("./flag").read()

print "You have 60 seconds to forge a signature! Go!"
# In 60 seconds, deliver a SIGALRM and terminate
signal.alarm(60)

print "N:", key.n
print "e:", key.e

while True:
    m = int(raw_input("Enter a number to sign (-1 to stop): "))
    if m == -1:
        break
    sig = key.sign(m, None)
    print "Signature:", str(sig[0])

challenge = random.randint(0, 2**32)
print "Challenge:", challenge
s = int(raw_input("Enter the signature of the challenge: "))
if key.verify(challenge, (s, None)):
    print "Congrats! Here is the flag:", flag
else:
    print "Nope, that's wrong!"
