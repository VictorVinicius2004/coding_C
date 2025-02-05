/*Faça um programa que alimente um vetor com N números aleatórios sorteados no intervalo entre X e Y.
Faça a ordenação deste vetor, mas considerando a frequência de cada número sorteado.
P.Ex.: 5 - 5 - 5 - 5 - 8 - 8 - 8 - 3 - 3 - 6 - 6 - 9*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct{
	int num;
	int cont;
}Nuns;

int main(){
	srand(time(NULL));
	int n, min, max;
	printf("Digite a quantidade de valores a serem gerados.\n");
	scanf(" %d", &n);
	printf("Digite o valor mínimo e o máximo respectivamente\n");
	scanf(" %d %d", &min, &max);
	
	//preenchendo e printando o vetor
	Nuns vetor[n];
	for(int i=0; i<n; i++){
		vetor[i].num=rand()%(max-min+1)+min;
		vetor[i].cont=0;
		
		if(i>0){
			int temp=vetor[i].num, j;
			for(j=i-1; j>=0; j--){
				if(temp>=vetor[j].num)
					break;
				vetor[j+1].num=vetor[j].num;
			}
			vetor[j+1].num=temp;
		}
	}
	
	for(int i=0; i<n; i++)
		printf("%d ", vetor[i].num);
	printf("\n");
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(vetor[i].num==vetor[j].num)
				vetor[i].cont++;
	
	for(int i=1; i<n; i++){
		Nuns temp=vetor[i];
		int j;
		
		for(j=i-1; j>=0; j--){
			if(temp.cont<=vetor[j].cont)
				break;
			vetor[j+1]=vetor[j];
		}
		vetor[j+1]=temp;
	}
	
	//printando o resultado
	printf("resultado:\n");
	for(int i=0; i<n; i++)
		printf("%d ", vetor[i].num);
	return 0;
}
