		.data
vetor1:		.word	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
resultado:	.asciz "\nDigite o tamanho da matriz: "
separador:	.asciz "  "
linebreak:	.asciz "\n"
		.text
	
	
main:
	li 	a7, 4
        la	a0, resultado #para printar bonitinho pedindo o tamanho da matriz
        ecall
        
	la	s0, vetor1
	li	a7, 5
	ecall
	mv	a3, a0
	mul	a4, a3, a3
	
	
Loop:
	rem	t1, t0, a3 #faz a divisao pelo tamanho da coluna da matriz
	beqz	t1, break  #se for igual a zero a divisao quebra a linha pra formar a matriz
	
printa:
        #printo o valor
    	li 	a7, 1
        lw	a0, 0(s0)
        ecall
        
        li 	a7, 4
        la	a0, separador #para printar bonitinho a matriz separada por espaços
        ecall
        
        addi	s0, s0, 4 #passa os bits da memória
        addi	t0, t0, 1 #acrescenta 1 ao contador do a7
        blt	t0, a4, Loop #enquanto for menor que o numero lido em a7 e guardado em a0 (pelo print tem que salvar em a3 pra nao perder) faz o loop
        j	fim
        
break:
	li 	a7, 4
        la	a0, linebreak #para printar bonitinho a matriz separada por espaços
        ecall
	j	printa
	
fim:
	li     a7, 10   # chamada de sistema para encerrar programa
    	ecall
        