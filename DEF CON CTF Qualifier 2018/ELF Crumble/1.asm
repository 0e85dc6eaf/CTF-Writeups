00000000  5B                pop ebx
00000001  5D                pop ebp
00000002  C3                ret
00000003  55                push ebp
00000004  89E5              mov ebp,esp
00000006  83EC10            sub esp,byte +0x10
00000009  E8E0010000        call 0x1ee
0000000E  05DC180000        add eax,0x18dc
00000013  C745FC00000000    mov dword [ebp-0x4],0x0
0000001A  EB23              jmp short 0x3f
0000001C  8B55FC            mov edx,[ebp-0x4]
0000001F  8B4508            mov eax,[ebp+0x8]
00000022  01D0              add eax,edx
00000024  0FB600            movzx eax,byte [eax]
00000027  89C2              mov edx,eax
00000029  8B45FC            mov eax,[ebp-0x4]
0000002C  8D0C02            lea ecx,[edx+eax]
0000002F  8B55FC            mov edx,[ebp-0x4]
00000032  8B4508            mov eax,[ebp+0x8]
00000035  01D0              add eax,edx
00000037  89CA              mov edx,ecx
00000039  8810              mov [eax],dl
0000003B  8345FC01          add dword [ebp-0x4],byte +0x1
0000003F  837DFC13          cmp dword [ebp-0x4],byte +0x13
00000043  7ED7              jng 0x1c
00000045  90                nop
00000046  C9                leave
00000047  C3                ret
00000048  55                push ebp
00000049  89E5              mov ebp,esp
0000004B  53                push ebx
0000004C  83EC14            sub esp,byte +0x14
