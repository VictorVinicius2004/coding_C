#ifndef INTERFACES_H
#define INTERFACES_H

#include <stdio.h>
#include <string.h>
#include "list.h"
#include "pessoa.h"
#include "casa.h"

void esperaEnter(char* msg){
	printf("%s\nAperte ENTER para continuar\n",msg);
	setbuf(stdin,NULL);
	getchar();
}

void cadastroPessoa(List lst){
	char nome[100];
	int idade;
	float altura, peso;
	printf("Nome(SAIR para cancelar): ");
	scanf(" %s",nome);
	if(!strcmp(nome,"SAIR")) return;
	printf("Idade: ");
	scanf(" %d",&idade);
	printf("Altura: ");
	scanf(" %f",&altura);
	printf("peso: ");
	scanf(" %f",&peso);
	
	int escolha;
	printf("\n1) push \n2)enqueue\n");
	do{
		scanf(" %d",&escolha);
	}while(escolha!=1 && escolha!=2);
	Object pessoa = new(Pessoa,nome,idade,altura,peso);
	if(escolha==1) lst->push(lst,pessoa);
	else lst->enqueue(lst,pessoa);
}

void cadastroCasa(List lst){
	char bairro[100], rua[100];
	int numero;
	printf("Bairro(SAIR para cancelar): ");
	scanf(" %s",bairro);
	if(!strcmp(bairro,"SAIR")) return;
	printf("Rua: ");
	scanf(" %s",rua);
	printf("Número: ");
	scanf(" %d",&numero);
	
	int escolha;
	printf("\n1) push \n2)enqueue\n");
	do{
		scanf(" %d",&escolha);
	}while(escolha!=1 && escolha!=2);
	if(escolha==1) lst->push(lst,new(Casa,bairro,rua,numero));
	else lst->enqueue(lst,new(Casa,bairro,rua,numero));
}

void interfaceDelete(List lst){
	int indice;
	printf("digite o índice do item a ser excluído\n");
	scanf(" %d",&indice);
	if(indice<lst->size)
		lst->del(lst,indice);
	else printf("posição inexistente\n");
	
}

void interfaceListar(List lst){
	printf("1) listar tudo\n");
	printf("2) listar pessoas\n");
	printf("3) listar casas\n");
	int escolha;
	scanf(" %d", &escolha);
	switch(escolha){
		case 1: lst->listar(lst,QUALQUER); break;
		case 2: lst->listar(lst, PESSOA); break;
		case 3: lst->listar(lst, CASA); break;
	}
}

int interface(){
	printf("1) adicionar pessoa\n");
	printf("2) adicionar casa\n");
	printf("3) listar\n");
	printf("4) Deletar topo\n");
	printf("5) deletar item escolhido\n");
	printf("6) clear\n");
	printf("0) sair\n");
	int escolha;
	scanf(" %d",&escolha);
	system("clear");
	return escolha;
}

#endif
