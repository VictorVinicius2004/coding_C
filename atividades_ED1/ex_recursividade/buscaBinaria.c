#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define INEXISTENTE -1

int buscaBinariaRecursiva(int array[],int alvo, int min, int max){
	int meio = (min+max) / 2;
	return (min>max)? INEXISTENTE :
	(array[meio]==alvo)? meio :
	(array[meio]>alvo)? buscaBinariaRecursiva(array,alvo,min,meio-1) :
	buscaBinariaRecursiva(array,alvo,meio+1,max);
}

void bubbleSort(int array[], int size){
	for (int i = 0; i < size-1; i++)
		for(int j=i+1; j<size; j++)
			if(array[i]>array[j]){
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}

int main(){
	int array[TAMANHO];
	for(int i=0; i<TAMANHO; i++)
		array[i]=rand()%100;
	bubbleSort(array,TAMANHO);
	for(int i=0; i<TAMANHO; i++)
		printf("%02d°: [%02d]\n",i,array[i]);
		
	int alvo;
	scanf(" %d", &alvo);
	printf("%d\n",buscaBinariaRecursiva(array,alvo,0,TAMANHO-1));
	return 0;
}

