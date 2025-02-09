/*Gere uma cartela de bingo 5 x 5, com números aleatórios entre 1 e 75. (Em uma cartela de bingo, não há
números repetidos e os números são apresentados em ordem crescente). Imprima a cartela e faça com
que o programa sorteie as bolas, uma a uma, e realize a “marcação” da cartela em tempo real.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 typedef struct{
	int num;
	int escolhido;
 }Cartela;
 
int main(){
	srand(time(NULL));
	Cartela cartela[5][5];
	
	//preenche a matriz com valores não repetidos
	int i=0;
	do{
		int j=0;
		do{
			int num=rand()%75+1;
			
			int repetido=0;
			for(int l=0; l<=i; l++){
				for(int c=0; c<5; c++){
					if(l==i && c==j)
						break;
					if(num==cartela[l][c].num){
						repetido=1;
						break;
					}
					if(repetido)
						break;
				}
			}
			if(!repetido){
				cartela[i][j].num=num;
				cartela[i][j].escolhido=0;
				j++;
			}
		}while(j<5);
		i++;
	}while(i<5);
	
	//ordenando a matriz
	for(int j=0; j<5; j++)
		for(int i=0; i<5; i++)	
			for(int c=j; c<5; c++)
				for(int l=0; l<5; l++)
					if(((c==j && l>i) || c>j) && (cartela[i][j].num>cartela[l][c].num)){
							int aux=cartela[i][j].num;
							cartela[i][j]=cartela[l][c];
							cartela[l][c].num=aux;
					}
					
	int tentativas=0, cont=0;
	do{
		int sorteado=rand()%75;
		printf("%d° tentativa%d \nNúmero sorteado: %d\n\n", ++tentativas, cont, sorteado);
		
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(cartela[i][j].num==sorteado && !cartela[i][j].escolhido){
					cartela[i][j].escolhido=1;
					cont++;
				}
				
				if(cartela[i][j].escolhido)
					printf("\033[32m%02d \033[0m", cartela[i][j].num);
				else
					printf("%02d ", cartela[i][j].num);
			}
			printf("\n");
		}
	
	system("sleep 0.6");
	system("clear");
	}while(cont<25);
	
	printf("Total de tentativas: %d", tentativas);
	return 0;
}

