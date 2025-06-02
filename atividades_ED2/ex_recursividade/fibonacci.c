#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INEXISTENTE -1

typedef struct Termo{
	int termo;
	int valor;
	struct Termo* left;
	struct Termo* right;
}Termo;

int procuraTermo(Termo* calculados, int alvo);
void salvaTermo(Termo* novoEspaco, int valor, int termo);
void armazenaTermo(int novoValor, int novoTermo, Termo* calculados);
int fibonacci(int termo, Termo* calculados);

int procuraTermo(Termo* calculados, int alvo){
	if(calculados->termo==alvo) 
		return calculados->valor;
	if((calculados->left==NULL) && (calculados->right==NULL))
		return INEXISTENTE;
	if(calculados->termo>alvo) 
		return procuraTermo(calculados->left,alvo);
	return procuraTermo(calculados->right,alvo);
}

void salvaTermo(Termo* novoEspaco, int valor, int termo){
	novoEspaco->left=NULL;
	novoEspaco->right=NULL;
	novoEspaco->termo=termo;
	novoEspaco->valor=valor;
}

void armazenaTermo(int novoValor, int novoTermo, Termo* calculados){
	if(calculados->termo==novoTermo)
		return;
	if(calculados->left==NULL){
		calculados->left=malloc(sizeof(Termo));
		salvaTermo(calculados->left,novoTermo,novoValor);
		return;
	}
	if(calculados->right==NULL){
		calculados->right=malloc(sizeof(Termo));
		salvaTermo(calculados->right,novoTermo,novoValor);
		return;
	}
	if(novoTermo>calculados->termo)
		armazenaTermo(novoValor,novoTermo,calculados->right);
	else
		armazenaTermo(novoValor,novoTermo,calculados->left);
}

int fibonacci(int termo, Termo* calculados){
	if(termo<=2)
		return 1;
	int valor = procuraTermo(calculados,termo);
	if(valor==INEXISTENTE){
		valor = fibonacci(termo-1,calculados)+fibonacci(termo-2,calculados);
		armazenaTermo(valor,termo,calculados);
	}
	return valor;
}

int main(){
	Termo calculados;
	calculados.left=NULL;
	calculados.right=NULL;
	
	int termo;
	do{
		scanf(" %d", &termo);
		long int tempo = time(NULL);
		printf("[%d] ",fibonacci(termo,&calculados));
		printf("Tempo de execução: %ld segundos\n", time(NULL)-tempo);
	}while(termo!=-1);
	return 0;
}

