# Much Ado About Hacking

> In a lonely file, you find prose written in an interesting style. What is this Shakespearean play? What does it have to say? How could one get it to produce this ending?

Hints:

> Some would say that Shakespearean english is an... esoteric language

> I swear that this play compiles. However, there are different versions of the shakespeare language. If you get errors when you run spl2c on MuchAdoAboutHacking, then you need to use a different version of the language. There is a fixed version of the language here: https://stackoverflow.com/questions/1948372/compiling-and-executing-the-shakespeare-programming-language-translator-spl2c-on

Using spl2c program from hints we can convert our spl file to a bit more readable form.
However for better understanding the program I added some comments explaining library functions.

[C code](src.c)

The algorithm isn't very complicated and [here](decode.php) is the script which decodes the flag.

```
>php decode.php
Its@MidSuMm3rNights3xpl0!t
```


The flag is `Its@MidSuMm3rNights3xpl0!t`.