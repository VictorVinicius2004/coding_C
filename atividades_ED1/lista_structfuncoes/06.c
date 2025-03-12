/*Uma pequena mercearia deseja informatizar o processo de estoque e venda de produtos.
Faça um programa que alimente um vetor com até 100 registros de Produto: Código de Barras (i),
Descrição (s), Qtde. em Estoque (i), Valor Unitário (f).
Após cadastrar o estoque existente, o programa entrará no modo de venda (PDV). Neste modo, o
programa seguirá o seguinte fluxo:
●​ O caixa informa o Código de Barra do produto a ser vendido;
●​ O programa verifica e imprime todas informações do produto (ou se não existe/leitura incorreta);
●​ O caixa informa a Quantidade que deseja comprar deste item;
●​ O programa verifica se possui a quantidade desejada em estoque;
●​ Caso seja possível realizar a venda, o programa contabiliza o valor a ser pago e atualiza a
quantidade daquele item no estoque;
O Programa deve repetir todo o fluxo acima para vários itens, até que o Código de Barras informado seja
um valor negativo; Caso seja informado um código negativo, o programa deve então imprimir o valor
total da venda realizada, receber o valor pago pelo cliente, e calcular o troco a ser devolvido.
Iniciar uma nova operação de venda logo em seguida.*/

#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int codigo, estoque;
	char descricao[50];
	float valor;
}Produto;

void ordena_produtos(int cont, Produto *produtos){
	for(int i=0; i<cont-1; i++)
		for(int j=i+1; j<cont; j++)
			if(produtos[i].codigo>produtos[j].codigo){
				Produto aux=produtos[i];
				produtos[i]=produtos[j];
				produtos[j]=aux;
			}
}

int cadastrar_produto(Produto *produtos, int cont){
	printf("cadastro de produtos\n");
	do{
		printf("Código do produto: ");
		scanf(" %d", &produtos[cont].codigo);
		printf("Descrição: ");
		scanf(" %s", produtos[cont].descricao);
		printf("Quantidade em estoque: ");
		scanf(" %d", &produtos[cont].estoque);
		printf("Valor unitário: ");
		scanf(" %f", &produtos[cont].valor);
		cont++;
		
		int saida;
		printf("Deseja sair?0-não, 1-sim\n");
		scanf(" %d", &saida);
		if(saida) break;
	}while(1);
	system("clear");
	return cont;
}

void printproduto(Produto p){
	printf("Descrição: %s \nCódigo: %d \nEstoque: %d \nValor: R$%.2f\n",
		p.descricao,
		p.codigo,
		p.estoque,
		p.valor);
}

int busca_produto(int code, int cont, Produto *produtos){
	int inicio=0, fim=cont-1, encontrado=-1;
	
	do{
		int meio=(inicio+fim)/2;
		
		if(produtos[meio].codigo==code){
			encontrado=meio;
			break;
		}
		else if(produtos[meio].codigo>code)
			fim=meio-1;
		else
			inicio=meio+1;
	}while(inicio<=fim);
	
	return encontrado;
}

void etapa_venda(int cont, Produto *produtos){
	float valor_compra=0;
	do{
		printf("produtos disponíveis:\n");
		for(int i=0; i<cont; i++){
			printproduto(produtos[i]);
			printf("\n");
		}
		int code;
		printf("Valor atual: R$%.2f\n", valor_compra);
		printf("digite o código do produto(-1 para confirmar a compra): ");
		scanf(" %d", &code);
		system("clear");
		if(code==-1){ 
			system("clear");
			break;
		}
		
		int posicao=busca_produto(code, cont, produtos);
		if(posicao!=-1){
			printproduto(produtos[posicao]);
			int qntd;
			printf("digite a quantidade que deseja comprar\n");
			scanf(" %d", &qntd);
			if(qntd<=produtos[posicao].estoque){
				valor_compra+=produtos[posicao].valor*qntd;
				produtos[posicao].estoque-=qntd;
			}
			else
				printf("quantidade excede o estoque\n\n");
		}
		else
			printf("Código inválido\n\n");
	}while(1);
	
	printf("valor final: R$%.2f", valor_compra);
}

int main(){
	Produto produtos[100];
	int cont=0;
	
	cont = cadastrar_produto(produtos, cont);
	ordena_produtos(cont, produtos);
	etapa_venda(cont, produtos);
	return 0;
}

