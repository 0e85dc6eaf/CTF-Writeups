.intel_syntax noprefix
.bits 32
	
.global asm3

asm3:
	push   	ebp
	mov    	ebp,esp
	mov	eax,0x19
	xor	al,al
	mov	ah,BYTE PTR [ebp+0xa]
	sal	ax,0x10
	sub	al,BYTE PTR [ebp+0xd]
	add	ah,BYTE PTR [ebp+0xc]
	xor	ax,WORD PTR [ebp+0x12]
	mov	esp, ebp
	pop	ebp
	ret
