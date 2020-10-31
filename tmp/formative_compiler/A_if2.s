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
beq $2, $zero, else1
addi $2, $zero, 144
addi $sp, $sp,4
jr $ra
j endif1
else1:
addi $2, $zero, 1
addi $sp, $sp,4
jr $ra
endif1:
addi $2, $zero, 100
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
