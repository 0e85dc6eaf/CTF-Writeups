# pipe

> During your adventure, you will likely encounter a situation where you need to process data that you receive over the network rather than through a file. Can you find a way to save the output from this program and search for the flag? Connect with 2018shell1.picoctf.com 48696. 

Hints:

> Remember the flag format is picoCTF{XXXX}
    
> Ever heard of a pipe? No not that kind of pipe... This kind

```
$ nc 2018shell1.picoctf.com 48696 | grep picoCTF
picoCTF{almost_like_mario_f617d1d7}
```

Flag is `picoCTF{almost_like_mario_f617d1d7}`.