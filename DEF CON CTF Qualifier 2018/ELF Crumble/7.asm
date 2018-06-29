00000000  0FB612            movzx edx,byte [edx]
00000003  8855FB            mov [ebp-0x5],dl
00000006  8B9038000000      mov edx,[eax+0x38]
0000000C  89D1              mov ecx,edx
0000000E  8B5508            mov edx,[ebp+0x8]
00000011  01CA              add edx,ecx
00000013  0FB612            movzx edx,byte [edx]
00000016  8D4A02            lea ecx,[edx+0x2]
00000019  8B9038000000      mov edx,[eax+0x38]
0000001F  89D3              mov ebx,edx
00000021  8B5508            mov edx,[ebp+0x8]
00000024  01DA              add edx,ebx
00000026  880A              mov [edx],cl
00000028  8B9038000000      mov edx,[eax+0x38]
0000002E  8D4A02            lea ecx,[edx+0x2]
00000031  8B5508            mov edx,[ebp+0x8]
00000034  01D1              add ecx,edx
00000036  0FB655FB          movzx edx,byte [ebp-0x5]
0000003A  8811              mov [ecx],dl
0000003C  8B903C000000      mov edx,[eax+0x3c]
00000042  89D1              mov ecx,edx
00000044  8B5508            mov edx,[ebp+0x8]
00000047  01CA              add edx,ecx
00000049  0FB612            movzx edx,byte [edx]
0000004C  8855FB            mov [ebp-0x5],dl
0000004F  8B903C000000      mov edx,[eax+0x3c]
00000055  89D1              mov ecx,edx
00000057  8B5508            mov edx,[ebp+0x8]
0000005A  01CA              add edx,ecx
0000005C  0FB612            movzx edx,byte [edx]
0000005F  8D4A03            lea ecx,[edx+0x3]
00000062  8B903C000000      mov edx,[eax+0x3c]
00000068  89D3              mov ebx,edx
0000006A  8B5508            mov edx,[ebp+0x8]
0000006D  01DA              add edx,ebx
0000006F  880A              mov [edx],cl
00000071  8B903C000000      mov edx,[eax+0x3c]
00000077  8D4A03            lea ecx,[edx+0x3]
0000007A  8B5508            mov edx,[ebp+0x8]
0000007D  01D1              add ecx,edx
0000007F  0FB655FB          movzx edx,byte [ebp-0x5]
00000083  8811              mov [ecx],dl
00000085  8B9040000000      mov edx,[eax+0x40]
0000008B  89D1              mov ecx,edx
0000008D  8B5508            mov edx,[ebp+0x8]
00000090  01CA              add edx,ecx
00000092  0FB612            movzx edx,byte [edx]
00000095  8855FB            mov [ebp-0x5],dl
00000098  8B9040000000      mov edx,[eax+0x40]
0000009E  89D1              mov ecx,edx
000000A0  8B5508            mov edx,[ebp+0x8]
000000A3  01CA              add edx,ecx
000000A5  0FB612            movzx edx,byte [edx]
000000A8  8D4A04            lea ecx,[edx+0x4]
000000AB  8B9040000000      mov edx,[eax+0x40]
000000B1  89D3              mov ebx,edx
000000B3  8B5508            mov edx,[ebp+0x8]
000000B6  01DA              add edx,ebx
000000B8  880A              mov [edx],cl
000000BA  8B9040000000      mov edx,[eax+0x40]
000000C0  8D4A04            lea ecx,[edx+0x4]
000000C3  8B5508            mov edx,[ebp+0x8]
000000C6  01D1              add ecx,edx
000000C8  0FB655FB          movzx edx,byte [ebp-0x5]
000000CC  8811              mov [ecx],dl
000000CE  8B9044000000      mov edx,[eax+0x44]
000000D4  89D1              mov ecx,edx
000000D6  8B5508            mov edx,[ebp+0x8]
000000D9  01CA              add edx,ecx
000000DB  0FB612            movzx edx,byte [edx]
000000DE  8855FB            mov [ebp-0x5],dl
000000E1  8B9044000000      mov edx,[eax+0x44]
000000E7  89D1              mov ecx,edx
000000E9  8B5508            mov edx,[ebp+0x8]
000000EC  01CA              add edx,ecx
000000EE  0FB612            movzx edx,byte [edx]
000000F1  8D4A05            lea ecx,[edx+0x5]
000000F4  8B9044000000      mov edx,[eax+0x44]
000000FA  89D3              mov ebx,edx
000000FC  8B5508            mov edx,[ebp+0x8]
000000FF  01DA              add edx,ebx
00000101  880A              mov [edx],cl
00000103  8B8044000000      mov eax,[eax+0x44]
00000109  8D5005            lea edx,[eax+0x5]
0000010C  8B4508            mov eax,[ebp+0x8]
0000010F  01C2              add edx,eax
00000111  0FB645FB          movzx eax,byte [ebp-0x5]
00000115  8802              mov [edx],al
00000117  90                nop
00000118  83C410            add esp,byte +0x10
