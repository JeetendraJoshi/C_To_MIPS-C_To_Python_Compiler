.data
.text
.globl ffff
ffff:
addi $2, $zero, 0
beq $2, $zero, if1
addi $2, $zero, 5
beq $2, $zero, else2
addi $2, $zero, 111
addi $sp, $sp,0
jr $ra
j endif2
else2:
addi $2, $zero, 1212
addi $sp, $sp,0
jr $ra
endif2:
if1:
addi $2, $zero, 1223
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
