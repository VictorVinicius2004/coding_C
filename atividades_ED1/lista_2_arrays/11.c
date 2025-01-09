#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de
Arrays. Faça um programa que implemente o método...
FILTER => Dado um vetor V1, com N números inteiros sorteados entre 0 e 99, e um outro valor inteiro
X, crie um novo vetor V2, preenchendo-o apenas com valores do primeiro vetor que são múltiplos de
X. Um mesmo valor não deve ser filtrado mais de 1 vez. Imprima V1 e V2.*/

int main(){
	srand(time(NULL));
	int n, x;
	printf("Digite a quantidade de valores a serem gerados.\n");
	scanf(" %d", &n);
	printf("Digite um número natural.\n");
	scanf(" %d", &x);
	int v1[n], v2[n], usados[n], cont=0;
	for(int i=0; i<n; i++){
		v2[i]=-1;
		v1[i]=rand()%100;
		usados[i]=-1;
	}
	
	for(int i=0; i<n; i++){
		int permitido=1;
		for(int j=0; j<n; j++){
			if(v1[i]==usados[j] || v1[i]%x!=0 || v1[i]==0){
				permitido=0;
				break;
			}
			if(usados[j]==-1)
				break;
		}
		
		if(permitido){
			usados[cont]=v1[i];
			v2[cont]=v1[i];
			cont++;
		}
			
	} 
	
	printf("\n\nv1: ");
	for (int i = 0; i < n; i++)
		printf("%d ", v1[i]);
	printf("\n\nv2: ");
	if(cont){
		for(int i=0; i<n; i++)
			if(v2[i]!=-1)
				printf("%d ", v2[i]);
	}
	else
		printf("Nenhum multiplo de %d", x);
	return 0;
}
