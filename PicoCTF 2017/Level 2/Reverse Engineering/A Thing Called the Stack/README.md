# A Thing Called the Stack

> A friend was stacking dinner plates, and handed you this, saying something about a "stack". Can you find the difference between the value of esp at the end of the code, and the location of the saved return address? Assume a 32 bit system. Submit the answer as a hexidecimal number, with no extraneous 0s. For example, the decimal number 2015 would be submitted as 0x7df, not 0x000007df

Hints:

> Where is the return address saved on the stack?

> Which commands actually affect the stack?

The instructions which actually affect esp register are in this case pushl and `sub $0x124, %esp`.
We know that stacks grows downwards, so `sub` instruction makes difference equal 0x124 and each pushl increases this value by next 4 bytes

`0x124+4*4=0x134`

The flag is `0x134`.