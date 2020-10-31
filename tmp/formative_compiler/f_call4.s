.data
.text
.globl f
f:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $4, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $5, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $6, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
sw $7, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 0
addi $9, $fp, -20
lw $2, 0($9)
sw $2, 0($8)
addi $8, $sp, 16
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 16
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 8
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 4
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp,20
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,20
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
addi $2, $zero, 1
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 7
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 8
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 3
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 4
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 16
lw $2, 0($8)
addi $2, $sp, 16
addi $sp, $sp, -4
sw $2, 0($sp)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
sw $31, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 32
lw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 32
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $8, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 32
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $8, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 32
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $8, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 32
lw $2, 0($8)
lw $8, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $8, 0
addi $8, $sp, 16
sw $2, 0($8)
addi $8, $sp, 16
lw $4, 0($8)
addi $8, $sp, 12
lw $5, 0($8)
addi $8, $sp, 8
lw $6, 0($8)
addi $8, $sp, 4
lw $7, 0($8)
jal f
nop
addi $sp, $sp, 4
addi $sp, $sp, 4
addi $sp, $sp, 4
addi $sp, $sp, 4
addi $sp, $sp, 4
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 16
lw $2, 0($8)
addi $sp, $sp,20
jr $ra
addi $sp, $sp, 20
addi $sp, $sp,0
jr $ra
.data
