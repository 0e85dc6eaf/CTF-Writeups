#!/bin/bash
nasm asm1/test.asm -felf32
gcc -m32 asm1/test.o -o run1.e
rm asm1/test.o
nasm asm2/test.asm -felf32
gcc -m32 asm2/test.o -o run2.e
rm asm2/test.o
nasm asm3/test.asm -felf32
gcc -m32 asm3/test.o -o run3.e
rm asm3/test.o
nasm asm4/test.asm -felf32
gcc -m32 asm4/test.o -o run4.e
rm asm4/test.o