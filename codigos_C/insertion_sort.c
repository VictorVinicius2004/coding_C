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
	
	for(int i=1; i<n; i++){
		int temp=vetor[i], j;
		
		for(j=i-1; j>=0; j--){
			if(temp>=vetor[j]) break;
			vetor[j+1]=vetor[j];
		}
		vetor[j+1]=temp;
	}
	
	printf("\n\nVetor ordenado:\n");
	for(int i=0; i<n; i++)
		printf("%02d ", vetor[i]);
	return 0;
}

