#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <MINHA_BIBLIOTECA.h>

/*Faça um programa que sorteie aleatoriamente N números, no intervalo entre X e Y (inclusive). Após o
sorteio, o programa deve imprimir os números sorteados originalmente. Após isso, e a cada iteração, o
programa deve imprimir novamente a relação, mas agora trocando as posições do MAIOR elemento pelo
MENOR elemento. Uma vez trocadas as posições, estes mesmos número não poderão ser mais trocados.
Repita essa operação até quando for possível.*/


int main(){
	int n, min, max;
	printf("Digite a quantidade de números a serem sorteados.\n");
	scanf(" %d", &n);
	printf("Digite o valor mínimo e máximo, respectivamente, a serem sortados.\n");
	scanf(" %d %d", &min, &max);
	int vetor[n], trocados[n], permitido, maior=min-1, menor=max+1, pos_maior, pos_menor;
	
	printf("Vetor original: ");
	for(int i=0; i<n; i++){
		trocados[i]=n;
		vetor[i]=rand()%(max-min+1)+min;
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	
	printf("Novos vetores:\n");
	do{
		maior=min-1;
		menor=max+1;
			
		for(int i=0; i<n; i++){
			permitido=!entre_vetor(i, n, trocados);
			
			if(permitido){
				if(maior<vetor[i]){
					maior=vetor[i];
					pos_maior=i;
				}
				if(menor>vetor[i]){
					menor=vetor[i];
					pos_menor=i;
				}
			}
		}
		
		if(maior>=min && menor<=max){
			int aux=vetor[pos_maior];
			vetor[pos_maior]=vetor[pos_menor];
			vetor[pos_menor]=aux;
			
			trocados[pos_maior]=pos_maior;
			trocados[pos_menor]=pos_menor;
			
			for(int i=0; i<n; i++)
				printf("%d ", vetor[i]);
			printf("\n\n");
		}
		else
			break;
	}while(1);
	return 0;
}

