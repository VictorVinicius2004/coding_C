/*Gere um array com N valores inteiros sorteados entre 0 e 99. Após isso, peça ao usuário um valor X e
verifique se há no array um par de valores (V1 e V2), tal que:
V1 - V2 == X; ou V1 * V2 == X;
V1 + V2 == X; ou V1 / V2 == X;
Imprima todos os pares (V1 e V2) que satisfaça alguma dessas condições.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	//srand(time(NULL));
	int n, x;
	printf("Digite a quantidade de valores a serem gerados.\n");
	scanf(" %d", &n);
	printf("digite um valor x.\n");
	scanf(" %d", &x);
	
	int vetor[n];
	for(int i=0; i<n; i++)
		vetor[i]=rand()%100;
	
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(vetor[i]>vetor[j]){
				int aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
			
	printf("Vetor:\n");
	for(int i=0; i<n; i++)
		printf("%d ", vetor[i]);
	printf("\n");
	
	int antes=0, depois=n-1;
		while(1){
			int meio=antes+(depois-antes)/2;
			
			if(vetor[meio]==x){
				antes=meio;
				depois=meio;
				break;
			}
			else if(vetor[meio]<x)
				antes=meio;
			else
				depois=meio;
			if(depois-antes==1)
				break;
		}

	printf("\ncasos v1-v2==x:\n");
	if(x>=-99 && x<=99)
		for(int i=n-1; i>=0; i--){
			if(vetor[i]<x)
				break;
			if(vetor[i]==vetor[i-1] && i!=0)
				continue;
				
			for(int j=0; j<n; j++){
				if(vetor[i]-vetor[j]<x)
					break;
				if((vetor[j]==vetor[j+1] && j!=n-1) || j==i)
					continue;
				if(vetor[i]-vetor[j]==x)
					printf("%02d - %02d == %d\n", vetor[i], vetor[j], x);
			}
		}
		
	printf("\ncasos v1*v2==x:\n");
	if(x>=0 && x<=(99*99))
		for(int i=antes+1; i>=0; i--){
			int fim=0;
			if(vetor[i]==vetor[i-1] && i!=0)
				continue;
				
			for(int j=0; j<=antes+1; j++){
				if(vetor[i]*vetor[j]>x)
					break;
				if((vetor[j]==vetor[j+1] && vetor[j]!=antes) || i==j)
					continue;
				if(vetor[i]*vetor[j]==x)
					printf("%02d * %02d == %d\n", vetor[i], vetor[j], x);
				if(j>=i){
					fim=1;
					break;
				}
			}
			if(fim)
				break;
		}
		
	printf("\ncasos v1+v2==x:\n");
	if(x>=0 && x<=198)
		for(int i=antes; i>=0; i--){
			int fim=0;
			if(vetor[i]==vetor[i-1] && i!=0)
				continue;
				
			for(int j=0; j<=antes; j++){
				if(vetor[i]+vetor[j]>x)
					break;
				if(vetor[j]==vetor[j+1])
					continue;
				if(vetor[i]+vetor[j]==x)
					printf("%d + %d == %d\n", vetor[i], vetor[j], x);
				if(j>=i){
					fim=1;
					break;
				}
			}
			if(fim)
				break;
		}
		
	printf("\ncasos v1/v2==x:\n");
	if(x>=0 && x<=99)
		for(int i=n-1; i>=depois-1; i--){
			if(vetor[i]==vetor[i-1] && i!=depois-1)
				continue;

			for(int j=0; j<=n-1; j++){
				if((vetor[j]==vetor[j+1] && j!=antes+1) || vetor[j]==0)
					continue;
				if((float)vetor[i]/vetor[j]<x)
					break;
				if((float)vetor[i]/vetor[j]==x)
					printf("%d / %d == %d\n", vetor[i], vetor[j], x);
			}
		}
	return 0;
}

