.data
.text
.globl multiply
multiply:
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
addi $8, $sp, 8
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
beq $2, $zero, if1
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
sw $31, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 20
lw $2, 0($8)
subu $2, $0, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 20
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $8, 0
addi $8, $sp, 4
sw $2, 0($8)
addi $8, $sp, 4
lw $4, 0($8)
addi $8, $sp, 0
lw $5, 0($8)
jal multiply
nop
addi $sp, $sp, 4
addi $sp, $sp, 4
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
subu $2, $0, $2
addi $sp, $sp,12
jr $ra
addi $sp, $sp, 0
if1:
while2:
addi $8, $sp, 8
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $2, $9
beq $2, $zero, whileend2
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
addu $2, $2, $8
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 8
lw $2, 0($8)
addi $2, $sp, 8
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addiu $10, $2, -1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $10, 0($8)
addi $sp, $sp, 0
j while2
whileend2:
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,12
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,8
jr $ra
.data
