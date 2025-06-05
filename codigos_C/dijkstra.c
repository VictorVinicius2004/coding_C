#include <stdio.h>
#include <stdlib.h>

#define VERTICES 5
#define INFINITO 2147483647
#define VERDADEIRO 1
#define FALSO 0
#define INDEFINIDO -1

typedef struct{
	int destino;
	int peso;
	int origem;
}Tabela;

typedef struct LinkedList{
	int vertice;
	struct LinkedList* proximo;
}LinkedList;

void inicializaTabela(Tabela tabela[],int origem){
	for(int i=0; i<VERTICES; i++){
		tabela[i].destino=i;
		tabela[i].origem=INDEFINIDO;
		tabela[i].peso = (i==origem)? 0 : INFINITO;
	}
}

void printLinkedList(LinkedList* queue){
	while(queue->proximo!=NULL){
		printf("%d, ",queue->vertice);
		queue=queue->proximo;
	}
	printf("%d\n",queue->vertice);
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
}

int procuraVertice(LinkedList* queue, int alvo){
	while(queue!=NULL){
		if(queue->vertice==alvo)
			return 1;
		queue = queue->proximo;
	}
	return 0;
}

LinkedList* adicionaALista(LinkedList* queue, int vertice){
	if(procuraVertice(queue,vertice))
		return queue;
	
    LinkedList* novo = malloc(sizeof(LinkedList));
    novo->vertice = vertice;
    novo->proximo = NULL;

    if (!queue)
        return novo;

    LinkedList* temp = queue;
    while (temp->proximo != NULL){
        temp = temp->proximo;
    }
    temp->proximo = novo;

    return queue;
}

LinkedList* proximoDaLista(LinkedList* queue){
	LinkedList* novo = queue->proximo;
	free(queue);
	return novo;
}

void dijkstra(int grafo[VERTICES][VERTICES], int origem, Tabela tabela[]){
	LinkedList* fila=NULL;
	LinkedList* visitados=NULL;
	//inicia a fila com a origem
	fila = adicionaALista(fila,origem);
	
	while(fila!=NULL){
		//adiciona o vértice atual aos visitados
		visitados = adicionaALista(visitados,fila->vertice);

		for(int destino=0; destino<VERTICES; destino++){
			//evitar calculo com si mesmo e com a origem
			if(grafo[fila->vertice][destino]==0 || destino==origem)
				continue;
			
			//se ainda foi visitado vai para a fila
			if(!procuraVertice(visitados,destino))
				fila = adicionaALista(fila,destino);
			
			//calcula o somatório do peso e atualiza o menor caminho
			int pesoAtual = grafo[fila->vertice][destino] + tabela[fila->vertice].peso;
			if(pesoAtual<tabela[destino].peso){
				tabela[destino].peso=pesoAtual;
				tabela[destino].origem=fila->vertice;
				
				//caso um vértice já visitado receba uma alteração
				if(procuraVertice(visitados,destino)){
					fila = adicionaALista(fila,destino);
				}
			}
			
			//print da tabela
			printf("%d --> %d\n",fila->vertice,destino);
			printTabela(tabela);
			printf("Fila: ");
			printLinkedList(fila);
			printf("Visitados: ");
			printLinkedList(visitados);
			printf("\n");
		}	
		//atender o próximo da fila
		fila = proximoDaLista(fila);
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
	  // 0 1 2 3 4
		{0,4,3,5,0},//0
		{4,0,2,0,6},//1
		{3,2,0,1,6},//2
		{5,0,1,0,3},//3
		{0,6,6,3,0},//4
	};
	Tabela tabela[VERTICES];
	inicializaTabela(tabela,0);
	
	dijkstra(grafo,0,tabela);
	printCaminho(tabela,0,4);
	return 0;
}
