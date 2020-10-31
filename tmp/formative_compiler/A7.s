.data
.globl x
x: .word 7
.text
.globl ffff
ffff:
lw $2, x($zero)
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
