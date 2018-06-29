# sql

> https://ctftime.org/writeup/10102

The file we got contains only one query `explain [redacted]` which prints us all instructions this query is going to execute.
Using opcodes list [https://sqlite.org/opcode.html](https://sqlite.org/opcode.html) we can build simple VM to execute this query.

Single instruction is built this way:
```
address|name|P1|P2|P3|P4|P5|
```
where P is just an argument.

First of all we can notice that there are many opcodes that are useless for us as we don't have access to database and can't read any data from it.
We can ignore `Trace`,`Transaction`,`VerifyCookie`,`TableLock`,`OpenRead`,`Rewind`,`Column`,`ResultRow`,`Next` and `Close` instructions.
Implementing `Halt` and `Goto` also is very simple, because we just stop executing query in the first case and change instruction pointer in the second case.

First useful instructions which are executed are `Integer` and `String8` (we jump to them with `Goto`).
`Integer` stores value given in P1 in register with index P2. `String8` is a little more complicated but in this challenge we can just assume it stores letter given in P4 in register with index P2.

After initializing the registers we execute second part of the query which consists of a long series of  `Column`, `Function` and `Ne` instructions.

`Column` stores value from database in register with index P3 (that's why we can ignore it in our VM).

All `Function` instructions in this query execute `substr()` function with 3 arguments (string,start,length). Arguments are taken from registers starting at index P2 and  return value is written to register with index P3.

By examining registers values we can see that this function always takes 1 byte of string returned by databse in `Column` instruction.
The second argument for this function (so register with index `P2+1`) contains char index (starting from 1) we want to extract.

This one char goes to the register with index 1 which is later compared with value from register P1 in `Ne` instruction.
If the values were different we would just jump to the end of program (and possibly start extractring other records) so we can assume that they must be the same and the query executes without any problems until the end (we wouldn't be able to solve this otherwise).

So we know that P1 (from `String8`) is compared in `Ne` instruction with the preceding `Function`'s return value (single char at `P2+1`th position in the record from database, please note it's `P2+1` of `Function` instruction not `Ne`).

When we finally reach `Halt` instruction we'll know every character of flag as well as its index. We only need to glue all the parts together in the correct order and we get the flag.

`flag{lqs_rof_galf_esrever_a}`