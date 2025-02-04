/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre 0 e N^2 (inclusive).
Todo número sorteado, obrigatoriamente deve ser exclusivo em sua linha e em sua coluna. Imprima a
matriz em formato de tabela.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int n;
	scanf(" %d", &n);
	
	int matriz[n][n];
	
	int i=0, j=0;
	do{
		int num=rand()%(n*n);
		int repetido=0;
		
		for(int l=0; l<i; l++)
			if(matriz[l][j]==num){
				repetido=1;
				break;
			}
		
		for(int c=0; c<j; c++)
			if(matriz[i][c]==num){
				repetido=1;
				break;
			}
		
		if(!repetido){
			matriz[i][j++]=num;		
			
			if(j==n){
				j=0;
				i++;
			}
		}
	}while(i<n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%02d ", matriz[i][j]);
		printf("\n");
	}
	return 0;
}
