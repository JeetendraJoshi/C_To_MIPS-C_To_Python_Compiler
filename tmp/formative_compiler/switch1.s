.data
.text
.globl g
g:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $4, 0($8)
j switch1
addi $2, $zero, 1
case1_0:
addi $2, $zero, 10
addi $sp, $sp,4
jr $ra
addi $2, $zero, 2
case1_1:
addi $2, $zero, 11
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
switch1:
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $0, 1
beq $2, $8, case1_0
addi $8, $0, 2
beq $2, $8, case1_1
switchend1:
addi $sp, $sp, 0
addi $sp, $sp,4
jr $ra
.data
