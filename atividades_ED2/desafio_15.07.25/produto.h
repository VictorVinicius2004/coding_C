#ifndef PRODUTO_H
#define PRODUTO_H

#include <string.h>

typedef struct{
	char nome[100];
	float preco;
}Produto;

Produto* preenche_produto(char* nome, float preco){
	Produto* produto = malloc(sizeof(Produto));
	strcpy(produto->nome,nome);
	produto->preco=preco;
	return produto;
}

void new_Produto(List lst, char* nome, float preco){
	enqueue(lst);
	lst->tail->item=preenche_produto(nome,preco);
}

void listar_Produto(List lst){
	Object temp = lst->head;
	while(temp){
		Produto* produto = temp->item;
		
		printf("Item: [%02d]\n",temp->id);
		printf("Nome: %s\n",produto->nome);
		printf("Preço: %.2f\n\n",produto->preco);
		
		temp=temp->prox;
	}
}

#endif
