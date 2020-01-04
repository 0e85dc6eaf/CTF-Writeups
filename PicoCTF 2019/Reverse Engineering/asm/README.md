# asm1

After small modifications, you can compile the source code and execute it.

[original](asm1/test.S)

[modified](asm1/test.asm)

Compile with:
```
nasm asm1/test.asm -felf32
gcc -m32 asm1/test.o -o run1.e
rm asm1/test.o
```

[compiled application](run1.e)

Flag: `picoCTF{0x348}`

# asm2

[original](asm2/test.S)

[modified](asm2/test.asm)

Compile with:
```
nasm asm2/test.asm -felf32
gcc -m32 asm2/test.o -o run2.e
rm asm2/test.o
```

[compiled application](run2.e)

Flag: `picoCTF{0x63}`

# asm3

[original](asm3/test.S)

[modified](asm3/test.asm)

Compile with:
```
nasm asm3/test.asm -felf32
gcc -m32 asm3/test.o -o run3.e
rm asm3/test.o
```

[compiled application](run3.e)

Flag: `picoCTF{0xa4e1}`

# asm4

[original](asm4/test.S)

[modified](asm4/test.asm)

Compile with:
```
nasm asm4/test.asm -felf32
gcc -m32 asm4/test.o -o run4.e
rm asm4/test.o
```

[compiled application](run4.e)

Flag: `picoCTF{0x1f1}`