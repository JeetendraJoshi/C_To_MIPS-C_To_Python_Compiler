.data
.text
.globl f
f:
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
