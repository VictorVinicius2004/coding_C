#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre X e Y.
O programa deve informar a posição (índice) onde se encontra o menor número sorteado, seguido da
posição onde se encontra o segundo menor número sorteado, e assim sucessivamente...*/

int main(){
	int x, y, n, maior, menor;
	printf("Digite a quantidade de números a serem sorteados.\n");
	scanf(" %d", &n);
	printf("Digite o min e o max respectivamente.\n");
	scanf(" %d %d", &x, &y);
	int vetor[n], indice;
	
	for (int i = 0; i < n; i++){
		vetor[i]=rand()%(y-x+1)+x;
		printf("%02d ", vetor[i]);

		if(!i)
			maior=vetor[i];
		
		else
			if(maior<vetor[i])
				maior=vetor[i];
	}
	
	printf("\nOrdem crescente:\n");
	
	for (int i = 0; i < n; i++){
		menor=maior;
		
		for(int j=0; j<n; j++)
			if(menor>vetor[j]){
				menor=vetor[j];
				indice=j;
			}
		
		vetor[indice]=maior;
		
		printf("%02d°: %02d\n", i+1, menor);
	}
	return 0;
}
