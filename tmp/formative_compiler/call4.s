.data
.text
.globl hh
hh:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $4, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,4
jr $ra
.data
.text
.globl ffff
ffff:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 8
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
sw $31, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 99
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $8, $sp, 0
sw $2, 0($8)
addi $8, $sp, 0
lw $4, 0($8)
jal hh
nop
addi $sp, $sp, 4
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
