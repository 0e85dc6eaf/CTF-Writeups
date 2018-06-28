# OCR is cool!

> https://ctftime.org/writeup/10323

In this challenge we are given gmail screenshot. And its content is encrypted with caesar cipher.
To convert image to text we can use any OCR tool (I used this website - https://onlineocr.net/).
For better result we can cut the [image](data.png). Now we need to decrypt it. We don't know the key, but there are only 25 possible rotations, so we can try them all.
[This website](https://www.mobilefish.com/services/rot13/rot13.php) allows us to try all keys at once. We can see that ROT-7 looks like valid english text and there's also our flag.
[decrypted](rot7.txt)

Flag: `CTF{caesarcipherisasubstitutioncipher}`