#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 10

int main(){
	srand(time(NULL));
	int vetor1[TAM], vetor2[TAM], vetorf[TAM+TAM];
	
	//sorteando os vetores
	printf("Vetor 1: ");
	for(int i=0; i<TAM; i++){
		vetor1[i]=rand()%TAM+TAM+1;
		vetor2[i]=rand()%TAM+TAM+1;
	}
	
	//ordenando os vetores
	for(int i=0; i<TAM-1; i++)
		for(int j=i; j<TAM; j++){
			if(vetor1[i]>vetor1[j]){
				int aux=vetor1[i];
				vetor1[i]=vetor1[j];
				vetor1[j]=aux;
			}
			if(vetor2[i]>vetor2[j]){
				int aux=vetor2[i];
				vetor2[i]=vetor2[j];
				vetor2[j]=aux;
			}
		}
	
	//printando
	printf("\nVetor 1: ");
	for(int i=0; i<TAM; i++){
		printf("[%02d] ", vetor1[i]);
	}
	printf("\nVetor 2: ");
	for(int i=0; i<TAM; i++){
		printf("[%02d] ", vetor2[i]);
	}
	
	//mesclando
	int cont1=0, cont2=0, contf=0;
	do{
		int num1=cont1<TAM? vetor1[cont1] : 0;
		int num2=cont2<TAM? vetor2[cont2] : 0;
		
		if(num1 && num2){
			if(num1<=num2){
				cont1++;
				vetorf[contf++]=num1;
			}
			else{
				cont2++;
				vetorf[contf++]=num2;
			}
		}
		else if(num1){
			cont1++;
			vetorf[contf++]=num1;
		}
		else{
			cont2++;
			vetorf[contf++]=num2;
		}
	}while(contf<TAM+TAM);
	
	printf("\n\nVetor Final: ");
	for(int i=0; i<TAM+TAM; i++)
		printf("[%02d] ", vetorf[i]);
		
	return 0;
}
