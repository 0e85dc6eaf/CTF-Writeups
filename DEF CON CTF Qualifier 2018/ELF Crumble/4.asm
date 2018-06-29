00000000  E871FBFFFF        call 0xfffffb76
00000005  83C430            add esp,byte +0x30
00000008  B800000000        mov eax,0x0
0000000D  8B7DE4            mov edi,[ebp-0x1c]
00000010  65333D14000000    xor edi,[dword gs:0x14]
00000017  7405              jz 0x1e
00000019  E888000000        call 0xa6
0000001E  8D65F0            lea esp,[ebp-0x10]
00000021  59                pop ecx
00000022  5B                pop ebx
00000023  5E                pop esi
00000024  5F                pop edi
00000025  5D                pop ebp
00000026  8D61FC            lea esp,[ecx-0x4]
00000029  C3                ret
