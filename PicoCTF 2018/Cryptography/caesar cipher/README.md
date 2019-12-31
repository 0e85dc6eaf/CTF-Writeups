# caesar cipher 1

You can use [this website](https://www.dcode.fr/caesar-cipher) to decrypt the cipher for you.

Ciphertext: `grpqxdllaliazxbpxozfmebotlvlicmr`

Key: `23` (you can check all possible keys with this website)

Flag: `picoCTF{justagoodoldcaesarcipherwoyolfpu}`

# caesar cipher 2

This challenge is just an extended version of previous one - it can encode any byte, not just letters.

We can solve it using simple python script.

```py
cipher = "d]Wc7H:oW5YgUFS7]D\9fGS^iGHSUF9bHSg9WIf9q"
for i in range(0,256):
	p = ''
	for c in cipher:
		p+=chr((ord(c)+i)%256)
	if p.startswith("picoCTF"):
		print("%d: %s"%(i,p))
```

Key: `12`

Flag: `picoCTF{cAesaR_CiPhErS_juST_aREnT_sEcUrE}`