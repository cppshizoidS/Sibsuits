.text
.globl main
main:
li $v0, 5
syscall
move $t0, $v0
li $v0, 5
syscall
move $t1, $v0
li $t2, 10
li $t3, 0
move $t7, $t0
li $t8, 1
li $t4, 1

loop:
beqz $t0, end
divu $t7, $t2
mflo $t7
addi $t8, $t8, 1
bgt	$t7, $zero, loop

num:
sub $t1, $t8, $t1

loop1:
beqz $t0, end
divu $t0, $t2
mflo $t0
mfhi $t5
addi $t3, $t3, 1
beq $t3, $t1, loop
mul $t5, $t5, $t4
mul $t4, $t4, $t2
add $t6, $t6, $t5
bgt	$t0, $zero, loop1

end:
li $v0, 1
move $a0, $t6
syscall

li $v0, 10
syscall
