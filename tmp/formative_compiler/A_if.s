.data
.globl f
f: .word 6
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
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
addu $10, $zero, $2 
add $2, $0, $0
bne $10, $9, condequals1
addi $2, $zero, 1
condequals1:
beq $2, $zero, if2
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $9, 0($sp)
addi $sp, $sp, 4
slt $10, $2, $9
slt $2, $9, $2
or $2, $2, $10
beq $2, $zero, if3
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 3
lw $9, 0($sp)
addi $sp, $sp, 4
slt $10, $2, $9
slt $2, $9, $2
or $2, $2, $10
beq $2, $zero, if4
addi $2, $zero, 3
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
if4:
addi $sp, $sp, 0
if3:
addi $sp, $sp, 0
if2:
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
slt $10, $2, $9
slt $2, $9, $2
or $2, $2, $10
beq $2, $zero, if5
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 4
lw $9, 0($sp)
addi $sp, $sp, 4
addu $10, $zero, $2 
add $2, $0, $0
bne $10, $9, condequals6
addi $2, $zero, 1
condequals6:
beq $2, $zero, if7
addi $2, $zero, 4
addi $sp, $sp,4
jr $ra
if7:
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 5
lw $9, 0($sp)
addi $sp, $sp, 4
slt $10, $2, $9
slt $2, $9, $2
or $2, $2, $10
beq $2, $zero, if8
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 6
lw $9, 0($sp)
addi $sp, $sp, 4
addu $10, $zero, $2 
add $2, $0, $0
bne $10, $9, condequals10
addi $2, $zero, 1
condequals10:
beq $2, $zero, else9
addi $2, $zero, 6
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
j endif9
else9:
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 7
lw $9, 0($sp)
addi $sp, $sp, 4
slt $10, $2, $9
slt $2, $9, $2
or $2, $2, $10
beq $2, $zero, else11
addi $2, $zero, 7
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
j endif11
else11:
addi $2, $zero, 1
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
endif11:
endif9:
addi $sp, $sp, 0
if8:
addi $sp, $sp, 0
if5:
addi $2, $zero, 99
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
