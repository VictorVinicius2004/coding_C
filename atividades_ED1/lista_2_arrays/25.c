/*Programe o sorteio de um “Amigo Oculto” com N participantes. Leia o nome de cada amigo e imprima o
resultado do sorteio. Lembre que um amigo não pode tirar ele mesmo (e cuidado com o último).*/

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
	srand(time(NULL));
	int n;
	printf("Digite o número de participantes:\n");
	scanf(" %d", &n);
	
	char participantes[n][30];
	int sorteados[n];
	printf("Digite o nome dos participantes abaixo:\n");
	for(int i=0; i<n; i++){
		scanf(" %[^\n]s", participantes[i]);
		sorteados[i]=-1;
	}
	
	int cont=0;;
	do{
		int x=rand()%n;
		if(sorteados[x]==-1 && x!=cont){
			sorteados[x]=cont++;
			printf("%s sorteou %s\n", participantes[x], participantes[cont-1]);
		}
	}while(cont<n);
	return 0;
}

