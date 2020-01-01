.intel_syntax noprefix
.global asm0
asm0:
	mov ecx,ebx # function MUST preserve ebx value, save ebx
	push	ebp
	mov	ebp,esp
	mov	eax,DWORD PTR [ebp+0x8]
	mov	ebx,DWORD PTR [ebp+0xc]
	mov	eax,ebx
	mov	esp,ebp
	pop	ebp
	mov ebx,ecx # restore ebx
	ret