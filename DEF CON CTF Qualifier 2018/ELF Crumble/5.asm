00000000  E89A010000        call 0x19f
00000005  0596180000        add eax,0x1896
0000000A  83EC0C            sub esp,byte +0xc
0000000D  FF7508            push dword [ebp+0x8]
00000010  89C3              mov ebx,eax
00000012  E8F4FCFFFF        call 0xfffffd0b
00000017  83C410            add esp,byte +0x10
0000001A  8945F4            mov [ebp-0xc],eax
0000001D  C745F000000000    mov dword [ebp-0x10],0x0
00000024  EB2D              jmp short 0x53
00000026  8B55F0            mov edx,[ebp-0x10]
00000029  8B4508            mov eax,[ebp+0x8]
0000002C  01D0              add eax,edx
0000002E  0FB608            movzx ecx,byte [eax]
00000031  8B45F0            mov eax,[ebp-0x10]
00000034  01C0              add eax,eax
00000036  BA6D000000        mov edx,0x6d
0000003B  29C2              sub edx,eax
0000003D  89D0              mov eax,edx
0000003F  89C3              mov ebx,eax
00000041  8B55F0            mov edx,[ebp-0x10]
00000044  8B4508            mov eax,[ebp+0x8]
00000047  01D0              add eax,edx
00000049  09D9              or ecx,ebx
0000004B  89CA              mov edx,ecx
0000004D  8810              mov [eax],dl
0000004F  8345F001          add dword [ebp-0x10],byte +0x1
00000053  8B45F4            mov eax,[ebp-0xc]
00000056  89C2              mov edx,eax
00000058  C1EA1F            shr edx,byte 0x1f
0000005B  01D0              add eax,edx
0000005D  D1F8              sar eax,1
0000005F  83E804            sub eax,byte +0x4
00000062  3945F0            cmp [ebp-0x10],eax
00000065  7CBF              jl 0x26
00000067  90                nop
00000068  8B5DFC            mov ebx,[ebp-0x4]
0000006B  C9                leave
0000006C  C3                ret
0000006D  55                push ebp
0000006E  89E5              mov ebp,esp
00000070  83EC08            sub esp,byte +0x8
00000073  E827010000        call 0x19f
00000078  0523180000        add eax,0x1823
0000007D  FF7508            push dword [ebp+0x8]
