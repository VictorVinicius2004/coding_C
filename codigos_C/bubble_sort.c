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
	
	getchar();
	system("clear");
			
	//bubble sort
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			for(int k=0; k<n; k++){
				if(k==i)
					printf("[%02d] ", vetor[k]);
				else if(k==j)
					printf("{%02d} ", vetor[k]);
				else
					printf("%02d ", vetor[k]);
			}
			
			if(vetor[i]>vetor[j]){
				int aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
			
			getchar();
			system("clear");
		}
	}
	
	printf("Vetor ordenado:\n");
	for(int i=0; i<n; i++)
		printf("%02d ", vetor[i]);
	return 0;
}

