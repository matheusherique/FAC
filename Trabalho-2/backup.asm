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
	la $a0, modulo_nao_primo	
	syscall
	j exit
		
calc_inverso:
	add $t0, $a1, $zero
	add $t7, $zero, $zero
	loop2:
		addi $t7, $t7, 1
		mult $t0, $t7
		mflo $t5
		div $t5, $t1
		mfhi $t6
		beq $t6, 1, imprime_saida
		j loop2
		
imprime_saida:
	li $v0, 4
	la $a0, inverso_multiplicativo
	syscall
	li $v0, 1
	move $a0, $t7
	syscall
	
exit:
	
	
# le_inteiro, que lerá um primo do console de entrada;
# eh_primo, que testará se o inteiro indicado é, de fato, um número primo;
# calc_inverso, que calculará o inverso multiplicativo;
# imprime_erro, função que imprimirá o erro;
# imprime_saida, função que imprimirá o resultado bem sucedido
