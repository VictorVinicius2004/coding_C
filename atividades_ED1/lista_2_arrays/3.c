/*Faça um programa que preencha um vetor com N números inteiros aleatórios, sorteados no intervalo
entre 0 e X. O programa deve imprimir os números sorteados, e ao final o seguinte resumo:
a) Quantos números distintos foram sorteados.
b) As posições (índices) do maior e do menor valor.
c) O(s) número(s) mais vezes sorteado, e quantas vezes.
d) O(s) número(s) menos vezes sorteado, e quantas vezes.*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	srand(time(NULL));
	int n, x;
	printf("Digite o valor de n e x respectivamente:\n");
	scanf(" %d %d", &n, &x);
	
	//sorteando o vetor e pegando o maior e o menor
	int vetor[n], maior, menor, p_maior, p_menor;
	printf("vetor: ");
	for(int i=0; i<n; i++){
		vetor[i]=rand()%x;
		printf("%02d ", vetor[i]);
		
		if(i==0){
			maior=vetor[i];
			menor=vetor[i];
			p_maior=i;
			p_menor=i;
		}
		else{
			if(maior<vetor[i]){
				maior=vetor[i];
				p_maior=i;
			}
			if(menor>vetor[i]){
				menor=vetor[i];
				p_menor=i;
			}
		}
	}
	
	//a) c) e d)
	int mais_repetido, menos_repetido, vezes_mais_repetido=0, vezes_menos_repetido=n+1;
	printf("\n\nNúmeros distintos: ");
	for(int i=0; i<n; i++){
		int repetido=0;
		for(int j=0; j<i; j++)
			if(vetor[i]==vetor[j]){
				repetido=1;
				break;
			}
			
		if(!repetido){
			printf("%02d ", vetor[i]);
			
			//c) e d)
			int cont1=0, cont2=0;
			int num1=vetor[i];
			int num2=vetor[i];
			for(int j=0; j<n; j++){
				//mais repetido
				if(vetor[j]==num1)
					cont1++;
				
				//menos repetido
				if(vetor[j]==num2)
					cont2++;
			}
			
			if(cont1>vezes_mais_repetido){
				vezes_mais_repetido=cont1;
				mais_repetido=num1;
			}
			if(cont2<vezes_menos_repetido){
				vezes_menos_repetido=cont2;
				menos_repetido=num2;
			}
		}
	}
	
	//b)
	printf("\n\nPosição do menor número: %d \nPosição do maior número: %d\n\n", p_menor, p_maior);
	
	//c)
	printf("Número mais sorteado: %d(%d vezes)\n", mais_repetido, vezes_mais_repetido);
	
	//d)
	printf("Número menos sorteado: %d(%d vezes)\n", menos_repetido, vezes_menos_repetido);
	return 0;
}

