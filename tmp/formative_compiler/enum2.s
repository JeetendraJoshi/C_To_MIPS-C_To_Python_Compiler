.data
.globl vv
vv: .word 13
.globl yy
yy: .word 10
.text
.globl g
g:
lw $2, vv($zero)
addi $sp, $sp, -4
sw $2, 0($sp)
lw $2, yy($zero)
lw $9, 0($sp)
addi $sp, $sp, 4
addu $2 , $9, $2
addi $sp, $sp,0
jr $ra
addi $sp, $sp, 0
addi $sp, $sp,0
jr $ra
.data
