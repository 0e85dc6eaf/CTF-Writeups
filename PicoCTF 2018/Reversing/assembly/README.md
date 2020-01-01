# assembly-0

> asm0(0x2a,0x4f)

[source](intro_asm_rev.S)

[binary](run0.e)

On x86 we usually put return value in `eax` register.
```
mov	eax,DWORD PTR [ebp+0x8]
mov	ebx,DWORD PTR [ebp+0xc]
mov	eax,ebx
```
`mov` is just an assignment, so the final `eax` value is `DWORD PTR [ebp+0xc]` and it's the second parameter we pass to this function.

Flag is `0x4f`.

---

# assembly-1

> asm1(0x15e)

[source](eq_asm_rev.S)

[binary](run1.e)

```
cmp	DWORD PTR [ebp+0x8],0xdc
jg 	part_a
```
This code will jump to `part_a` as parameter is greater than 0xdc

```
cmp	DWORD PTR [ebp+0x8],0x68
jne	part_c
```
Argument is not equal 0x68, so we jump to `part_c`.

```
mov	eax,DWORD PTR [ebp+0x8]
add	eax,0x3
```
Function returns `our argument + 3`

Flag is `0x161`.

---

# assembly-2

> asm2(0x6,0x28)

[source](loop_asm_rev.S)

[binary](run2.e)

```
mov    	eax,DWORD PTR [ebp+0xc]
mov 	DWORD PTR [ebp-0x4],eax
```
This part creates local variable and assigns second argument to it.
```
mov    	eax,DWORD PTR [ebp+0x8]
mov	DWORD PTR [ebp-0x8],eax
```
Creates second local variable and assigns first argument to it.

```
cmp    	DWORD PTR [ebp+0x8],0x8f90
jle    	part_a
```
Executes `part_a` **while** first argument is less or equal 0x8f90.

```
part_a:
add    	DWORD PTR [ebp-0x4],0x1
add	DWORD PTR [ebp+0x8],0x8f
```
Increments first local variable and adds `0x8f` to first argument.

```
mov    	eax,DWORD PTR [ebp-0x4]
```
Function returns value of first local variable. We can use Python to calculate the final result.
```python
import math
print(hex(int(math.ceil(float(0x8f90-0x6)/0x8f + 0x28))))
```

Flag is `0x129`.

---

# assembly-3

> asm3(0xb5e8e971,0xc6b58a95,0xe20737e9)

[source](end_asm_rev.S)

[binary](run3.e)

```
mov	eax,0x19 # eax = 0x00000019
xor	al,al # eax = 0x00000000
mov	ah,BYTE PTR [ebp+0xa] # eax = 0x0000e800
sal	ax,0x10 # eax = 0x00000000
sub	al,BYTE PTR [ebp+0xd] # eax = 0x00000076
add	ah,BYTE PTR [ebp+0xc] # eax = 0x00009576
xor	ax,WORD PTR [ebp+0x12] # eax = 0x00007771
```

Flag is `0x7771`.

---

# assembly-4

[source](comp.nasm)

[binary](run4.e)

Compile with:
```
nasm comp.nasm -felf32
gcc -m32 comp.o -o run4.e
```

Flag is `picoCTF{1_h0p3_70u_c0mP1l3d_tH15_2390040222}`
