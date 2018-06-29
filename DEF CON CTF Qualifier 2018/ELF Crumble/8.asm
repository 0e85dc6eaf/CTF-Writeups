00000000  55                push ebp
00000001  89E5              mov ebp,esp
00000003  53                push ebx
00000004  83EC10            sub esp,byte +0x10
00000007  E81B030000        call 0x327
0000000C  05171A0000        add eax,0x1a17
00000011  8B9038000000      mov edx,[eax+0x38]
00000017  89D1              mov ecx,edx
00000019  8B5508            mov edx,[ebp+0x8]
0000001C  01CA              add edx,ecx
