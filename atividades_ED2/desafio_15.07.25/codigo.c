#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "pessoa.h"
#include "produto.h"

void esperaEnter(char* msg){
	printf("%s \nAperte ENTER para continuar\n",msg);
	setbuf(stdin,NULL);
	getchar();
}

void cadastro_Pessoa(List lst){
	Pessoa p;
	printf("Digite o nome\n");
	scanf(" %99[^\n]s",p.nome);
	printf("Digite a idade\n");
	scanf(" %d",&p.idade);
	printf("Digite o peso\n");
	scanf(" %f",&p.peso);
	printf("Digite a altura\n");
	scanf(" %f",&p.altura);
	new(Pessoa,lst,p.nome,p.idade,p.peso,p.altura);
}

void cadastro_Produto(List lst){
	Produto p;
	printf("Digite o nome\n");
	scanf(" %99[^\n]s",p.nome);
	printf("Digite o preço\n");
	scanf(" %f",&p.preco);
	new(Produto,lst,p.nome,p.preco);
}

int interface(){
	printf("1) Adicionar pessoa\n");
	printf("2) Adicionar produto\n");
	printf("3) Listar pessoas\n");
	printf("4) Listar produtos\n");
	printf("5) Sair\n");
	int escolha;
	scanf(" %d",&escolha);
	return escolha;
}

int main(){
	List lst_pessoas = new(List);
	List lst_produtos = new(List);
	
	while(1){
		system("clear");
		switch(interface()){
			case 1: cadastro(Pessoa,lst_pessoas); break;
			case 2: cadastro(Produto,lst_produtos); break;
			case 3: listar(Pessoa,lst_pessoas); break;
			case 4: listar(Produto,lst_produtos); break;
			case 5: return 0;
			default: printf("Opção inválida");
		}
		esperaEnter("");
	}
}
