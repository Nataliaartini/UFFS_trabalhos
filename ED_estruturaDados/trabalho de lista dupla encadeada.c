#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

struct estudante{
    char matricula [10];
    char nome [40];
    Data nascimento;
    double notas;
    struct estudante *prev, *next;
};
typedef struct estudante Estudante;

struct pontas{
	Estudante *primeiro;
	Estudante *ultimo;	
};
typedef struct pontas Pontas;

void iniciar (Pontas *p){
	p->primeiro=NULL;
	p->ultimo=NULL;
}

void incluiEstudante(Pontas *a){
	Estudante *i;
    i = (Estudante *)malloc(sizeof(Estudante));
    scanf("%s", i->matricula);
    scanf("%s", i->nome);
    scanf("%d/%d/%d", &i->nascimento.dia,&i->nascimento.mes, &i->nascimento.ano);
    scanf("%lf", &i->notas);
    i->prev = NULL;
    i->next = NULL;

    if(a->primeiro == NULL){
        a->primeiro = i;
        a->ultimo = i;
    }
    else{
    	a->ultimo->next = i; 
		i->prev = a->ultimo; 
		a->ultimo = i;
    }
}

void deleta(Pontas *a){
	Estudante *p = a->primeiro;
	char matricula1 [10];
	int retorno;
	scanf("%s", &matricula1);
	Estudante *aux;
	while (p!=NULL){
		retorno = strcmp(matricula1, p->matricula);
		if (!retorno){
			aux = p;
			if (p->prev != NULL){
				p->prev->next = p->next;
			}
			else {
				a->primeiro = p->next;
			}
			if (p->next != NULL){
				p->next->prev = p->prev;
			}
			else{
				a->ultimo = p->prev;
			}
			p = p->next;
			free(aux);
		}
		else{
			p = p->next;
		}
	}
}

void imprimeInverso (Estudante *p){
	if (p == NULL) return;
	imprimeInverso (p->next);
	printf("%s\n%s\n%d/%d/%d\n%.2lf\n", p->matricula, p->nome, p->nascimento.dia, p->nascimento.mes, p->nascimento.ano, p->notas);
}

void imprimeEstudante(Estudante *p){
	if (p == NULL) return;
	printf("%s\n%s\n%d/%d/%d\n%.2lf\n", p->matricula, p->nome, p->nascimento.dia, p->nascimento.mes, p->nascimento.ano, p->notas);
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
  Estudante *p, *anterior, *proximo;
  for (p = first ; p!=NULL; p=p->next){
    anterior=p;  
    printf("*");
    free(anterior);
  }
  printf("\n");

}

int main(void) {
    int opcao;
    Pontas *a =  (Pontas *)malloc(sizeof(Pontas));
    iniciar(a);
    while(1){
        scanf("%d", &opcao);
	
        if(opcao == 1){
           incluiEstudante(a);
        }
        else if (opcao == 2){
        	if (a->primeiro == NULL){
                printf("Lista Vazia!\n");
			} else {
				deleta(a);
			}
        }
        else if (opcao == 3){
            if (a->primeiro == NULL){
                printf("Lista Vazia!\n");
			} else {
        		imprimeEstudante(a->primeiro);				
			}
        }
        else if (opcao == 4){
  			imprimeInverso(a->primeiro);
            if (a->primeiro == NULL){
                printf("Lista Vazia!\n");          
            }
        }
        else if (opcao == 5){
            printf("%d\n", num_elementos(a->primeiro));
        }
        else if (opcao == 0){
            freeM(a->primeiro);
            free(a);
            break;
        
        }
    }
    return 0;
}
