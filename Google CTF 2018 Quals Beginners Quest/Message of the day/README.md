# Message of the day

> https://ctftime.org/writeup/10477

We got only binary this time and `file` says it's not stripped elf64, so it contains all the symbols.
```
$ file motd
motd: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=48025612558d041aa5521523e5e98194320d1fa4, not stripped
```
When open the file in gdb and run `checksec` (it's not built-in, but I use gdb peda)
```
gdb-peda$ checksec
CANARY    : disabled
FORTIFY   : disabled
NX        : ENABLED
PIE       : disabled
RELRO     : Partial
```
we can see that the only thing we can't do is to execute code on the stack, but hopefully it won't be necessary.
Now let's look at the program in IDA. We have 5 options `get MOTD`, `set MOTD`, `get admin MOTD`, `set admin MOTD` and `quit`.
The only one we can't execute is `get admin MOTD`, so probably it's where we want to get. Our identity is verified with getuid() function, which basically returns our user id.
If it returns 0, it means that we are root and it will read the flag for us. We can connect to the server to see if someone accidentally run the application as root, but it's not the case in this challenge.
Let's look at `set motd` function. We can see that the buffer is on stack and it uses gets to read the input, but we can type in as many characters as we want and the buffer is only 0x100 bytes long.
So we can try to set 0x108 "A"s (there is also old rbp on stack before the return address) followed by the read_flag address as our motd and it should return to that function.
[exploit](exploit.py)

Flag: `CTF{m07d_1s_r3t_2_r34d_fl4g}`
