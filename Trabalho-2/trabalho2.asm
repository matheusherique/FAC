.data

	inverso_multiplicativo: .asciiz "O inverso multiplicativo é "
	modulo_nao_primo: .asciiz "O modulo nao eh primo"
.text
main:
	jal le_inteiro
	j eh_primo

le_inteiro:
	li $v0, 5
	syscall
	move $a0, $v0	# Le o Numero 1
	li $v0, 5
	syscall
	move $a1, $v0	# Le o Numero 2
	jr $ra

eh_primo:
	add $t1, $a0, $zero     # $t1 = Modulo
	addi $t2, $zero, 1      # $t2 = 1
	loop:					#t1 = argumento, #t2 é o contador
		addi $t2, $t2, 1        	# $t2++, o contador começa com o primeiro primo, 2
		beq $t2, $t1, calc_inverso      # if $t2 == $t1, return
		div $t3, $t1, $t2       	# $t3 = modulo / contador
		mfhi $t4                	# $t4 = resto
		beq $t4, $zero, imprime_erro	
		j loop
imprime_erro:
	li $v0, 4			# imprime string
	la $a0, modulo_nao_primo	# imprime não é primo
	syscall				# chamada de função
	j exit				# pula para a saida
		
calc_inverso:
	add $t0, $a1, $zero		# Segundo numero
	add $t7, $zero, $zero		# Contador
	loop2:
		addi $t7, $t7, 1	# inicia com 1 o X
		mult $t0, $t7		# A * X
		mflo $t5		# $t5 = A * X
		div $t5, $t1		# $t5 / modulo
		mfhi $t6		# resto da divisão de $t5 / modulo
		beq $t6, 1, imprime_saida	# if ($t5 % $t1 == 1) imprime saida
		j loop2				# se não, repete
		
imprime_saida:
	li $v0, 4				# imprime uma string
	la $a0, inverso_multiplicativo		# Imprime inverso multiplicativo é: 
	syscall
	li $v0, 1				# imprime um inteiro
	move $a0, $t7				# imprime o inverso multiplicativo
	syscall
	
exit:
	