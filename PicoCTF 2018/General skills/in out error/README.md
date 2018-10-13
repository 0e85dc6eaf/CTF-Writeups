# in out error

> Can you utlize stdin, stdout, and stderr to get the flag from this program? You can also find it in /problems/in-out-error_3_9eb10797d687f70cfce62e7c9c2bdea6 on the shell server 

Hints:

> Maybe you can split the stdout and stderr output?

```
$ cd /problems/in-out-error_3_9eb10797d687f70cfce62e7c9c2bdea6
$ echo "Please may I have the flag?" | ./in-out-error >~/out.txt 2>~/err.txt
```

This command will redirect stderr to err.txt in your home directory and stdout to out.txt.
You can then read the files and in err.txt there will be the flag. (note that the program may crash if you run it locally or from another directory)

Flag is `picoCTF{p1p1ng_1S_4_7h1ng_437b5c88}`.