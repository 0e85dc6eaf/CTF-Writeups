# script me

> Can you understand the language and answer the questions to retrieve the flag? Connect to the service with nc 2018shell1.picoctf.com 8672

Hints:

> Maybe try writing a python script?

This challenge is not really difficult (or I didn't understand it). We can realize that in fact there are only 3 rules.

1. If both components have the same nesting level we just concatenate them.
2. If second component has greater nesting level we put first component just after opening bracket of second component.
3. If first component has greater nesting level we put second component just before closing bracket of first component.

And an additional rule: we add from left to right.

[Solver](solve.py)

Flag is `picoCTF{5cr1pt1nG_l1k3_4_pRo_0970eb2d}`.