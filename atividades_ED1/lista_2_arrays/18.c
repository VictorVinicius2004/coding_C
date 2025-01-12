/*Faça um programa que alimente um vetor com N números aleatórios sorteados no intervalo entre X e Y.
Faça a ordenação deste vetor, mas considerando a frequência de cada número sorteado.
P.Ex.: 5 - 5 - 5 - 5 - 8 - 8 - 8 - 3 - 3 - 6 - 6 - 9*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	srand(time(NULL));
	int n, min, max;
	printf("Digite a quantidade de valores a serem gerados.\n");
	scanf(" %d", &n);
	printf("Digite o valor mínimo e o máximo respectivamente\n");
	scanf(" %d %d", &min, &max);
	int vetor[n], numeros[max-min+1], cont=0;
	
	//preenchendo o vetor e verificando a quantidade de números diferentes
	for(int i=0; i<n; i++){
		vetor[i]=rand()%(max-min+1)+min;
		
		int permitido=1;
		for (int j = 0; j < cont; j++)
			if(numeros[j]==vetor[i])
				permitido=0;
		if(permitido)
			numeros[cont++]=vetor[i];
	}
	
	//verificando quantas vezes cada número se repete
	int qntdnumeros[cont];
	for(int i=0; i<cont; i++){
		int cont1=0;
		for(int j=0; j<n; j++)
			if(numeros[i]==vetor[j])
				cont1++;
		
		qntdnumeros[i]=cont1;
	}

	//organizando o vetor
	int inicio=0;
	for(int i=0; i<n; i++){
		int maiorcont=0, num_maiorcont, pos_maiorcont;
		for(int j=0; j<cont; j++)
			if(maiorcont<qntdnumeros[j]){
				num_maiorcont=numeros[j];
				pos_maiorcont=j;
				maiorcont=qntdnumeros[j];
			}
		
		if(maiorcont==0)
			break;
		qntdnumeros[pos_maiorcont]=-1;
		
		for(int j=inicio; j<n-1; j++)
			for(int k=j+1; k<n; k++){
				if(vetor[j]==num_maiorcont)
					break;
				else if(vetor[k]==num_maiorcont){
					int aux=vetor[j];
					vetor[j]=vetor[k];
					vetor[k]=aux;
					break;
				}
			}
		inicio+=maiorcont;
	}
	
	//printando o resultado
	printf("resultado:\n");
	for(int i=0; i<n; i++)
		printf("%d ", vetor[i]);
	return 0;
}
