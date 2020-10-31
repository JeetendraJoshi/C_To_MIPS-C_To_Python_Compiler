.data
.text
.globl f
f:
addi $2, $zero, 0
beq $2, $zero, else1
addi $2, $zero, 11
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
j endif1
else1:
addi $2, $zero, 10
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
endif1:
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
