.data
	input_message: .asciiz "String de entrada: "
	out_message: .asciiz "CRC32: "
	input: .byte 16
.text
	
main:
	jal le_string
	# beq $s0, 0x10010014, imprime_saida_vazia
	j calc_crc32
	j exit			# fim do programa

#le_string, que lerá uma string do console de entrada;
le_string:
	la $a0, input_message	# carrega string
	li $v0, 4
	syscall
	li $v0, 8
	la $a0, input 		#load byte space into address
	li $a1, 16		#alloc the byte space for string
        move $s0,$a0 		#save string to s0
        syscall
	jr $ra
	
#▪ calc_crc32, que calculará o crc32;
calc_crc32:
	#   int i, j;
	li $t0, 0     			# $t0 = i = 0
	addiu $s2,$zero, 0xFFFFFFFF      		# $s2 = crc = 0xFFFFFFFF
	addiu $s3,$zero, 0xEDB88320			# $s3 = CRC32 code generator
	loop_while:					#t1 = argumento, #t2 é o contador
		addu $t3, $s0, $t0		# $t3 = address of string[i]
	       	lbu  $t6, ($t3)             	# $t6 = message[i]
		#move $t4, $t6			# $t4 = byte = message[i];
		beq $t6, 10, imprime_saida      	# while (message[i] != 0)
		xor $s2, $s2, $t6
				# crc = crc ^ byte;
		li $t7, 8			# $t7 = j = 8
		loop_for:
			subi $t7, $t7, 1
			andi $t9, $s2, 1		# (crc & 1);
			subu $t1, $0, $t9		# mask = -(crc & 1);
			srl $t2, $s2, 1			# (crc >> 1)
			and $t1, $t1, $s3		# (0xEDB88320 & mask)
			xor $s2, $t2, $t1		# crc = (crc >> 1) ^ (0xEDB88320 & mask);
			bgt $t7, $zero, loop_for		# for (j = 7; j >= 0; j--)

		addi $t0, $t0, 1        		# $t0++, i = i + 1;
		j loop_while

		
imprime_saida:
	la $a0, out_message	# carrega string
	li $v0, 4
	syscall
	not $s4, $s2
	move $a0, $s4
	li $v0, 34
	syscall
	j exit
exit:
#unsigned int crc32b(unsigned char *message) {
#   int i, j;
#   unsigned int byte, crc, mask;

#   i = 0;
#   crc = 0xFFFFFFFF;
#   while (message[i] != 0) {
#      byte = message[i];            // Get next byte.
#      crc = crc ^ byte;
#      for (j = 7; j >= 0; j--) {    // Do eight times.
#         mask = -(crc & 1);
#         crc = (crc >> 1) ^ (0xEDB88320 & mask);
#      }
#      i = i + 1;
#   }
#   return ~crc;
#}