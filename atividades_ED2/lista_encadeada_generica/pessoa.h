#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>

typedef struct{
	char nome[100];
	float peso;
	float altura;
	int idade;
}Pessoa;

void print_Pessoa(Object object){
	Pessoa* pessoa = object->item;
	printf("Nome: %s\n",pessoa->nome);
	printf("Idade: %d\n",pessoa->idade);
	printf("Altura: %.2f\n",pessoa->altura);
	printf("Peso: %.2f\n\n",pessoa->peso);
}

Object search_Pessoa(List lst){
	Object head = lst->head;
	while(head){
		if(head->type!=PESSOA){
			head=head->next; 
			continue;
		}
		head=head->next;
	}
	return NULL;
}

Object new_Pessoa(char* nome,int idade,float altura,float peso){
	Pessoa* newPessoa= pointer(Pessoa);
	strcpy(newPessoa->nome,nome);
	newPessoa->idade=idade;
	newPessoa->altura=altura;
	newPessoa->peso=peso;
	
	Object novo = new(Object);
	novo->print=print_Pessoa;
	novo->item=newPessoa;
	novo->type=PESSOA;
	return novo;
}

#endif
