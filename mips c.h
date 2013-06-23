.data
array_a: .word 0, 1, 2, 3, 4, 5, 6, 7
array_b: .word 8, 9, 10, 11, 12, 13, 14, 15
.text
main:  la	$t0, array_a
	la	$t1, array_b
	li	$t2, 8
	add	$t2, $zero, $zero
loop:
	lw	$t4, 0($t0)
	lw	$t5, 0($t1)
	add	$t3, $t3, $t4
	add	$t3, $t3, $t5
	addi	$t0, $t0, 4	
	addi	$t1, $t1, 4
	addi	$t2, $t2, -1
	bne	$t2, $zero, loop
	
	move	$a0, $t3
	li	$v0, 1
	syscall
	li 	$v0, 10
	syscall
	jr	$ra
