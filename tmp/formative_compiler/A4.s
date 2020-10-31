.data
.text
.globl ffff
ffff:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, 0
addi $2, $zero, 1
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
nor $2, $2, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $9, $2
slti $2, $2, 1
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $2, $9
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $2, $9
slti $2, $2, 1
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
divu $9, $2
mflo $2
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
divu $9, $2
mfhi $2
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
sll $2, $2, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2, $2, $9
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 9
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $2, $zero, 1
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
nor $2, $2, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $9, $2
slti $2, $2, 1
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $2, $9
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $2, $9
slti $2, $2, 1
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
divu $9, $2
mflo $2
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
divu $9, $2
mfhi $2
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
sll $2, $2, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2, $2, $9
lw $2, 0($2)
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
