#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de
Arrays. Faça um programa que implemente o método...
MAP => Dado um vetor V1, com N números inteiros sorteados entre 0 e 1023, crie um novo vetor V2,
preenchendo-o com os valores do primeiro array convertidos para a base binária. Imprima V1 e V2.*/

int main(){
	srand(time(NULL));
	int n;
	printf("Digite a quantidade de números a serem sorteados.\n");
	scanf(" %d", &n);
	int v1[n], v2[n];
	
	for (int i = 0; i < n; i++)
		v1[i]=rand()%1024;

	for(int i=0; i<n; i++){
		int cont=9, array[10];
		for(int j=v1[i]; j>=1; j/=2)
			array[cont--]=j%2;
		
		for(int j=cont+1; j<10; j++){
			if(j==cont+1)
				v2[i]=1;
			else v2[i]=(array[j]==1)? v2[i]*10+1 : v2[i]*10;
		}
	}
	
	printf("v1       v2\n");
	for (int i = 0; i < n; i++)
		printf("%d   %d\n", v1[i], v2[i]);
	return 0;
}
