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
beq $2, $zero, if1
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,4
jr $ra
if1:
addi $2, $zero, 10
subu $2, $0, $2
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
