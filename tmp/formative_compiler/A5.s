.data
.text
.globl ffff
ffff:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $2, $zero, 0
sll $2, $2, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 8
lw $2, 0($8)
addi $2, $sp, 8
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2, $2, $9
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 5
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $2, $zero, 0
sll $2, $2, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 8
lw $2, 0($8)
addi $2, $sp, 8
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2, $2, $9
lw $2, 0($2)
addi $sp, $sp,8
jr $ra
addi $sp, $sp, 8
addi $sp, $sp,0
jr $ra
.data
