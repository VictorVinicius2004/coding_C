#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <gconio.h>

#define LINHAS 12
#define COLUNAS 6
#define PASSOU 0
#define BONUS -1
#define PRESENTE -2
#define MUNIÇOES 50

int main(){
	srand(time(NULL));
	int quarteirao[LINHAS][COLUNAS], linha=0, coluna=2, muniçoes=MUNIÇOES;
	char wasd;
	printf("Seu objetivo é chegar até o acampamento, mas antes você deve passar por vários quarteirões cheios de zumbis tendo um revolver e 50 munições, mas em um dos quarteirõs terá um bonus de 8 munições e nenhum zumbi.\n Boa sorte.\n");
	printf("Pressione qualquer tecla para iniciar\n");
	getch();
	system("clear");
	
	for (int i = 0; i < LINHAS; i++)
		for(int j=0;j<COLUNAS;j++)
			quarteirao[i][j]=rand()%9+1;
	
	quarteirao[rand()%4+4][rand()%COLUNAS]=BONUS;
	quarteirao[0][2]=PRESENTE;
	
	do{
		printf("munição restante: %d\n", muniçoes);
		for (int i = 0; i < LINHAS; i++){
			for (int j = 0; j < COLUNAS; j++){
				if(quarteirao[i][j]==PASSOU)
					printf("* ");
				else{
					if(quarteirao[i][j]==PRESENTE)
						printf("@ ");
					if(quarteirao[i][j]==BONUS)
						printf("# ");
					if(quarteirao[i][j]!=BONUS && quarteirao[i][j]!=PRESENTE)
						printf("%d ", quarteirao[i][j]);
				}
			}
			printf("\n");
		}
		printf("==========\n");
		
	printf("Use WASD para se mover\n");
	wasd=getch();
	system("clear");
	switch(wasd){
		case 'w':
			if(quarteirao[linha-1][coluna]!=PASSOU && linha-1>=0){
				quarteirao[linha][coluna]=PASSOU;
				linha--;
			}
			else
				printf("movimento inválido\n");
			break;
		case 'a':
			if(quarteirao[linha][coluna-1]!=PASSOU && coluna-1>=0){
				quarteirao[linha][coluna]=PASSOU;
				coluna--;
			}
			else
				printf("movimento inválido\n");
			break;
		case 's':
			if((quarteirao[linha+1][coluna]!=PASSOU && linha+1<=LINHAS) || linha+1==LINHAS){
				quarteirao[linha][coluna]=PASSOU;
				linha++;
			}
			else
				printf("movimento inválido\n");
			break;
		case 'd':
			if(quarteirao[linha][coluna+1]!=PASSOU && coluna+1<=COLUNAS-1){
				quarteirao[linha][coluna]=PASSOU;
				coluna++;
			}
			else
				printf("movimento inválido\n");
			break;
		default:
			printf("movimento inválido\n");
	}
	
	if(linha==LINHAS){
		printf("Parebéns! você chegou até o acampamento vivo");
		break;
	}
	if(quarteirao[linha][coluna]!=BONUS)
		muniçoes-=quarteirao[linha][coluna];
	else
		muniçoes+=8;
		
	if(muniçoes<=0){
		printf("Você não teve munição suficiente para chegar ao acampamento vivo");
		break;
	}
	
	quarteirao[linha][coluna]=PRESENTE;
	}while(1);
	
	return 0;
}

