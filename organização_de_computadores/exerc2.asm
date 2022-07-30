	.data
vetor1:	.word	9, 8, 7, 6, 5, 4, 3, 2, 1
vetor2: .word	-10, 8, 11, 16, 15, -6, 22


	.text
	
main:
	la 	a0, vetor1
	li 	a1, 8
	li 	a2, 0
	jal	shift
	
	la 	a0, vetor2
	li 	a1, 5
	li 	a2, 1
	jal	shift

	li 	a7, 10   # chamada de sistema para encerrar programa
	ecall 
	
#####################################
# Implemente a função abaixo	

shift:
	addi	s9, zero, 1
	addi 	t0, zero, 4 	# salva o valor 4 em t0
 	mul 	t1, a1, t0  	# multiplica 4 vezes o indice 
	add 	a3, t1, a0 	# soma o valor de t1 ao endereço incial para obter o endereço onde se encontra o indice passado como parametro
	lw  	s0, (a3) 	# salva em s0 o valor que estava no indice 
	
	mul 	t1, a2, t0   	# multiplica 4 vezes o indice 
	add 	t2, t1, a0 	# soma o valor de t1 ao endereço incial para obter o endereço onde se encontra o indice passado como parametro
	lw 	s1, (t2) 	# salva em s1 o valor que estava no indice 
	
	sw 	s0, (t2) 	# salva o valor do primeiro indice no lugar do segundo
	
	sub	a1, a1, a2 	#calcula quantas vezes tem que repetir
	
while:
	beqz 	a1, fim
	add 	t2, t2, t0 	# soma 4 ao valor do endereço
	lw  	s0, (t2)
	sw 	s1, (t2)
	add	s1, zero, s0
	sub 	a1, a1, s9
	j	while
	
fim:	
	ret
		
