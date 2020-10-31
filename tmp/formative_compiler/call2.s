.data
.globl de
de: .word 1
.text
.globl f
f:
add $2, $zero, $zero
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 3
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, de($8)
addi $2, $zero, 1
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
.text
.globl ffff
ffff:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $31, 0($sp)
jal f
nop
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
lw $2, de($zero)
addi $sp, $sp,4
jr $ra
addi $sp, $sp, 4
addi $sp, $sp,0
jr $ra
.data
