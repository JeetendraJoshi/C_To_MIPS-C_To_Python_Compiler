.data
.space 4
.text
.globl r1
r1:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $4, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 0
lw $9, 0($sp)
addi $sp, $sp, 4
addu $10, $zero, $2 
add $2, $0, $0
bne $10, $9, condequals2
addi $2, $zero, 1
condequals2:
beq $2, $zero, else1
addi $2, $zero, 1
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
j endif1
else1:
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
sw $31, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
addi $8, $sp, 0
sw $2, 0($8)
addi $8, $sp, 0
lw $4, 0($8)
jal r2
nop
addi $sp, $sp, 4
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
sw $31, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 16
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
addi $8, $sp, 0
sw $2, 0($8)
addi $8, $sp, 0
lw $4, 0($8)
jal r2
nop
addi $sp, $sp, 4
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
endif1:
addi $sp, $sp, 0
addi $sp, $sp,4
jr $ra
.data
