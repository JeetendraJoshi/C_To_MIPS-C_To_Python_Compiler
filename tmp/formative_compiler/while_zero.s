.data
.text
.globl f
f:
while1:
addi $2, $zero, 0
beq $2, $zero, whileend1
j while1
whileend1:
addi $2, $zero, 19937
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
