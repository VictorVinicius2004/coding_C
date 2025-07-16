#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
	char nome[50];
	int idade;
	struct Pessoa *next;
}Pessoa;

void espera_enter(char *msg){
	printf("%s\nAperte ENTER para continuar\n",msg);
	setbuf(stdin,NULL);
	getchar();
}

Pessoa *push(Pessoa *top){
	int idade;
	char nome[50];
	printf("Nome: ");
	scanf(" %[^\n]s",nome);
	printf("Idade: ");
	scanf(" %d", &idade);

	Pessoa *nova_pessoa = malloc(sizeof(Pessoa));
	nova_pessoa->idade=idade;
	strcpy(nova_pessoa->nome,nome);
	nova_pessoa->next=top;
	return nova_pessoa;
}

void listar(Pessoa *top){
	while(top){
		printf("Nome: %s\n", top->nome);
		printf("Idade: %02d\n\n",top->idade);
		top = top->next;
	}
}

Pessoa *pop(Pessoa *top){
	if(!top){
		espera_enter("Pilha vazia");
		return top;
	}
	Pessoa *novo_topo = top->next;
	free(top);
	return novo_topo; 
}

void excluirPilha(Pessoa* topo){
	while(topo)
		topo = pop(topo);
}

int interface(){
	printf("1) Push\n");
	printf("2) Pop\n");
	printf("3) Listar\n");
	printf("4) Sair\n");
	
	int escolha;
	scanf(" %d", &escolha);
	return escolha;
}

int main(){
	Pessoa *top = NULL;
	do{
		system("clear");
		switch(interface()){
			case 1:	top = push(top);
					break;
			case 2:	top = pop(top);
					break;
			case 3:	listar(top);
					espera_enter("");
					break;
			case 4:	excluirPilha(top);
					return 0;
		}
		
	}while(1);
}

