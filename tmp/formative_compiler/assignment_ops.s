.data
.globl g
g: .word 10
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
addi $2, $zero, 2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
addi $8, $sp, 0
lw $2, 0($8)
addi $2, $sp, 0
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
addi $2, $sp, 12
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 4
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 16
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 12
lw $2, 0($8)
addi $2, $sp, 12
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 7
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 8
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
lw $8, 0($sp)
addi $sp, $sp, 4
addu $2, $2, $8
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
add $2, $zero, $zero
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, g($zero)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 10
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, g($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 28
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
lw $8, 0($sp)
addi $sp, $sp, 4
sub $2, $8, $2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, g($8)
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 16
lw $2, 0($8)
addi $2, $sp, 16
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, 0($2)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 8
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 24
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
multu $2, $9
mflo $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 28
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
divu $9, $2
mflo $2
addi $sp, $sp, -4
sw $2, 0($sp)
addi $8, $sp, 24
lw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
xor $2, $2, $9
lw $8, 0($sp)
addi $sp, $sp, 4
addu $2, $2, $8
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
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
lw $2, g($zero)
addi $sp, $sp, -4
sw $2, 0($sp)
addi $2, $zero, 3
lw $9, 0($sp)
addi $sp, $sp, 4
divu $9, $2
mfhi $2
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
lw $8, 0($sp)
addi $sp, $sp, 4
sw $2, 0($8)
addi $8, $sp, 8
lw $2, 0($8)
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
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, g($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp,12
jr $ra
addi $sp, $sp, 12
addi $sp, $sp,0
jr $ra
.data
