#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define V 1
# define F 0

/*Faça um programa C para ler do usuário dois valores inteiros X e Y. Alimente dois vetores de tamanhos X
e Y com números inteiros aleatórios, não repetitivos, sorteados no intervalo entre 0 e X+Y (inclusive).
Faça a impressão das seguintes informações:
a) Vetores X e Y;
b) Todos os números exclusivos do vetor X;
c) Todos os números exclusivos do vetor Y;
d) Os números existentes nos dois vetores;*/

int main(){
	srand(time(NULL));
	int x, y;
	printf("Digite o valor de x e y.\n");
	scanf(" %d %d", &x, &y);
	getchar();
	system("clear");
	int vetorX[x], vetorY[y], num, cont=0;
	
	do{
		num=rand()%(x+y+1);
		for (int i = 0; i < cont; i++)
			if(vetorX[i]==num){
				num=-1;
				break;
			}
			
		if(num>=0){
			vetorX[cont]=num;
			cont++;
		}
		
	} while (cont<x);
	cont=0;
	
	do{
		num=rand()%(x+y+1);
		for (int i = 0; i < cont; i++)
			if(vetorY[i]==num){
				num=-1;
				break;
			}
			
		if(num>=0){
			vetorY[cont]=num;
			cont++;
		}
	} while (cont<y);
	
	//a)
	printf("Vetor x: ");
	for(int i=0; i<x; i++)
		printf("%02d ", vetorX[i]);
	printf("\n\nVetor y: ");
	for(int i=0; i<y; i++)
		printf("%02d ", vetorY[i]);
	printf("\n");
	
	printf("\nPressione ENTER para continuar\n");
	getchar();
	
	//b)
	printf("Exclusivos do vetor x: ");
	for (int i = 0; i < x; i++){
		num=V; 
		for(int j=0; j<y; j++)
			if(vetorX[i]==vetorY[j]){
				num=F;
				break;
			}
		
		if(num)
			printf("%d ", vetorX[i]);
	}
	
	//c)
	printf("\n\nExclusivos do vetor y: ");
	for (int i = 0; i < y; i++){
		num=V; 
		for(int j=0; j<x; j++)
			if(vetorY[i]==vetorX[j]){
				num=F;
				break;
			}
		
		if(num)
			printf("%d ", vetorY[i]);
	}
	
	printf("\n\nPressione ENTER para continuar\n");
	getchar();
	
	//d)
	printf("Números comuns aos dois vetores: ");
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			if(vetorX[i]==vetorY[j]){
				printf("%02d ", vetorX[i]);
				break;
			}
	return 0;
}

