.data
.text
.globl ffff
ffff:
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
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 45
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
beq $2, $zero, if1
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
subu $2, $0, $2
lw $8, 0($sp)
addi $sp, $sp, 4
sub $2, $8, $2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $2, $9
beq $2, $zero, if2
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 3
lw $8, 0($sp)
addi $sp, $sp, 4
addu $2, $2, $8
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $10, $zero, $2 
add $2, $0, $0
bne $10, $9, condequals3
addi $2, $zero, 1
condequals3:
beq $2, $zero, if4
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
multu $2, $9
mflo $2
addi $sp, $sp,8
jr $ra
addi $sp, $sp, 0
if4:
addi $sp, $sp, 0
if2:
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,8
jr $ra
addi $sp, $sp, 0
if1:
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp,8
jr $ra
addi $sp, $sp, 8
addi $sp, $sp,0
jr $ra
.data
