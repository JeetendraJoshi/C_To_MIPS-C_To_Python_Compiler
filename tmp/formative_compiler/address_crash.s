.data
.globl a
a: .space 4
.text
.globl ffff
ffff:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
add $2, $zero, $zero
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, a($8)
lw $2, a($zero)
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
