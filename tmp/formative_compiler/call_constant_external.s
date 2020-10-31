.data
.space 4
.text
.globl f
f:
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $31, 0($sp)
jal g
nop
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
