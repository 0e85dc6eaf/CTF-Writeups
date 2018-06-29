# ELF Crumble

This time we got broken binary (807 bytes was replaced with 'X') and 8 code fragments.
To disassemble the fragments we can use `ndisasm`. Total length of the fragments is equal 807, so we are sure that nothing is missing (it was also mentioned in challenge description).
IDA reveals that there are five functions `f1`,`f2`,`f3`,`recover_flag`,`main` in the binary and they are all broken.
We can calculate length of each function.

```
f1 000005AD-000006E8 (316 bytes)
f2 000006E9-0000072D (69 bytes)
f3 0000072E-000007A1 (116 bytes)
recover_flag 000007A2-000007DB (58 bytes)
main 000007DC-000008D3 (248 bytes)
```
We know that function in assembly (usually) starts with
```
push ebp
mov ebp,esp
```
* Fragment 8th is the only one that starts with these instruction, so it must be the beginning of `f1`.
* Fragment 4th is the only one that ends with `ret`, so it must be the end of `main`.
* Fragment 1st contains one whole function. This function is 69 bytes long, so it is `f2` (also this fragment contains end of `f1` and beginning of `f3`)
* Fragment 7th fits the rest of `f1` (283 bytes)
* Fragment 3rd is too long to fit `f3` or `recover_flag` so it must be the middle part of `main`
* Fragment 2nd must be the beginning of `main` as if we put 5th there we length would not match
* Fragment 5th is the beginning of `recover_flag`
* Fragment 6th is the middle part of `recover_flag`

In the end we get something like this
```
[8]->[7]->[1]->[5]->[6]->[2]->[3]->[4]
```
We can use python script to place the fragments in the binary.

[fix.py](fix.py)

`fixed` binary prints us the flag.

Flag: `welcOOOme`