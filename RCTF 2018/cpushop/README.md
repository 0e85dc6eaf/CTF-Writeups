# cpushop

We got source of the application running on server and our goal was to buy flag. We had enough money to buy anything else.

When we briefly look at the source we can immediately notice this piece of code
```
payment = 'product=%s&price=%d&timestamp=%d' % (items[n][0], items[n][1], time.time()*1000000)
sign = sha256(signkey+payment).hexdigest()
```
If you didn't know about hash length extension attack, you'd probably struggle a lot with this challenge, but I was lucky and I knew it.
There is a really nice library https://github.com/bwall/HashPump that performs the attack for us. The only thing we need to do is to supply correct arguments to it.
It was also a part of the challenge here. For the attack to work, we must know secret length and here it can be any value from range <8;32>.
Fortunately there is no payment fail limit, so we can just bruteforce it.

[exploit](exploit.py)

Flag: `RCTF{ha5h_l3ngth_ex7ens10n_a77ack_1s_ez}`