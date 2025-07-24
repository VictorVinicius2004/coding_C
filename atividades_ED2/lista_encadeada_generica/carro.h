#ifndef CARRO_H
#define CARRO_H

#include <string.h>

typedef struct{
	char nome[100];
	char modelo[100];
	int ano;
}Carro;

void print_Carro(Object object){
	Carro* carro = object->item;
	printf("Nome: %s\n",carro->nome);
	printf("Modelo: %s\n",carro->modelo);
	printf("Ano: %d\n\n",carro->ano);
}

void init_Carro(Object object){
	object->print=print_Carro;
}

Object new_Carro(char* nome,char* modelo,int ano){
	Carro* newCarro = pointer(Carro);
	strcpy(newCarro->nome,nome);
	strcpy(newCarro->modelo,modelo);
	newCarro->ano=ano;
	
	Object novo = new(Object);
	novo->item=newCarro;
	init_Carro(novo);
	return novo;
}

#endif
