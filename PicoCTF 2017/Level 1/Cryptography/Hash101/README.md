# Hash101

> Prove your knowledge of hashes and claim a flag as your prize! Connect to the service at shell2017.picoctf.com:51461

Hints:

> All concepts required to complete this challenge, including simple modular math, are quickly found by googling :)

Before starting this problem it's good to open some useful websites in your browser.

http://www.asciitohex.com/

http://www.binaryhexconverter.com/hex-to-decimal-converter

http://md5online.org/

OK, let's connect to the server now.

```
>ncat shell2017.picoctf.com 51461

Welcome to Hashes 101!

There are 4 Levels. Complete all and receive a prize!


-------- LEVEL 1: Text = just 1's and 0's --------
All text can be represented by numbers. To see how different letters translate to numbers, go to http://www.asciitable.com/

TO UNLOCK NEXT LEVEL, give me the ASCII representation of 0111011101101111011100100110110001100100

>world
------ LEVEL 2: Numbers can be base ANYTHING -----
Numbers can be represented many ways. A popular way to represent computer data is in base 16 or 'hex' since it lines up with bytes very well (2 hex characters = 8 binary bits). Other formats include base64, binary, and just regular base10 (decimal)! In a way, that ascii chart represents a system where all text can be seen as "base128" (not including the Extended ASCII codes)

TO UNLOCK NEXT LEVEL, give me the text you just decoded, world, as its hex equivalent, and then the decimal equivalent of that hex number ("foo" -> 666f6f -> 6713199)

hex>776f726c64
Good job! 776f726c64 to ASCII -> world is world
Now decimal
dec>512970878052
Good job! 512970878052 to Hex -> 776f726c64 to ASCII -> world is world
Correct! Completed level 2

----------- LEVEL 3: Hashing Function ------------
A Hashing Function intakes any data of any size and irreversibly transforms it to a fixed length number. For example, a simple Hashing Function could be to add up the sum of all the values of all the bytes in the data and get the remainder after dividing by 16 (modulus 16)

TO UNLOCK NEXT LEVEL, give me a string that will result in a 6 after being transformed with the mentioned example hashing function

>F
Correct! Completed level 3

--------------- LEVEL 4: Real Hash ---------------
A real Hashing Function is used for many things. This can include checking to ensure a file has not been changed (its hash value would change if any part of it is changed). An important use of hashes is for storing passwords because a Hashing Function cannot be reversed to find the initial data. Therefore if someone steals the hashes, they must try many different inputs to see if they can "crack" it to find what password yields the same hash. Normally, this is too much work (if the password is long enough). But many times, people's passwords are easy to guess... Brute forcing this hash yourself is not a good idea, but there is a strong possibility that, if the password is weak, this hash has been cracked by someone before. Try looking for websites that have stored already cracked hashes.

TO CLAIM YOUR PRIZE, give me the string password that will result in this MD5 hash (MD5, like most hashes, are represented as hex digits):
d63d5efad4a59c06228d0596a89e2a34

>3mb0x
Correct! Completed level 4
You completed all 4 levels! Here is your prize: 905ac43a6c6aecc74d3f7190b1accecf
```


The flag is `905ac43a6c6aecc74d3f7190b1accecf`.