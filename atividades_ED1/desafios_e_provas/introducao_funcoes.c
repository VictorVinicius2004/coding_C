#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int codigo, estoque;
	char descricao[50];
	float valor;
}Produto;

void cadastra_produto(Produto *produto){
	printf("Codigo: ");
	scanf(" %d", &produto->codigo);
	printf("Descrição: ");
	scanf(" %s", produto->descricao);
	printf("Estoque: ");
	scanf(" %d", &produto->estoque);
	printf("Valor: ");
	scanf(" %f", &produto->valor);
}

void printproduto(Produto produto){
	printf("%s \n%d \n%f \n%d",
	produto.descricao,
	produto.codigo,
	produto.valor,
	produto.estoque);
}

void vendeproduto(Produto *produto){
	int qntd;
	printf("deseja comprar quantas unidades?\n");
	scanf(" %d", &qntd);
	
	int confirm;
	printf("O valor será de %f \nConfirmar compra? 0-não, 1-sim\n", qntd*produto->valor);
	scanf(" %d", &confirm);
	if(confirm)
		produto->estoque-=qntd;
}

int main(){
	Produto produto;
	cadastra_produto(&produto);
	printproduto(produto);
	vendeproduto(&produto);
	printproduto(produto);
	return 0;
}

