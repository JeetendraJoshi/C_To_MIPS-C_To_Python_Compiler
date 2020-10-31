.data
.text
.globl ffff
ffff:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 5
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
j switch1
addi $2, $zero, 1
case1_0:
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
j expressionlabel2
forloopstart2:
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $8, 0($sp)
addi $sp, $sp, 4
addu $2, $2, $8
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, 0
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addiu $10, $2, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $10, 0($8)
expressionlabel2:
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 10
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
bne $2, $0, forloopstart2
forloopend2:
j switchend1
addi $2, $zero, 2
case1_1:
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 45
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
j switchend1
default1:
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 12
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
j switchend1
addi $sp, $sp, 0
switch1:
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $0, 1
beq $2, $8, case1_0
addi $8, $0, 2
beq $2, $8, case1_1
j default1
switchend1:
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,8
jr $ra
addi $sp, $sp, 8
addi $sp, $sp,0
jr $ra
.data
