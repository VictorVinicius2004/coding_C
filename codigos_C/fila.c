#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
	char nome[50];
	int idade;
	struct Pessoa* next;
}Pessoa;

typedef struct{
	Pessoa* head;
	Pessoa* tail;
}Fila;

void espera_enter(char* msg){
	printf("%s\nPressione ENTER para continuar\n",msg);
	setbuf(stdin,NULL);
	getchar();
}

Pessoa* enqueue(Pessoa* tail){
	Pessoa* new = malloc(sizeof(Pessoa));
	printf("Nome: ");
	scanf(" %s", new->nome);
	printf("Idade: ");
	scanf(" %d",&new->idade);
	new->next=NULL;
	if(tail)		
		tail->next=new;
	return new;
}

Pessoa* dequeue(Pessoa* head){
	Pessoa* newHead = head->next;
	free(head);
	return newHead;
}

void listar(Pessoa* head){
	while(head){
		printf("Nome: %s \nIdade: %d\n\n",head->nome,head->idade);
		head = head->next;
	}
	espera_enter("");
}

void excluirFila(Pessoa* head){
	while(head)
		head = dequeue(head);
}

int interface(){
	printf("1) Enqueue\n");
	printf("2) Dequeue\n");
	printf("3) Listar\n");
	printf("4) Sair\n");
	int escolha;
	scanf(" %d", &escolha);
	return escolha;
}

int main(){
	Fila fila;
	fila.head = fila.tail = NULL;
	
	do{
		system("clear");
		
		switch(interface()){
			case 1:	fila.tail = enqueue(fila.tail);
					if(!fila.head)
						fila.head = fila.tail;
					break;
			case 2:	fila.head = dequeue(fila.head);
					break;
			case 3:	listar(fila.head);
					break;
			case 4:	excluirFila(fila.head);
					return 0;
		}
	}while(1);
}

