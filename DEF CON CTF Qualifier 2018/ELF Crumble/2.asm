00000000  83EC0C            sub esp,byte +0xc
00000003  FF7508            push dword [ebp+0x8]
00000006  E813FFFFFF        call 0xffffff1e
0000000B  83C410            add esp,byte +0x10
0000000E  90                nop
0000000F  C9                leave
00000010  C3                ret
00000011  8D4C2404          lea ecx,[esp+0x4]
00000015  83E4F0            and esp,byte -0x10
00000018  FF71FC            push dword [ecx-0x4]
0000001B  55                push ebp
0000001C  89E5              mov ebp,esp
0000001E  57                push edi
0000001F  56                push esi
00000020  53                push ebx
00000021  51                push ecx
00000022  83EC38            sub esp,byte +0x38
00000025  E8BBFCFFFF        call 0xfffffce5
0000002A  81C3DB170000      add ebx,0x17db
