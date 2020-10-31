.data
.globl RED
RED: .word 0
.globl GREEN
GREEN: .word 1
.text
.globl ffff
ffff:
.globl RED
RED: .word 0
.globl GREEN
GREEN: .word 1
.globl BLUE
BLUE: .word 2
.globl G
G: .word 3
.globl K
K: .word 4
.globl L
L: .word 5
.globl O
O: .word 6
.globl P
P: .word 7
.globl t
t: .word 0
.globl u
u: .word 1
.globl i
i: .word 2
lw $2, RED($zero)
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, GREEN($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, BLUE($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, L($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, O($zero)
nor $2, $2, $2
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, P($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, t($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, u($zero)
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, i($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
multu $2, $9
mflo $2
lw $9, 0($sp)
addi $sp, $sp, 4
subu $2 , $9, $2
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
