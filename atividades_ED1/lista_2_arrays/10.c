#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

/*Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de
Arrays. Faça um programa que implemente o método...
MAP => Dado um vetor V1, com N números inteiros sorteados entre 0 e 1023, crie um novo vetor V2,
preenchendo-o com os valores do primeiro array convertidos para a base binária. Imprima V1 e V2.*/

int main(){
	srand(time(NULL));
	int n;
	printf("Digite a quantidade de números a serem sorteados.\n");
	scanf(" %d", &n);
	int v1[n], num, expoente;
	unsigned long int v2[n], bin;
	
	for (int i = 0; i < n; i++)
		v1[i]=rand()%1024;
	
	for(int i=0; i<n; i++){
		for(int j=10; j>=1; j--){
			if(v1[i]<=pow(2, j)-1)
				expoente=j;
			else
				break;
		}
		
		int array[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		num=v1[i];
		do{
			array[expoente-1]=num%2;
			num/=2;
			expoente--;
		}while(num>0);

		bin=array[0];
		for(int j=1; j<10; j++){
			if(array[j]!=-1){
				switch(array[j]){
					case 0:
						bin*=10;
						break;
					case 1:
						bin=bin*10+1;
				}
			}
			else
				break;
		}
		v2[i]=bin;
	}
	
	printf("v1       v2\n");
	for (int i = 0; i < n; i++)
		printf("%d   %lu\n", v1[i], v2[i]);
	return 0;
}

