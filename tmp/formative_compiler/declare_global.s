.data
.globl x
x: .space 32
.space 4
.text
.globl f
f:
addi $2, $zero, 11
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
