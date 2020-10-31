.data
.text
.globl d
d:
addi $2, $zero, 444
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
.text
.globl h
h:
addi $2, $zero, 222
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
sw $fp, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $31, 0($sp)
jal d
nop
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $31, 0($sp)
jal h
nop
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
