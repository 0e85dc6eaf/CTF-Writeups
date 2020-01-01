# quackme

In `.rodata` segment you can see `sekrutBuffer` variable. It's referenced in `doMagic` function that xors it with our input and then compares the result to the greeting message `You have now entered the Duck Web, and you're in for a honk`.

We can xor greeting message with the `sekrutBuffer` to recover the flag.

[script](solve1.py)

[application](main1)

Flag: `picoCTF{qu4ckm3_9bcb819e}`

# quackme up

This application implements simple substitution cipher and we can perform chosen plaintext attack to recover the "S-box".

```
$ qemu-i386 ./main2
We're moving along swimmingly. Is this one too fowl for you?
Enter text to encrypt: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789{}!@#$%^&*()_-+=
Here's your ciphertext: 00 30 20 50 40 70 60 90 80 B0 A0 D0 C0 F0 E0 11 01 31 21 51 41 71 61 91 81 B1 02 32 22 52 42 72 62 92 82 B2 A2 D2 C2 F2 E2 13 03 33 23 53 43 73 63 93 83 B3 15 05 35 25 55 45 75 65 95 85 A1 C1 04 12 24 54 44 F3 74 B4 94 84 E3 C4 A4 C5
Now quack it! : 11 80 20 E0 22 53 72 A1 01 41 55 20 A0 C0 25 E3 20 30 00 45 05 35 40 65 C1
That's all folks.
```

[script](solve2.py)

[application](main2)

Flag: `picoCTF{qu4ckm3_cba512e7}`