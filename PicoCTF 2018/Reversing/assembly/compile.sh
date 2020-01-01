#!/bin/bash
gcc -m32 run0.c intro.S -o run0.e
gcc -m32 run1.c eq.S -o run1.e
gcc -m32 run2.c loop.S -o run2.e
gcc -m32 run3.c end.S -o run3.e
nasm comp.nasm -felf32
gcc -m32 comp.o -o run4.e
rm comp.o