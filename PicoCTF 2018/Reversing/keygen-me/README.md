# keygen-me-1

Constraints:
1. Code must be 16 chars long
2. Only digits and uppercase letters are allowed
3. Last character is a checksum

Since there are only 36 possible checksums, we can test all possible values.

[brute force checksum](solve1.py)

```
$ ./solve1.py THISWASEASYCHAL
THISWASEASYCHALT
```

```
pico-2018-shell:/problems/keygen-me-1_2_74297f5e012cf93ee059a2be15d77734$ ./activate THISWASEASYCHALT
Product Activated Successfully: picoCTF{k3yg3n5_4r3_s0_s1mp13_1295245566}
```

Flag: `picoCTF{k3yg3n5_4r3_s0_s1mp13_1295245566}`

# keygen-me-2

Constraints:
1. Code must be 16 chars long
2. Only digits and uppercase letters are allowed
3. Code must satisfy 12 additional constraints defined in the application.

To calculate the correct key we can use [z3](https://github.com/Z3Prover/z3).

[solver](solve2.py)

```
$ ./solve2.py
UK0O2WBLL7Z0Z3VE
```

```
pico-2018-shell:/problems/keygen-me-2_0_ac2a45bc27456d666f2bbb6921829203$ ./activate UK0O2WBLL7Z0Z3VE
Product Activated Successfully: picoCTF{c0n5tr41nt_50lv1nG_15_W4y_f45t3r_783243818}
```

Flag: `picoCTF{c0n5tr41nt_50lv1nG_15_W4y_f45t3r_783243818}`