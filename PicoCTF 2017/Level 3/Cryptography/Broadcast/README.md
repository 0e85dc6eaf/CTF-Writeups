# Broadcast

> You stumbled upon a group Message. Can you figure out what they were sending? The string sent is ascii encoded as a hex number (submit the ascii string as the flag)

Hints:

> The same message, with a small exponent, is being encrypted with several different n values

We can use Chinese Remainder Theorem to compute the message. 
[Here](https://crypto.stackexchange.com/a/6715) there's a good explanation of how to calculate it.
In the Internet there are many useful pieces of code we can use to deal with mathematical problems.
[Final script](main.py)

```
>python main.py
broadcast_with_small_e_is_killer_40332300191
```

The flag is `broadcast_with_small_e_is_killer_40332300191`.