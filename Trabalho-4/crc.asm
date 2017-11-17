.data
	input_message: .asciiz "String de entrada: "
	input: .byte 16
	crc: .ascii "0xFFFFFFFF"
	magic: .ascii "0xEDB88320"
.text
	
main:
	jal le_string
	j calc_crc32
	j exit			# fim do programa

#le_string, que lerá uma string do console de entrada;
le_string:
	la $a0, input_message	# carrega string
	li $v0, 4
	syscall
	li $v0, 8
	la $a0, input 		#load byte space into address
	li $a1, 16		# allot the byte space for string
        move $s0,$a0 		#save string to s0
        syscall
	jr $ra
	
#▪ calc_crc32, que calculará o crc32;
calc_crc32:
	#   int i, j;
	li $t0, 0     			# $t0 = i = 0
	la $s2, crc      		# $s2 = crc = 0xFFFFFFFF
	la $s3, magic			# $s3 = byte 
	loop:					#t1 = argumento, #t2 é o contador
		addu $t3, $s0, $t0		# $t3 = address of string[i]
	       	lbu  $t5, 0($t3)             	# $t5 = elements[i]
		move $t4, $t5			# $t4 = byte = message[i];
		xor $s2, $s2, $t4		# crc = crc ^ byte;
		li $t7, 8			# $t7 = j
		loop_for:
			subiu $t7, $t7, 1
			andi $t9, $s2, 1		# (crc & 1);
			subu $t1, $0, $t9		# mask = -(crc & 1);
			srl $t2, $s2, 1			# (crc >> 1)
			and $t1, $t1, $s3		# (0xEDB88320 & mask)
			xor $s2, $t2, $t1		# crc = (crc >> 1) ^ (0xEDB88320 & mask);
			bgtu $t7, 0, loop_for		# for (j = 7; j >= 0; j--)
		bleu $t5, 10, imprime_saida      	# while (message[i] != 0)
		addiu $t0, $t0, 1        		# $t0++, i = i + 1;
		j loop
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





#▪ imprime_saida,
imprime_saida:
	not $s4, $s2
	move $a0, $s4
	li $v0, 34
	syscall
	j exit
exit:
	