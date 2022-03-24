#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

struct estudante{
    int matricula;
    char nome [40];
    Data nascimento;
    float media_notas;
    struct estudante *next;
};
typedef struct estudante Estudante;

Estudante *incluiEstudante(Estudante *p){
	Estudante *i, *aux;
    i = (Estudante *)malloc(sizeof(Estudante));
    scanf("%d", &i->matricula);
    scanf("%s", i->nome);
    scanf("%d/%d/%d", &i->nascimento.dia,&i->nascimento.mes, &i->nascimento.ano);
    scanf("%f", &i->media_notas);
    i->next = NULL;

    if(p == NULL)
    {
        p = i;
        return p;
    }
    else
    {
        for (aux=p;aux->next!=NULL;aux=aux->next); 
    	aux->next=i;
    	return p;
    }
}

Estudante *deleta(Estudante *p)
{
	int matricula;
	scanf("%d\n", &matricula);

	Estudante *ant, *atual = p;

	while (atual!=NULL){
		if (p->matricula==matricula){
			atual=p->next;
			free(p);
			p=ant=atual;
		} else {
			if (atual->matricula==matricula){
				ant->next=atual->next;
				free(atual);
				atual=ant->next;
			} else {
				ant=atual;
				atual=atual->next;
			}	
		}
	}
	
	return p;
}

void imprimeInverso (Estudante *p){
	if (p == NULL) return;
	imprimeInverso (p->next);
	printf("%d\n%s\n%d/%d/%d\n%.2lf\n", p->matricula, p->nome, p->nascimento.dia, p->nascimento.mes, p->nascimento.ano, p->media_notas);
}

void imprimeEstudante(Estudante *p){
	if (p == NULL) return;
	printf("%d\n%s\n%d/%d/%d\n%.2lf\n", p->matricula, p->nome, p->nascimento.dia, p->nascimento.mes, p->nascimento.ano, p->media_notas);
	imprimeEstudante(p->next);
}

int num_elementos(Estudante *p){
    int i=0;
	while (p!=NULL){
		i++;
		p = p->next;
	}
	return i;
}


void freeM(Estudante *first){
  Estudante *p, *anterior;
  for (p = first ; p!=NULL; p=p->next){
    anterior=p;  
    printf("-");
    free(anterior);
  }
  printf("\n");

}

int main(void) {
    int opcao;
    Estudante *first = NULL;
    while(1){
        scanf("%d", &opcao);
	
        if(opcao == 1){
           first = incluiEstudante(first);
        }
        else if (opcao == 2){
        	if (first == NULL){
                printf("Lista Vazia!\n");
			} else {
				first = deleta(first);
			}
        }
        else if (opcao == 3){
            if (first == NULL){
                printf("Lista Vazia!\n");
			} else {
				imprimeEstudante(first);
			}
        }
        else if (opcao == 4){
  			imprimeInverso(first);
            if (first == NULL){
                printf("Lista Vazia!\n");          
            }
        }
        else if (opcao == 5){
            printf("%d\n", num_elementos(first));
        }
        else if (opcao == 0){
            freeM(first);
            break;
        
        }
    }
    return 0;
}
