#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int n;
	printf("Digite a quantidade de dias no período: ");
	scanf(" %d", &n);
	
	int periodo[n]; 
	for(int i=0; i<n; i++){
		periodo[i]=rand()%(n*2)+1;
		
		printf("Dia %02d: %02d ", i, periodo[i]);
		for(int j=0; j<periodo[i]; j++)
			printf("-");
		printf("\n");
	}
	
	int lucro=0, primeirodia, ultimodia;
	for(int i=0; i<n-1; i++)
		for(int j=i; j<n; j++){
			if(periodo[i]>periodo[j])
				continue;
			if(periodo[j]-periodo[i]>lucro){
				lucro=periodo[j]-periodo[i];
				primeirodia=i;
				ultimodia=j;
			}
			else if(periodo[j]-periodo[i]==lucro && j-i<primeirodia-ultimodia){
				primeirodia=i;
				ultimodia=j;
			}
		}
	
	printf("\nResultado da análise:\n");
	printf("melhor dia para compra: Dia %02d - R$ %d\n", primeirodia, periodo[primeirodia]);
	printf("melhor dia para venda: Dia %02d - R$ %d\n", ultimodia, periodo[ultimodia]);
	printf("Lucro obtido: R$ %d", lucro);
	return 0;
}

