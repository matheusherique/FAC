 .globl main
.text
main:
li $v0, 4               # print welcome message
la $a0, welcome
syscall

la $a0, prompt          # prompt for user input
syscall         

#receive input
li $v0, 5               
syscall
add $s1, $v0, $zero     # $s1 = user input

beq $s1, $zero, quit    # if input == zero, quit

#print 1st prime
li $v0, 1               # print int
addi $a0, $zero, 2      # argument = 2
syscall

li $v0, 4               # print new line
la $a0, line
syscall

addi $s2, $s2, 1        # $s2 = 1 (prime counter)
addi $a2, $zero, 2      # $a2 = 2

loop:
addi $a2, $a2, 1        # argument++
#beq $s2, $s1, quit     # if prime counter == input, quit
jal test_prime
beq $v1, $zero, loop    # if test_prime returns false, repeat
addi $s2, $s2, 1        # else $s2++
#print next prime
li $v0, 1               # print int
add $a0, $a2, $zero     # argument = $a2
syscall

li $v0, 4               # print new line
la $a0, line
syscall

beq $s2, $s1, quit      # if prime counter == input, quit
j loop

test_prime:
	add $t1, $a2, $zero     # $t1 = argument
	addi $t2, $zero, 1      # $t2 = 1
	loop2:		#t1 = argumento, #t2 é o 
		addi $t2, $t2, 1        # $t2++
		beq $t2, $t1, true      # if $t2 == $t1, return
		div $t3, $t1, $t2       # $t3 = $t1 / $t2
		mfhi $t4                # $t4 = remainder
		beq $t4, $zero, false
		j loop2
	false:
		li $v1, 0       # $v1 = false
		jr $ra
	true:
	li $v1, 1       # $v1 = true
	jr $ra

quit:
# program exit
li $v0, 10
syscall


.data
welcome:    .asciiz "Prime Numbers\n"   
prompt:     .asciiz "How many primes? "
line:       .asciiz "\n"