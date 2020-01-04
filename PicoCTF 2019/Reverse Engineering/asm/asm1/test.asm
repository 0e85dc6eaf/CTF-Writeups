[bits 32]
section	.text
	global main
	extern printf
	extern exit
asm1:
	push   ebp
	mov    ebp,esp
	cmp    DWORD [ebp+0x8],0x37a
	jg     label1
	cmp    DWORD [ebp+0x8],0x345
	jne    label2
	mov    eax,DWORD [ebp+0x8]
	add    eax,0x3
	jmp    label3
	label2:
	mov    eax,DWORD [ebp+0x8]
	sub    eax,0x3
	jmp    label3
	label1:
	cmp    DWORD [ebp+0x8],0x5ff
	jne    label4
	mov    eax,DWORD [ebp+0x8]
	sub    eax,0x3
	jmp    label3
	label4:
	mov    eax,DWORD [ebp+0x8]
	add    eax,0x3
	label3:
	pop    ebp
	ret
main:
	push 0x345
	call asm1
	push eax
	push format
	call printf
	add esp,8
	push 0
	call exit
section	.data
	format:	db 'picoCTF{0x%x}',0xa,0