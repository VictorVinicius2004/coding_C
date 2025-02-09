#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int n;
	printf("Digite a quantidade de valores do vetor.\n");
	scanf(" %d", &n);
	
	int vetor[n];
	for(int i=0; i<n; i++)
		vetor[i]=rand()%(n*2)+1;
	
	for(int i=0; i<n-1; i++){
		int trocado=0;
		for(int j=0; j<n-i-1; j++){
			
			system("sleep 0.3");
			system("clear");
			
			for(int k=n-1; k>=0; k--){
				if(k==j || k==j+1)
					printf("\033[31m");
				else if(k>=n-i)
					printf("\033[32m");
				for(int x=0; x<vetor[k]; x++)
					printf("o");
				
				printf("\033[0m\n");
			}
			
			if(vetor[j]>vetor[j+1]){
				int aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
				trocado=1;
			}
		}
		if(!trocado)
			break;
	}
	
	system("clear");
	printf("\033[32m");
	for(int k=n-1; k>=0; k--){
		for(int x=0; x<vetor[k]; x++)
			printf("o");
		
		printf("\n");
	}
	printf("\033[0m");
	return 0;
}

