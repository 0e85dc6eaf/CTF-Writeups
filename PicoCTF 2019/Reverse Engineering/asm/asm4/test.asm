[bits 32]
section	.text
	global main
	extern printf
	extern exit
asm4:
	push   ebp
	mov    ebp,esp
	push   ebx
	sub    esp,0x10
	mov    DWORD  [ebp-0x10],0x260
	mov    DWORD  [ebp-0xc],0x0
	jmp    label1
	label2:
	add    DWORD  [ebp-0xc],0x1
	label1:
	mov    edx,DWORD  [ebp-0xc]
	mov    eax,DWORD  [ebp+0x8]
	add    eax,edx
	movzx  eax,BYTE  [eax]
	test   al,al
	jne    label2
	mov    DWORD  [ebp-0x8],0x1
	jmp    label3
	label4:
	mov    edx,DWORD  [ebp-0x8]
	mov    eax,DWORD  [ebp+0x8]
	add    eax,edx
	movzx  eax,BYTE  [eax]
	movsx  edx,al
	mov    eax,DWORD  [ebp-0x8]
	lea    ecx,[eax-0x1]
	mov    eax,DWORD  [ebp+0x8]
	add    eax,ecx
	movzx  eax,BYTE  [eax]
	movsx  eax,al
	sub    edx,eax
	mov    eax,edx
	mov    edx,eax
	mov    eax,DWORD  [ebp-0x10]
	lea    ebx,[edx+eax*1]
	mov    eax,DWORD  [ebp-0x8]
	lea    edx,[eax+0x1]
	mov    eax,DWORD  [ebp+0x8]
	add    eax,edx
	movzx  eax,BYTE  [eax]
	movsx  edx,al
	mov    ecx,DWORD  [ebp-0x8]
	mov    eax,DWORD  [ebp+0x8]
	add    eax,ecx
	movzx  eax,BYTE  [eax]
	movsx  eax,al
	sub    edx,eax
	mov    eax,edx
	add    eax,ebx
	mov    DWORD  [ebp-0x10],eax
	add    DWORD  [ebp-0x8],0x1
	label3:
	mov    eax,DWORD  [ebp-0xc]
	sub    eax,0x1
	cmp    DWORD  [ebp-0x8],eax
	jl     label4
	mov    eax,DWORD  [ebp-0x10]
	add    esp,0x10
	pop    ebx
	pop    ebp
	ret
main:
	push arg1
	call asm4
	push eax
	push format
	call printf
	add esp,8
	push 0
	call exit
section	.data
	arg1: db	"picoCTF_fdb55",0
	format:	db	'picoCTF{0x%x}',0xa,0