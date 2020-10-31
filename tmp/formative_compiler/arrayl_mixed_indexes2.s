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
addi $sp, $sp, -100
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 24
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $9, $2
slti $2, $2, 1
j expressionlabel1
forloopstart1:
addi $8, $sp, 0
lw $2, 0($8)
sll $2, $2, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 108
lw $2, 0($8)
addi $2, $sp, 108
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2, $2, $9
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, 0
expressionlabel1:
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addiu $10, $2, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $10, 0($8)
bne $2, $0, forloopstart1
forloopend1:
addi $8, $sp, 108
lw $2, 0($8)
addi $2, $sp, 108
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 108
lw $2, 0($8)
addi $2, $sp, 108
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 108
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp,112
jr $ra
addi $sp, $sp, 112
addi $sp, $sp,0
jr $ra
.data
