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
addi $2, $zero, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
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
while1:
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 50
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
beq $2, $zero, whileend1
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
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 33
lw $9, 0($sp)
addi $sp, $sp, 4
addu $10, $zero, $2 
add $2, $0, $0
bne $10, $9, condequals2
addi $2, $zero, 1
condequals2:
beq $2, $zero, if3
beq $0, $0,  while1
addi $sp, $sp, 0
if3:
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
addi $sp, $sp, 0
j while1
whileend1:
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,8
jr $ra
addi $sp, $sp, 8
addi $sp, $sp,0
jr $ra
.data
