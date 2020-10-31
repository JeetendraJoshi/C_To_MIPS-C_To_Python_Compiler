.data
.text
.globl ffff
ffff:
addi $2, $zero, 1
beq $2, $zero, if1
addi $2, $zero, 2
beq $2, $zero, else2
addi $2, $zero, 1111
addi $sp, $sp,0
jr $ra
j endif2
else2:
addi $2, $zero, 2222
addi $sp, $sp,0
jr $ra
endif2:
if1:
addi $2, $zero, 33
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
