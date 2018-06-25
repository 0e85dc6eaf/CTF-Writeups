# The Early School

> Welcome to ASIS Early School.

We got an archive that contains some python script and encrypted flag. Encryption algorithm is really simple: we just take 2 bits of the message and append their xor to them.
If the length was odd we append 0 bit to it. So to decrypt the message we just need to split it in 3-bits blocks and remove last bit (if last block has 2 bits we need to remove the second one).
We can do it recursively until decrypted text doesn't start with ASIS. [Final script](solve.py)

Flag: `ASIS{50_S1mPl3_CryptO__4__warmup____}`