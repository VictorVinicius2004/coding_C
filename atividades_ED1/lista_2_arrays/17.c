/*Faça um programa que gere um vetor com K números aleatórios entre 0 e N. Após isso, peça um número
X ao usuário, e consulte pelo valor de PISO (maior número menor ou igual a X) e valor de TETO (menor
número maior ou igual a X). Faça várias buscas, sempre utilizando o algoritmo de Pesquisa Binária.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int k, max, x;
	printf("Digite a quantidade de números a serem gerados.\n");
	scanf(" %d", &k);
	printf("Digite o valor máximo a ser gerado.\n");
	scanf(" %d", &max);
	do{
		printf("Digite um valor de x(1<=x<=%d).\n", max-1);
		scanf(" %d", &x);
	}while(x<1 || x>max-1);
	int vetor[k];
	
	//gerando vetor
	for(int i=0; i<k; i++)
		vetor[i]=rand()%(max+1);
	
	//ordenando
	for(int i=0; i<k-1; i++)
		for(int j=i+1; j<k; j++)
			if(vetor[i]>vetor[j]){
				int aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
			
	int i_max=k-1, i_min=0, teto, piso;	
	while(i_min<=i_max){
		int meio=i_min+(i_max-i_min)/2;
		
		if(vetor[meio]==x){
			piso = teto = vetor[meio];
			break;
		}
		else if(vetor[meio]>x){
			teto=vetor[meio];
			i_max=meio-1;
		}
		else{
			piso=vetor[meio];
			i_min=meio+1;
		}
	}
	
	printf("Vetor:\n");
	for(int i=0; i<k; i++)
		printf("%d ", vetor[i]);
	
	printf("\nPiso: %d\nTeto: %d\n", piso, teto);
	return 0;
}

