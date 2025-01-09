#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Gere dois vetores, V1 e V2, cada um com K valores aleatórios sorteados no intervalo entre 0 e X (0<K<X).
O usuário deve informar o valor de K e X, desde que K < X. O programa NÃO deverá aceitar números
repetidos no mesmo vetor, e nem o mesmo número no mesmo índice dos dois vetores. Imprima os
valores sorteados nos dois vetores, e o resultado da multiplicação dos valores dos índices de V1 e V2.*/

int main(){
	srand(time(NULL));
	int x, k;
	do{
		printf("Digite o valor de k(k>0)\n");
		scanf(" %d", &k);
		system("clear");
	} while (k<=0);
	
	do{
		printf("Digite o valor de x(x>k)\n");
		scanf(" %d", &x);
		system("clear");
	} while (x<=k);
	int v1[k], v2[k], n1, n2, cont=0;
	
	do{
		int aceito=1;
		n1=rand()%(x+1);
		n2=rand()%(x+1);
	
		for (int i = 0; i < cont; i++){
			if(n1==v1[i]){
				aceito=0;
				break;
			}
			if(n2==v2[i]){
				aceito=0;
				break;
			}
		}
		
		if(aceito && n1!=n2){
			v1[cont]=n1;
			v2[cont]=n2;
			cont++;
		}
	}while(cont<k);
	
	printf("V1: ");
	for (int i = 0; i < k; i++)
		printf("%02d ", v1[i]);
	printf("\n\nV2: ");
	for (int i = 0; i < k; i++)
		printf("%02d ", v2[i]);
	
	printf("\n\nV1[i]xV2[i]:\n");
	for (int i = 0; i < k; i++)
		printf("%02dx%02d=%02d\n", v1[i], v2[i], v1[i]*v2[i]);
	return 0;
}

