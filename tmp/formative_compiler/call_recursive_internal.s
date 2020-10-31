.data
.text
.globl f
f:
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
bne $10, $9, condequals1
addi $2, $zero, 1
condequals1:
beq $2, $zero, if2
addi $2, $zero, 0
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 0
if2:
addi $8, $sp, 0
lw $2, 0($8)
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
jal f
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
addi $sp, $sp,4
jr $ra
.data
