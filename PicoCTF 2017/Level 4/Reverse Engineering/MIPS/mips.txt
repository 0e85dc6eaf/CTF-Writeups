.data
fail:
  .asciiz  "Not quite! Keep trying.\n"
success:
  .asciiz  "Good job! Submit your input value as the flag.\n"

.text
main:
  li $v0, 5
  syscall                    # SPIM read_int system call (Note: decimal, not hex)
  move    $4,$v0
  addiu   $sp,$sp,-32
  sw      $31,28($sp)
  sw      $16,24($sp)
  li      $6,-16777216       # 0xffffffffff000000
  and     $6,$4,$6
  li      $16,16711680       # 0xff0000
  and     $16,$4,$16
  andi    $7,$4,0xff00
  andi    $4,$4,0xff
  sra     $3,$6,24
  move    $2,$0
$L3:
  slt     $5,$2,13
  beq     $5,$0,$L2
  addiu   $2,$2,1
  b       $L3
  addiu   $3,$3,-13
$L2:
  addiu   $3,$3,-6
  sll     $5,$3,24
  sra     $16,$16,16
  addiu   $2,$16,-81
  sll     $8,$2,6
  sll     $3,$2,8
  subu    $3,$3,$8
  subu    $3,$2,$3
  sra     $7,$7,8
  sll     $2,$4,1
  addiu   $2,$2,3
  bne     $7,$2,$L7
  sll     $3,$3,16
  b       $L4
  li      $2,94
$L7:
  li      $2,165
$L4:
  addiu   $2,$2,-94
  sll     $2,$2,8
  srl     $6,$6,24
  subu    $16,$6,$16
  subu    $4,$4,$16
  addu    $3,$5,$3
  addu    $3,$2,$3
  addu    $16,$4,$3
  bne     $16,$0,$L5
  li $v0, 4
  la $a0, success
  syscall                  # SPIM print_string system call
  lw      $28,16($sp)
  b       $L9
  move    $2,$16
$L5:
  li $v0, 4
  la $a0, fail
  syscall                  # SPIM print_string system call
  lw      $28,16($sp)
  move    $2,$16
$L9:
  lw      $31,28($sp)
  lw      $16,24($sp)
  j       $31
  addiu   $sp,$sp,32
