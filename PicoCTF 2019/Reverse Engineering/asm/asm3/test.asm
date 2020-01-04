[bits 32]
section	.text
	global main
	extern printf
	extern exit
asm3:
	push   ebp
	mov    ebp,esp
	xor    eax,eax
	mov    ah,BYTE [ebp+0x9];0xbd
	shl    ax,0x10
	sub    al,BYTE [ebp+0xd];0x6c
	add    ah,BYTE [ebp+0xf];0xb5
	xor    ax,WORD [ebp+0x10];0x1175
	nop
	pop    ebp
	ret
main:
	push 0xad761175
	push 0xb5a06caa
	push 0xc264bd5c
	call asm3
	push eax
	push format
	call printf
	add esp,8
	push 0
	call exit
section	.data
	format:	db 'picoCTF{0x%x}',0xa,0