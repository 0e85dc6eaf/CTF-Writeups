#!python2
import md5
seed = "7349" #your user ID
hashc = seed
prevhash = ""
while True:
	hashc = md5.new(hashc).hexdigest()
	if hashc == "f21f38e0bce0ec1711aca5f7d3beed95":#your next hash
		print prevhash
		quit()
	prevhash = hashc