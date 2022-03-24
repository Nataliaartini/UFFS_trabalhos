#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista {
	char item [60];	
	struct lista *proximo;
} Lista;

typedef struct {
	Lista *topo;
} Pilha;

Pilha *inicializaPilha(){
	Pilha *pilha;
	pilha = malloc(sizeof(Pilha));
	pilha->topo = NULL;
	return pilha;
}

void insereElemento(char novoItem[60], Pilha *pilha){
	Lista *i;
	i = malloc(sizeof(Lista));
	strcpy(i->item, novoItem);
	i->proximo = pilha->topo;
	pilha->topo = i;
}

void apaga(Pilha *pilha) {
	Lista *i;
	i = pilha->topo;
	pilha->topo= pilha->topo->proximo;
	free(i);
}

int pilhavazia(Pilha *pilha){
	return (pilha->topo == NULL);
}

void freeM(Pilha *pilha){
	Lista *top, *proximo;
	if (pilha->topo == NULL){
    	printf("!");
    	return ;
	}
	for (top = pilha->topo; top!=NULL; top=top->proximo) {
    	printf("@");
    	free(pilha);
	}
  }

int main (){
	Pilha *pilha = NULL;
	pilha= inicializaPilha();
	char i [60];

	while(1){
		scanf("%s", i);
		if (!strcmp(i,"B")){
			if (pilhavazia(pilha)){
				printf("Vazio\n");
			}
			else {
				printf("%s\n",pilha->topo);
				apaga(pilha);
			}
		} else if (!strcmp(i, "E")){
			freeM(pilha);
			break;
		} else {
			insereElemento (i,pilha);
			
		}
	}
	return 0;
}
