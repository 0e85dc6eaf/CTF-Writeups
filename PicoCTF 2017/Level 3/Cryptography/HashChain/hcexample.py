import md5 #Must be run in python 2.7.x

#code used to calculate successive hashes in a hashchain. 
seed = "seedhash"

#this will find the 5th hash in the hashchain. This would be the correct response if prompted with the 6th hash in the hashchain
hashc = seed
for _ in xrange(5):
  hashc = md5.new(hashc).hexdigest()
 
print hashc