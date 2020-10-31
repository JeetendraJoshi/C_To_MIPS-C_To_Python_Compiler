.data
.text
.globl foo
foo:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 12
lw $2, 0($8)
addi $2, $sp, 12
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 123
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 8
lw $2, 0($8)
addi $2, $sp, 8
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2322
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 3233
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 5721
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp,16
jr $ra
addi $sp, $sp, 16
addi $sp, $sp,0
jr $ra
.data
.text
.globl ffff
ffff:
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $8, $sp, 12
lw $2, 0($8)
addi $2, $sp, 12
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 122
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 8
lw $2, 0($8)
addi $2, $sp, 8
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2222
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 4
lw $2, 0($8)
addi $2, $sp, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 322
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 22
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $31, 0($sp)
jal foo
nop
lw $31, 0($sp)
addi $sp, $sp, 4
lw $fp, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp,16
jr $ra
addi $sp, $sp, 16
addi $sp, $sp,0
jr $ra
.data
