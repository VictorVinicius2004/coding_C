#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int n; 
	scanf(" %d", &n);
	while(getchar()!='\n');
	
	printf("Vetor gerado:\n");
	int vetor[n];
	for(int i=0; i<n; i++){
		vetor[i]=rand()%(n*2);
		printf("%02d ", vetor[i]);
	}
			
	for(int i=0; i<n-1; i++){
		int pos_minimo=i;
		
		for(int j=i+1; j<n; j++)
			if(vetor[j]<vetor[pos_minimo])
				pos_minimo=j;
		
		int aux=vetor[i];
		vetor[i]=vetor[pos_minimo];
		vetor[pos_minimo]=aux;
	}
	
	printf("\n\nVetor ordenado:\n");
	for(int i=0; i<n; i++)
		printf("%02d ", vetor[i]);
	return 0;
}

