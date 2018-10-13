# grep 1

> Can you find the flag in file? This would be really obnoxious to look through by hand, see if you can find a faster way. You can also find the file in /problems/grep-1_3_8d9cff3d178c231ab735dfef3267a1c2 on the shell server. 

Hints:

> grep tutorial

```
$ cat file | grep picoCTF
picoCTF{grep_and_you_will_find_cdf2e7c2}
```

Flag is `picoCTF{grep_and_you_will_find_cdf2e7c2}`.

======

# grep 2

> This one is a little bit harder. Can you find the flag in /problems/grep-2_3_826f886f547acb8a9c3fccb030e8168d/files on the shell server? Remember, grep is your friend. 

Hints:

> grep tutorial

```
$ grep -r -H "picoCTF" /problems/grep-2_3_826f886f547acb8a9c3fccb030e8168d/files
/problems/grep-2_3_826f886f547acb8a9c3fccb030e8168d/files/files3/file6:picoCTF{grep_r_and_you_will_find_556620f7}
```

Flag is `picoCTF{grep_r_and_you_will_find_556620f7}`.