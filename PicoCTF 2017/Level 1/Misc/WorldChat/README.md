# WorldChat

> We think someone is trying to transmit a flag over WorldChat. Unfortunately, there are so many other people talking that we can't really keep track of what is going on! Go see if you can find the messenger at shell2017.picoctf.com:7911. Remember to use Ctrl-C to cut the connection if it overwhelms you!

Hints:

> There are cool command line tools that can filter out lines with specific keywords in them. Check out 'grep'! You can use the '|' character to put all the output into another process or command (like the grep process)

In fact the soultion is given in the hint.

```
<username>@shell-web:~$ nc shell2017.picoctf.com 7911 | grep flagperson                       
22:53:03 flagperson: this is part 1/8 of the flag - 08bc
22:53:03 flagperson: this is part 2/8 of the flag - 0aa6
22:53:05 flagperson: this is part 3/8 of the flag - 4ab9
22:53:20 flagperson: this is part 4/8 of the flag - 7621
22:53:23 flagperson: this is part 5/8 of the flag - e512
22:53:24 flagperson: this is part 6/8 of the flag - d2e4
22:53:26 flagperson: this is part 7/8 of the flag - 6d8b
22:53:26 flagperson: this is part 8/8 of the flag - dab3
```

The flag is `08bc0aa64ab97621e512d2e46d8bdab3`.