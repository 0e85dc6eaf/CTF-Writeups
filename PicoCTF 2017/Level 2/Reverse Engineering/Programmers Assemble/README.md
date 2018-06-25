# Programmers Assemble

> You found a text file with some really low level code. Some value at the beginning has been X'ed out. Can you figure out what should be there, to make main return the value 0x1? Submit the answer as a hexidecimal number, with no extraneous 0s. For example, the decimal number 2015 would be submitted as 0x7df, not 0x000007df

Hints:

> All of the commands can be found here along with what they do.

> It may be useful to be able to run the code, with test values.

Ok, the only case when our code returns 1 is when we reach `good` label. The application will jump to `good` when the `ebx` register equals 0x47c8 (`cmp $0x47c8, %ebx`).
We can see that `ebx` is incremented by `ecx` in loop and the `ecx` equals 8. Loop continues to repeat while `eax` is different from 0 and it's value is what we need to find.
We simply need to calculate how many iterations do we need to make `ebx` equal 0x47c8 at the end.
`0x47c8 / 8 = 0x8f9`

The flag is `0x8f9`.