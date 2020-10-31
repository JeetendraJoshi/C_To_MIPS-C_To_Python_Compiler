.data
.globl e
e: .word 0
.globl r
r: .word 1
.globl t
t: .word 2
.text
.globl ffff
ffff:
.globl RED
RED: .word 0
.globl GREEN
GREEN: .word 1
.globl BLUE
BLUE: .word 2
lw $2, BLUE($zero)
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, RED($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, GREEN($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, e($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, r($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, t($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
