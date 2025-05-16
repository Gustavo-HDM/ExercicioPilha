#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TAM 5

int resp;

//	ESTRUTURA PARA UMA PILHA
typedef struct {
	int dados[TAM];
	int topo;
} Pilha;

//	TESTA SE A PILHA ESTÁ VAZIA
bool isEmpty(Pilha *p) {
	return p->topo == -1;
}

//	INICIALIZA UMA PILHA DEFININDO O TOPO COMO -1
void inicializar(Pilha *p) {
	p->topo = -1;
}

//	ADICIONA UM VALOR AO TOPO DA PILHA
void push(Pilha *p, int data) {
	if(p->topo == TAM-1) {
		printf("Pilha Cheia!\n");
		return;
	}
	p->topo++;
	p->dados[p->topo] = data;
}

//	IMPRIME TODOS OS VALORES DA PILHA
void imprimePilha(Pilha *p){
	if(isEmpty(p)) {
		printf("Pilha Vazia!\n");
		return;
	}
	printf("Pilha: ");
	int i;
	for(i = 0; i <= p->topo; i++) {
		printf("%d -> ", p->dados[i]);
	}
	printf("Topo");
}

//	TRAZ O VALOR DO TOPO DA PILHA SEM TIRAR ELE
void top(Pilha *p) {
	if(isEmpty(p)) {
		printf("Pilha Vazia!\n");
		return;
	}
	printf("%d", p->dados[p->topo]);
}

//	TRAZ O VALOR DO TOPO DA PILHA TIRANDO ELE EM SEGUIDA
int pop(Pilha *p) {
	if(isEmpty(p)) {
		printf("\nPilha Vazia!\n");
		return 0;
	}
	int temp = p->dados[p->topo];
	p->topo--;
	return temp;
}

//	TELA DE MENU
menu(){
	printf("\nMenu:\n");
	printf("[1] Adicionar valor a pilha\n");
	printf("[2] Retirar valor a pilha\n");
	printf("[3] Mostrar pilha\n");
	printf("[4] Sair\n");
	scanf("%d", &resp);
 }

main() {
	
	Pilha pilha;
	inicializar(&pilha);
	
	menu();
	
	do {
		switch (resp) {
			case 1: {
				int valor;
				printf("\nAdicione um valor: ");
				scanf("%d", &valor);
				push(&pilha, valor);
				menu();
				break;
			}
			case 2: {
				if(isEmpty(&pilha)) {
					printf("\nPilha Vazia!\n");
					menu();
				} else {
					printf("\nValor retirado: %d\n", pop(&pilha));
					menu();
				}
				break;
			}
		
			case 3: {
				imprimePilha(&pilha);
				menu();
				break;
			}
			
			case 4: {
				printf("\nSaindo do sistema...");
				break;
			}
			
			default: {
				printf("\nResposta invalida, tente novamente...\n");
				menu();
				break;
			}
		} 
	} while (resp != 4);
}
