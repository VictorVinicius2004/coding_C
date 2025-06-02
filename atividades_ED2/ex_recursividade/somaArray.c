#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5
#define RAND 5

int somaArray(int array[], int indice){
	return (indice==0)? array[indice] : array[indice] + somaArray(array, indice-1);
}

int main(){
	int array[TAMANHO];
	for(int i=0; i<TAMANHO; i++){
		array[i]=rand()%RAND;
		printf("%d ", array[i]);
	}printf("\n");
	
	printf("%d\n", somaArray(array,TAMANHO-1));
	return 0;
}

