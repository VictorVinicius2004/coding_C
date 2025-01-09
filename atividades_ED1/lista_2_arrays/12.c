#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de
Arrays. Faça um programa que implemente o método...
REDUCE => Dado um vetor V, com N números inteiros sorteados aleatoriamente (entre 0 e 9),
imprima a maior sequência crescente do vetor (em caso de empate, imprima a primeira sequência).*/

int main(){
	srand(time(NULL));
	int n;
	printf("Digite a quantidade de números a serem sorteados.\n");
	scanf(" %d", &n);
	int vetor[n], sequencia[2], iniciofim[2], maiorseq=-1;
	
	printf("Vetor: ");
	for(int i=0; i<n; i++){
		vetor[i]=rand()%10;
		printf("%d ", vetor[i]);
	}
		
	for(int i=0; i<n; i++){
		int cont=i;
		iniciofim[0]=i;
		iniciofim[1]=i;
		
		do{
			cont++;
			if(cont<n && vetor[cont]==vetor[cont-1]+1){
				iniciofim[1]=cont;
			}
			else
				break;
		}while(1);
		
		if(i==0){
			maiorseq=iniciofim[1]-iniciofim[0];
			sequencia[0]=iniciofim[0];
			sequencia[1]=iniciofim[1];
		}
		else
			if(maiorseq<(iniciofim[1]-iniciofim[0])){
				maiorseq=iniciofim[1]-iniciofim[0];
				sequencia[0]=iniciofim[0];
				sequencia[1]=iniciofim[1];
			}
	}
	
	printf("\n\nMaior sequencia crescente: ");
	for(int i=sequencia[0]; i<=sequencia[1]; i++)
		printf("%d ", vetor[i]);
	printf("\nposição %d a %d", sequencia[0], sequencia[1]);
	return 0;
}
