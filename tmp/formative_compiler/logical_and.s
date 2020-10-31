.data
.text
.globl f
f:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $4, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $5, 0($8)
addi $8, $sp, 4
lw $2, 0($8)
beq $zero, $2, endand1
addi $8, $sp, 0
lw $2, 0($8)
beq $zero, $2, endand1
addi $2, $zero, 1
endand1:
addi $sp, $sp,8
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,8
jr $ra
.data
