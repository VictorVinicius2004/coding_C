#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*Faça um programa que sorteie aleatoriamente N números, no intervalo entre X e Y (inclusive). Após o
sorteio, o programa deve imprimir os números sorteados originalmente. Após isso, e a cada iteração, o
programa deve imprimir novamente a relação, mas agora trocando as posições do MAIOR elemento pelo
MENOR elemento. Uma vez trocadas as posições, estes mesmos número não poderão ser mais trocados.
Repita essa operação até quando for possível.*/


int main(){
	srand(time(NULL));
	int n, min, max;
	printf("Digite a quantidade de números a serem sorteados.\n");
	scanf(" %d", &n);
	printf("Digite o valor mínimo e máximo, respectivamente, a serem sortados.\n");
	scanf(" %d %d", &min, &max);
	int vetor[n], trocados[n];
	
	for(int i=0; i<n; i++){
		vetor[i]=rand()%(max-min+1)+min;
		trocados[i]=0;
	}
	
	do{
		int maior=min-1, menor=max+1, pos_maior, pos_menor;
		
		printf("\n");
		for(int i=0; i<n; i++)
			printf("%02d ", vetor[i]);
		printf("\n");
		
		for(int i=0; i<n; i++){
			if(menor>vetor[i] && trocados[i]==0){
				menor=vetor[i];
				pos_menor=i;
			}
			if(maior<vetor[i] && trocados[i]==0){
				maior=vetor[i];
				pos_maior=i;
			}
		}
		
		int aux=vetor[pos_maior];
		vetor[pos_maior]=vetor[pos_menor];
		vetor[pos_menor]=aux;
		
		trocados[pos_maior]=1;
		trocados[pos_menor]=1;
		
		if(maior==min-1 || menor==max+1)
			break;
			
		printf("\npróxima troca: %02d e %02d\n", maior, menor);
		printf("Posições [%d] e [%d]\n", pos_maior, pos_menor);
	}while(1);
	
	return 0;
}
