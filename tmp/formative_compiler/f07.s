.data
.globl x
x: .space 4
.text
.globl ffff
ffff:
add $2, $zero, $zero
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, x($8)
lw $2, x($zero)
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
