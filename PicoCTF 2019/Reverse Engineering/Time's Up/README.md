# Time's Up

[script](solve1.py)

Flag: `picoCTF{Gotta go fast. Gotta go FAST. #3c3eaafb}`

# Time's Up, Again!

Python is too slow? We can use C.

[solver](solve2.c)

Compile:
```
gcc solve2.c -o solve2.e -O3
```

Flag: `picoCTF{Hasten. Hurry. Ferrociously Speedy. #2edc7d0a}`

# Time's Up, For the Last Time!

This time even C is too slow. To solve this challenge we need to block `SIGALRM` signal (we could do this in previous challenges too).

Another thing that was added in this challenge are 5 custom operations:
```
x,r,o: return right operand
t,f: return left operand
```

[solver](solve3.c)

Compile:
```
gcc solve3.c -o solve3.e -O3
```

Flag: `picoCTF{And now you can hack time! #0f00cb4e}`