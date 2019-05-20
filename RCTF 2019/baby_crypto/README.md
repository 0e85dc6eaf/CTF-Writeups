# baby_crypto

In this challenge we have to forge a cookie with admin flag set to 1.

First thing we have to notice is that only the last occurence of any key in the cookie counts.

```python
info = {}
for _ in cookie.split(b";"):
	k, v = _.split(b":")
	info[k] = v
```

Thanks to this, if we can append `;admin:1` to the cookie, we'll get the flag.

To encrypt arbitrary data we can use padding oracle attack.

The only problem is that we must append hash to the cookie and we can't easily calculate it without knowing the salt.

Here comes hash length extension attack. We can use it to update the hash without need to guess the salt.

Final cookie (with AES padding) looks like this:
```
admin:0;username:admin;password:admin\x80\x00\x00\x00\x00\x00\x00\x00\x00\x01\xa8;admin:1\x08\x08\x08\x08\x08\x08\x08\x08
```

Now we only need to encrypt it with padding oracle attack and update the hash.

[Final script](solve.py)

Flag is `RCTF{f2c519ea-567b-41d1-9db8-033f058b4e3e}`