# computeAES

> You found this clue laying around. Can you decrypt it?

Hints:

> Try online tools or python

Or PHP ;) You must have installed openssl extension for PHP (or mcrypt, but it's decprecated).
We need to decode the key before calling the function (we don't have to decode ciphertext as openssl_decrypt expects base64 string).

```
>php --interactive
Interactive shell

php > $key = base64_decode("/7uAbKC7hfINLcSZE+Y9AA==");
php > $ciphertext = "rvn6zLZS4arY+yWNwZ5YlbLAv/gjwM7gZJnqyQjhRZVCC5jxaBvfkRapPBoyxu4e";
php > echo openssl_decrypt($ciphertext,'aes-128-ecb',$key);
```

Unfortunately, this doesn't work. The reason can be that openssl by default uses PKCS7 padding, which is better option, however some libraries (like mentioned before - mcrypt) use another approach (zero padding) and the text could be encrypted that way. Let's check.

```
php > echo openssl_decrypt($ciphertext,'aes-128-ecb',$key,OPENSSL_ZERO_PADDING);
flag{do_not_let_machines_win_82e02651}__________
```
Now it works.

The flag is `flag{do_not_let_machines_win_82e02651}`.
