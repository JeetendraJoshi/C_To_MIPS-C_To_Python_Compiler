.data
.text
.globl f
f:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 5678
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1234
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, 4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
