# what base is this?

> To be successful on your mission, you must be able read data represented in different ways, such as hexadecimal or binary. Can you get the flag from this program to prove you are ready? Connect with nc 2018shell1.picoctf.com 64706. 

Hints:

> I hear python is a good means (among many) to convert things.

> It might help to have multiple windows open

For hex and bin to ASCII I used [this website](https://www.asciitohex.com/).

Last question was in oct, so I wrote [simple script](toascii.py) for it.

```
$ ./toascii.py 143 141 153 145
cake
```

```
$ nc 2018shell1.picoctf.com 64706
We are going to start at the very beginning and make sure you understand how data is stored.
cake
Please give me the 01100011 01100001 01101011 01100101 as a word.
To make things interesting, you have 30 seconds.
Input:
cake
Please give me the 706c7567 as a word.
Input:
plug
Please give me the  143 141 153 145 as a word.
Input:
cake
You got it! You're super quick!
Flag: picoCTF{delusions_about_finding_values_5b21aa05}
```

Flag is `picoCTF{delusions_about_finding_values_5b21aa05}`.