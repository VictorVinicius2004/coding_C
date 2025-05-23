#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 25
#define MAX_NUM 100

int findMax(int array[], int indice){
	if(indice==0)
		return array[indice];
	int maior = findMax(array,indice-1);
	return (maior>array[indice])? maior : array[indice];
}

int main(){
	srand(time(NULL));
	int array[TAMANHO];
	for(int i=0; i<TAMANHO; i++){
		array[i]=rand()%MAX_NUM;
		printf("%d ", array[i]);
	}printf("\n");
	
	printf("%d\n", findMax(array,TAMANHO-1));
	return 0;
}

