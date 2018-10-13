# learn gdb

> Using a debugging tool will be extremely useful on your missions. Can you run this program in gdb and find the flag? You can find the file in /problems/learn-gdb_1_a2decdea3e89bfcdcbd9de1a67ceed0e on the shell server. 

Hints:

> Try setting breakpoints in gdb

> Try and find a point in the program after the flag has been read into memory to break on

> Where is the flag being written in memory?

I have gdb peda already installed on my machine so it's much more comfortable to debug applications, but it can be done without peda too.

```
$ gdb ./run
gdb-peda$ break *main
Breakpoint 1 at 0x4008c9
gdb-peda$ r
Breakpoint 1, 0x00000000004008c9 in main ()
```

If we disassemble main function (gdb peda does it for us), we can see `decrypt_flag` function. 
Let's set another breakpoint there.

```
gdb-peda$ break *decrypt_flag
Breakpoint 2 at 0x400786
gdb-peda$ c
Breakpoint 2, 0x0000000000400786 in decrypt_flag ()
```

We can now use `ni` to execute program instruction by instruction (without entering functions).
The function calls malloc and seems to write results there. We can delete breakpoint 2 (we don't want to step throught this long loop) and run the program once again.
This time we set breakpoint just after decrypt_flag call.

We can check heap location with `info proc mappings`.
```
            0x602000           0x623000    0x21000        0x0 [heap]
```
Our flag is 0x10 bytes after start address of heap. We can print it with
```
$ x/s 0x602010
0x602010:       "picoCTF{gDb_iS_sUp3r_u53fuL_f3f39814}"
```

Flag is `picoCTF{gDb_iS_sUp3r_u53fuL_f3f39814}`.