#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Implemente a solução do mesmo problema anterior(08), mas agora considerando que o algoritmo adotado
seja o LFU (Least Frequently Used).*/

int main(){
	srand(time(NULL));
	int n, min, max;
	printf("Digite a quantidade de números a serem sorteados.\n");
	scanf(" %d", &n);
	printf("Digite o min e o max respectivamente.\n");
	scanf(" %d %d", &min, &max);
	system("clear");
	int array[n];
	
	for (int i = 0; i < n; i++)
		array[i]=rand()%(max-min+1)+min;
	
	for(int i=min-1; i<=max; i++){
		int removido=0;
		
		for(int j=0; j<n; j++)
			if(array[j]==i){
				array[j]=max+1;
				removido=1;
			}
		
		for(int j=0; j<n; j++)
			if((array[j]<=max && removido) || i==min-1)
				printf("%02d ", array[j]);
		if(removido || i==min-1)
			printf("\n");
	}
	printf("Programa finalizado.");
	return 0;
}

