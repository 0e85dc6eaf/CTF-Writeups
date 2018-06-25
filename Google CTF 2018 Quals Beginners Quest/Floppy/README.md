# Floppy

This time we get only some .ico file, but when we open it in notepad++ we can see that it contains some filenames, so maybe it's an archive?
We can extract its content with 7-zip. First file is `drivers.txt` and it contains our flag.

Flag: `CTF{qeY80sU6Ktko8BJW}`

# Floppy 2

Now we have to do something with www.com file. I downloaded DOSbox, but it only displays text `The Foobanizer9000 is no longer on the OffHub DMZ.`.
I couldn't find any way to decompile it, so I decided to debug it. I found compiled debugger for dosbox at https://www.vogons.org/viewtopic.php?t=3944
I was running program in single stepping mode until i realized it writes something to memory.
```
01FE:012D  8B2C                mov  bp,[si]                ds:[016E]=4C4C
01FE:012F  312D                xor  [di],bp                ss:[015C]=0D0D
```
I navigated to `ds:[016E]` in data overview and I found my flag (it was after many iterations of the above code)
```
01FE:0130     2D 46 47 49 75 F5 5A 68 48 49 58 25 41 29 CD 21  -FGIu.ZhHIX%A).!
01FE:0140     68 53 4C 58 34 53 CD 21 43 54 46 7B 67 30 30 64  hSLX4S.!CTF{g00d
01FE:0150     6F 31 64 44 4F 53 2D 46 54 57 7D 0D 0D 0D 5D 55  o1dDOS-FTW}...]U
01FE:0160     64 29 48 4F 3B 7B 20 6C 7B 7D 39 6C 3E 6A 4C 4C  d)HO;{ l{}9l>jLL
01FE:0170     50 5B 2D 60 7C 30 67 76 50 59 30 6F 6E 51 30 67  P[-`|0gvPY0onQ0g
01FE:0180     65 5A 30 77 59 35 3E 44 30 67 5D 68 2B 28 58 2D  eZ0wY5>D0g]h+(X-
01FE:0190     6B 26 34 60 50 5B 30 2F 2C 36 34 22 50 34 41 50  k&4`P[0/,64"P4AP
01FE:01A0     C3 0D 54 68 65 20 46 6F 6F 62 61 6E 69 7A 65 72  ..The Foobanizer
```

We can see the flag at 01FE:0148

Flag: `CTF{g00do1dDOS-FTW}`