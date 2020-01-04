[bits 32]
section	.text
	global main
	extern printf
	extern exit
asm2:
	push   ebp
	mov    ebp,esp
	sub    esp,0x10
	mov    eax,DWORD [ebp+0xc]
	mov    DWORD [ebp-0x4],eax
	mov    eax,DWORD [ebp+0x8]
	mov    DWORD [ebp-0x8],eax
	jmp    label1
	label2:
	add    DWORD [ebp-0x4],0x1
	add    DWORD [ebp-0x8],0xf9
	label1:
	cmp    DWORD [ebp-0x8],0x3c75
	jle    label2
	mov    eax,DWORD [ebp-0x4]
	leave
	ret
main:
	push 0x24
	push 0x6
	call asm2
	push eax
	push format
	call printf
	add esp,8
	push 0
	call exit
section	.data
	format:	db 'picoCTF{0x%x}',0xa,0