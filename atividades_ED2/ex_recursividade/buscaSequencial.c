#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INEXISTENTE -1
#define TAMANHO 20

int buscaLinearRecursiva(int array[], int alvo, int indice){
	return (indice==-1)? INEXISTENTE : 
	(array[indice]==alvo)? indice : buscaLinearRecursiva(array,alvo,indice-1);
}

int main(){
	srand(time(NULL));
	int array[TAMANHO];
	for(int i=0; i<TAMANHO; i++){
		array[i]=rand()%100;
		printf("%02d°: [%02d]\n", i, array[i]);
	}
	
	int alvo;
	scanf(" %d", &alvo);
	printf("%d\n", buscaLinearRecursiva(array,alvo,TAMANHO-1));
	return 0;
}

