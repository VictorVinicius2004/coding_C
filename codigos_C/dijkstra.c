#include <stdio.h>

#define VERTICES 4
#define INFINITO 2147483647
enum {VERDADEIRO, FALSO};

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
		tabela[i].peso = (i==0)? 0 : INFINITO;
	}
}

void dijkstra(int grafo[VERTICES][VERTICES],int origem,Tabela tabela[]){
	for(int destino=0; destino<VERTICES; destino++){
		if(grafo[origem][destino]==0)
			continue;
		
		int alterado=FALSO;
		tabela[origem].visitado=VERDADEIRO;
		
		int pesoAtual = grafo[origem][destino] + tabela[origem].peso;
		if(pesoAtual<tabela[destino].peso){
			tabela[destino].peso=pesoAtual;
			tabela[destino].origem=origem;
			alterado=VERDADEIRO;
		}
		
		if(alterado==VERDADEIRO || tabela[destino].visitado==FALSO)
			dijkstra(grafo,destino,tabela);
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
		{0,3,4,0},//0
		{3,0,1,3},//1
		{4,1,0,2},//2
		{0,3,2,0},//3
	};
	Tabela tabela[VERTICES];
	inicializaTabela(tabela);
	
	dijkstra(grafo,0,tabela);
	printCaminho(tabela,0,3);
	return 0;
}

