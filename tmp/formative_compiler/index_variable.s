.data
.text
.globl f
f:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -32
addi $8, $sp, 36
lw $2, 0($8)
addi $2, $sp, 36
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
j expressionlabel1
forloopstart1:
addi $8, $sp, 36
lw $2, 0($8)
sll $2, $2, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 36
lw $2, 0($8)
addi $2, $sp, 36
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2, $2, $9
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 40
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, 0
addi $8, $sp, 36
lw $2, 0($8)
addi $2, $sp, 36
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addiu $10, $2, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $10, 0($8)
expressionlabel1:
addi $8, $sp, 36
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 8
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
bne $2, $0, forloopstart1
forloopend1:
addi $2, $zero, 4
sll $2, $2, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 36
lw $2, 0($8)
addi $2, $sp, 36
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2, $2, $9
lw $2, 0($2)
addi $sp, $sp,40
jr $ra
addi $sp, $sp, 40
addi $sp, $sp,0
jr $ra
.data
