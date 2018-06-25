# looooong

> I heard you have some "delusions of grandeur" about your typing speed. How fast can you go at shell2017.picoctf.com:51091?

Hints:

> Use the nc command to connect!

> I hear python is a good means (among many) to generate the needed input.

> It might help to have multiple windows open

If it comes to sockets i really like Node.js. With help of [this script](index.js) we can get the flag.

```
>node .
connected
To prove your skills, you must pass this test.
Please give me the 'K' character '619' times, followed by a single '2'.
To make things interesting, you have 30 seconds.
Input:

KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK2
You got it! You're super quick!
Flag: with_some_recognition_and_training_delusions_become_glimpses_cf0c40cbcc7efbd5121222729fff9263
```

The flag is `with_some_recognition_and_training_delusions_become_glimpses_cf0c40cbcc7efbd5121222729fff9263`.