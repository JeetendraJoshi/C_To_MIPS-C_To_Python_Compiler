.data
.globl a
a: .word 3
.text
.globl ffff
ffff:
lw $2, a($zero)
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, a($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
multu $2, $9
mflo $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
lw $9, 0($sp)
addi $sp, $sp, 4
divu $9, $2
mflo $2
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
