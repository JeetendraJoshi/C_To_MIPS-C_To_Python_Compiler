.data
.text
.globl bsqrt
bsqrt:
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
addi $8, $sp, 0
sw $6, 0($8)
while1:
addi $8, $sp, 8
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 8
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
beq $2, $zero, whileend1
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 16
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 16
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
rightshift2:
beq $2, $zero, rightshiftend2
addi $2, $2, -1
srl $9, $9, 1
j rightshift2
rightshiftend2:
add $2, $9, $zero
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
addi $8, $sp, 12
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
multu $2, $9
mflo $2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
sub $2, $9, $2
slti $2, $2, 1
beq $2, $zero, else3
addi $8, $sp, 16
lw $2, 0($8)
addi $2, $sp, 16
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 8
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, 0
j endif3
else3:
addi $8, $sp, 12
lw $2, 0($8)
addi $2, $sp, 12
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 8
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, 0
endif3:
addi $sp, $sp, 8
j while1
whileend1:
addi $8, $sp, 8
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
multu $2, $9
mflo $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
slt $2, $9, $2
beq $2, $zero, else4
addi $8, $sp, 4
lw $2, 0($8)
addi $sp, $sp,12
jr $ra
addi $sp, $sp, 0
j endif4
else4:
addi $8, $sp, 8
lw $2, 0($8)
addi $sp, $sp,12
jr $ra
addi $sp, $sp, 0
endif4:
addi $sp, $sp, 0
addi $sp, $sp,12
jr $ra
.data
