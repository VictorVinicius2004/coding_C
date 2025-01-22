/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
Imprima-a em formato de tabela (linhas e colunas) e informe a localização do maior e do menor valor da
matriz.*/

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
	int matriz[n][n], menor=max+1, maior=min-1, pos_maior[2], pos_menor[2];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			matriz[i][j]=rand()%(max-min+1)+min;
			
			if(menor>matriz[i][j]){
				menor=matriz[i][j];
				pos_menor[0]=i;
				pos_menor[1]=j;
			}
			if(maior<matriz[i][j]){
				maior=matriz[i][j];
				pos_maior[0]=i;
				pos_maior[1]=j;
			}
		}
	}

	for(int i=-1; i<n; i++){
		for(int j=-1; j<n; j++){
			if(i==-1){
				if(j==0)
					printf("     %02d° ",j);
				if(j>0)
					printf("%02d° ",j);
				if(j==n-1)
					printf("\n");
			}
			else{
				if(j==-1)
					printf("%02d°  ", i);
				else
					printf("%02d  ", matriz[i][j]);
			}
		}
		printf("\n"); 
	}
	printf("\nmaior número: %d \nlinha: %d \ncoluna: %d\n\n", maior, pos_maior[0], pos_maior[1]);
	printf("menor número: %d \nlinha: %d \ncoluna: %d", menor, pos_menor[0], pos_menor[1]);
	return 0;
}

