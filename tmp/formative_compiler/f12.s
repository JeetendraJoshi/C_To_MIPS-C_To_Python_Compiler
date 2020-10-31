.data
.text
.globl ffff
ffff:
addi $2, $zero, 1
beq $2, $zero, if1
addi $2, $zero, 10
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
if1:
addi $2, $zero, 11
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
