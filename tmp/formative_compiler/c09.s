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
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 5
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $9, $2
slti $2, $2, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 3
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $2, $9
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 44
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 56
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 45
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $9, $2
slti $2, $2, 1
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 67
lw $9, 0($sp)
addi $sp, $sp, 4
slt $10, $2, $9
slt $2, $9, $2
or $2, $2, $10
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $2, $9
slti $2, $2, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 8
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 8
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 5
lw $9, 0($sp)
addi $sp, $sp, 4
addu $10, $zero, $2 
add $2, $0, $0
bne $10, $9, condequals1
addi $2, $zero, 1
condequals1:
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 12
lw $2, 0($8)
addi $2, $sp, 12
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 12
lw $2, 0($8)
addi $sp, $sp,16
jr $ra
addi $sp, $sp, 16
addi $sp, $sp,0
jr $ra
.data
