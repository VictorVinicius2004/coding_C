#include <stdio.h>

#define VERTICES 4
#define INFINITO 2147483647
#define VERDADEIRO 1
#define FALSO 0
#define INDEFINIDO -1

typedef struct{
	int destino;
	int peso;
	int origem;
	int visitado;
}Tabela;

void inicializaTabela(Tabela tabela[]){
	for(int i=0; i<VERTICES; i++){
		tabela[i].destino=i;
		tabela[i].visitado=FALSO;
		tabela[i].origem=INDEFINIDO;
		tabela[i].peso = (i==0)? 0 : INFINITO;
	}
}

void printTabela(Tabela tabela[]){
	for(int i=0; i<VERTICES; i++){
		printf("%02d | ",tabela[i].destino);
		if(tabela[i].peso==INFINITO)
			printf("∞  | ");
		else
			printf("%02d | ", tabela[i].peso);
		if(tabela[i].origem!=INDEFINIDO)
			printf("%02d",tabela[i].origem);
		printf("\n");
	}
	printf("\n");
}

void dijkstra(int grafo[VERTICES][VERTICES],int origem, int final, Tabela tabela[]){
	for(int origem=0; origem<VERTICES; origem++){
		for(int destino=0; destino<VERTICES; destino++){
			if(grafo[origem][destino]==0)
				continue;
			if(origem==final)
				return;
				
			int alterado=FALSO;
			tabela[origem].visitado=VERDADEIRO;
			
			int pesoAtual = grafo[origem][destino] + tabela[origem].peso;
			if(pesoAtual<tabela[destino].peso){
				tabela[destino].peso=pesoAtual;
				tabela[destino].origem=origem;
				alterado=VERDADEIRO;
			}
			
			printf("{%d --> %d}\n",origem,destino);
			printTabela(tabela);
			
			if(alterado==VERDADEIRO && tabela[destino].visitado==VERDADEIRO){
				origem=destino;
				destino=0;
			}
		}
	}
}

void printCaminho(Tabela tabela[], int origem, int destino){
	printf("(%d) - ", destino);
	int posicaoAtual=destino;
	do{
		posicaoAtual=tabela[posicaoAtual].origem;
		if(posicaoAtual!=origem)
			printf("(%d) - ",posicaoAtual);
		else{
			printf("(%d)\n",posicaoAtual);
			break;
		}
	}while(1);
}

int main(){
	int grafo[VERTICES][VERTICES]={
	  // 0 1 2 3
		{0,6,4,0},//0
		{6,0,1,2},//1
		{4,1,0,4},//2
		{0,2,4,0},//3
	};
	Tabela tabela[VERTICES];
	inicializaTabela(tabela);
	
	dijkstra(grafo,0,3,tabela);
	printCaminho(tabela,0,3);
	return 0;
}

