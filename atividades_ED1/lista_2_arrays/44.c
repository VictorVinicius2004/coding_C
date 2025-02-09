/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
Peça ao usuário o índice de duas colunas, e faça a troca das respectivas colunas. Faça o mesmo com duas
linhas escolhidas pelo usuário. Imprima a matriz após realizadas as trocas.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int n, min, max;
	printf("Digite a ordem da matriz.\n");
	scanf(" %d", &n);
	printf("Digite o valor mínimo e máximo respectivamente.\n");
	scanf(" %d %d", &min, &max);
	
	int matriz[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			matriz[i][j]=rand()%(max-min+1)+min;
			printf("%02d ", matriz[i][j]);
		}
		printf("\n");
	}
	int col1, col2, li1, li2;
	printf("Digite duas colunas.\n");
	scanf(" %d %d", &col1, &col2);
	printf("Agora duas linhas.\n");
	scanf(" %d %d", &li1, &li2);
	
	//trocando as colunas
	for(int i=0; i<n; i++){
		int aux=matriz[i][col1];
		matriz[i][col1]=matriz[i][col2];
		matriz[i][col2]=aux;
	}
	
	//trocando as linhas
	for(int j=0; j<n; j++){
		int aux=matriz[li1][j];
		matriz[li1][j]=matriz[li2][j];
		matriz[li2][j]=aux;
	}
	
	printf("Matriz após a troca:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%02d ", matriz[i][j]);
		printf("\n");
	}
	return 0;
}

