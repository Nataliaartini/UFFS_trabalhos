	.data
vetor1:	.word	9, 8, 7, 6, 5, 4, 3, 2, 1
vetor2: .word	-10, 8, 11, 16, 15, -6, 22
vetor3:	.word	0, 1, 2, 3, 4, 5, 6, 7 , 8, 9

	.text
	
main:
	la 	a0, vetor1
	li 	a1, 8
	jal	ordena
	
	la 	a0, vetor2
	li 	a1, 7
	jal	ordena

	la 	a0, vetor3
	li 	a1, 10
	jal	ordena

	li 	a7, 10   # chamada de sistema para encerrar programa
	ecall 
	
#####################################
# Implemente a função abaixo	
ordena:
	addi	t0, zero, 4 
	mul 	t1, a1, t0 	# salvando a posicao final do vetor
	add	t1, a0, t1
	add	a3, a0, t0
	
primeiro_for:
	blt	t1, a3, fim 	# pula pro fim se o vetor chegou no final
	lw	a4, (a3)	# salva o valor que esta na posição atual em a4
	add	t3, zero, a3	# salva endereço da poiscao atual
	
segundo_for:
	beq 	t3, a0, incremento	# anda até chegar na primeira posição
	sub	t2, t3, t0		# pega o endereco da posicao anterior
	lw	a5, (t2)
	bge	a4, a5, decremento
	sw 	a4, (t2)
	sw 	a5, (t3)
decremento:
	sub	t3, t3, t0
	j	segundo_for
incremento:
	add	a3, a3, t0
	j	primeiro_for
fim:
	ret
		
