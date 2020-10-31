.data
.space 4
.text
.globl f
f:
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
sw $31, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 10
addi $8, $sp, 0
sw $2, 0($8)
addi $8, $sp, 0
lw $4, 0($8)
jal g
nop
addi $sp, $sp, 4
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
