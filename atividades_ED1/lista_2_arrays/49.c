/*Considere N x N valores aleatórios sorteados no intervalo entre 1
e 20, que representam o peso de contêineres para transporte,
distribua-os no navio cargueiro de modo que o peso das cargas
fique relativamente equilibrado, conforme ilustração a seguir.
Imprima também o valor do peso total de cada coluna de
contêineres embarcados.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int n;
	printf("Digite a ordem da matriz: ");
	scanf(" %d", &n);
	
	int conteiners[n][n], vetor_controle[n*n], cont=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			conteiners[i][j]=rand()%20+1;
			vetor_controle[cont++]=conteiners[i][j];
		}
		
	for(int i=0; i<n*n; i++){
		int temp=vetor_controle[i], j;
		
		for(j=i-1; j>=0; j--){
			if(temp>=vetor_controle[j])
				break;
			vetor_controle[j+1]=vetor_controle[j];
		}
		vetor_controle[j+1]=temp;
	}
	
	int inicio=0, fim=n-1;
	for(int i=0; i<n; i++){
		int j=0;
		if(i%2==0)
			for(int k=inicio; k<=fim; k++)
				conteiners[i][j++]=vetor_controle[k];	
		else
			for(int k=fim; k>=inicio; k--)
				conteiners[i][j++]=vetor_controle[k];
		
		inicio+=n;
		fim+=n;
	}
	
	int valores_colunas[n];
	for(int i=0; i<n; i++)
		valores_colunas[i]=0;
	for(int j=0; j<n; j++)
		for(int i=0; i<n; i++)
			valores_colunas[j]+=conteiners[i][j];
	
	printf("Conteiners:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%02d ", conteiners[i][j]);
		printf("\n");
	}
	
	printf("Soma das colunas:\n");
	for(int i=0; i<n; i++)
		printf("%02d ", valores_colunas[i]);
	return 0;
}

