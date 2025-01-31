/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
Imprima-a em formato de tabela, e os valores que compõem a coluna que resulta na maior soma, e os
valores da linha que resulta na menor soma.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	int n, min, max;
	printf("Digite o valor de n, min e max respectivamente.\n");
	scanf(" %d %d %d", &n, &min, &max);
	
	int matriz[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			matriz[i][j]=rand()%(max-min+1)+min;
			printf("[%02d] ", matriz[i][j]);
		}
		printf("\n");
	}
	
	//linha de maior soma
	int soma_l, maior_linha;
	for(int i=0 ; i<n; i++){
		int soma=0;
		for(int j=0; j<n; j++)
			soma+=matriz[i][j];
		
		
		if(i==0){
			soma_l=soma;
			maior_linha=0;
		}
		else if(soma>soma_l){
			soma_l=soma;
			maior_linha=i;
		}
	}
	
	//coluna de maior valor
	int soma_c, maior_coluna;
	for(int j=0; j<n; j++){
		int soma=0;
		for(int i=0; i<n; i++)
			soma+=matriz[i][j];
		
		if(j==0){
			soma_c=soma;
			maior_coluna=0;
		}
		else if(soma>soma_c){
			soma_c=soma;
			maior_coluna=j;
		}
	}
	
	printf("\nMaior linha: %d \nSoma: %d\n", maior_linha, soma_l);
	for(int j=0; j<n; j++)
		printf("[%02d] ", matriz[maior_linha][j]);
	printf("\nMaior coluna: %d \nSoma : %d\n", maior_coluna, soma_c);
	for (int i = 0; i < n; i++)
		printf("[%02d] ", matriz[i][maior_coluna]);
	return 0;
}

