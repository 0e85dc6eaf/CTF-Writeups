00000000  89C8              mov eax,ecx
00000002  8B4004            mov eax,[eax+0x4]
00000005  8945C4            mov [ebp-0x3c],eax
00000008  65A114000000      mov eax,[gs:0x14]
0000000E  8945E4            mov [ebp-0x1c],eax
00000011  31C0              xor eax,eax
00000013  C745CD44696420    mov dword [ebp-0x33],0x20646944
0000001A  C745D1596F7520    mov dword [ebp-0x2f],0x20756f59
00000021  C745D546696E44    mov dword [ebp-0x2b],0x446e6946
00000028  C745D920746865    mov dword [ebp-0x27],0x65687420
0000002F  C745DD20476C55    mov dword [ebp-0x23],0x556c4720
00000036  66C745E1653F      mov word [ebp-0x1f],0x3f65
0000003C  C645E300          mov byte [ebp-0x1d],0x0
00000040  C745C801000000    mov dword [ebp-0x38],0x1
00000047  83EC0C            sub esp,byte +0xc
0000004A  8D45CD            lea eax,[ebp-0x33]
0000004D  50                push eax
0000004E  E854FFFFFF        call 0xffffffa7
00000053  83C410            add esp,byte +0x10
00000056  0FB645E1          movzx eax,byte [ebp-0x1f]
0000005A  0FBEC8            movsx ecx,al
0000005D  0FB645CD          movzx eax,byte [ebp-0x33]
00000061  0FBEF8            movsx edi,al
00000064  0FB645D8          movzx eax,byte [ebp-0x28]
00000068  0FBEC0            movsx eax,al
0000006B  8945C0            mov [ebp-0x40],eax
0000006E  0FB645D8          movzx eax,byte [ebp-0x28]
00000072  0FBED0            movsx edx,al
00000075  8955BC            mov [ebp-0x44],edx
00000078  0FB645D8          movzx eax,byte [ebp-0x28]
0000007C  0FBEF0            movsx esi,al
0000007F  8975B8            mov [ebp-0x48],esi
00000082  0FB645CE          movzx eax,byte [ebp-0x32]
00000086  0FBEF0            movsx esi,al
00000089  0FB645E1          movzx eax,byte [ebp-0x1f]
0000008D  0FBED0            movsx edx,al
00000090  0FB645D5          movzx eax,byte [ebp-0x2b]
00000094  0FBEC0            movsx eax,al
00000097  83EC0C            sub esp,byte +0xc
0000009A  51                push ecx
0000009B  57                push edi
0000009C  FF75C0            push dword [ebp-0x40]
0000009F  FF75BC            push dword [ebp-0x44]
000000A2  FF75B8            push dword [ebp-0x48]
000000A5  56                push esi
000000A6  52                push edx
000000A7  50                push eax
000000A8  8D83B0E9FFFF      lea eax,[ebx-0x1650]
000000AE  50                push eax
