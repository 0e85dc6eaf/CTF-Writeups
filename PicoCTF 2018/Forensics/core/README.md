# core

When we open the [print_flag](print_flag) binary in gdb and load the [core dump](core) we can see that the application "crashed" in `print_flag` function. Let's have a look at this function in IDA.

```
; middle part of print_flag function
mov     [ebp+flag_idx], 1337
mov     eax, [ebp+flag_idx]
mov     eax, ds:strs[eax*4] ; load strs[1337] to eax
sub     esp, 8
push    eax
push    offset aYourFlagIsPico ; "your flag is: picoCTF{%s}\n"
call    _printf ; printf("your flag is: picoCTF{%s}",strs[1337])
```

`strs[1337]` must contain a pointer to string (our flag). We can use gdb to read the flag from the core dump.

```
$ gdb ./print_flag ./core
gdb-peda$ x/xw strs+1337
0x804b564 <strs+5348>:  0x080610f0
gdb-peda$ x/s 0x080610f0
0x80610f0:      "c96bd0fa2da5c0853cf12c4f93fce288"
```

Flag: `picoCTF{c96bd0fa2da5c0853cf12c4f93fce288}`