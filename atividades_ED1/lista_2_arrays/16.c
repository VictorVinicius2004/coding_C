/*Declare 03 arrays contendo 10 valores aleatórios. Faça a ordenação dos 03 arrays (utilizando o algoritmo
de ordenação preferido). Imprima os 03 arrays ordenados e, após isso, faça a operação “merge”, ou seja,
mescle os valores dos 03 arrays em um único array, mantendo os valores ordenados.
Mas atenção... não deve-se realizar uma quarta ordenação para obter o resultado final.*/


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	srand(time(NULL));
	int array1[10], array2[10], array3[10], resultado[30];
	
	for(int i=0; i<10; i++){
		array1[i]=rand()%100;
		array2[i]=rand()%100;
		array3[i]=rand()%100;
	}
	
	//ordenados os vetores
	for(int i=0; i<9; i++){
		for(int j=i+1; j<10; j++){
			int aux;
			
			if(array1[i]>array1[j]){
				aux=array1[i];
				array1[i]=array1[j];
				array1[j]=aux;
			}
			
			if(array2[i]>array2[j]){
				aux=array2[i];
				array2[i]=array2[j];
				array2[j]=aux;
			}
			
			if(array3[i]>array3[j]){
				aux=array3[i];
				array3[i]=array3[j];
				array3[j]=aux;
			}
		}
	}
	
	printf("Vetor 1: ");
	for(int i=0; i<10; i++)
		printf("%02d ", array1[i]);
	printf("\n");
		
	printf("Vetor 2: ");
	for(int i=0; i<10; i++)
		printf("%02d ", array2[i]);
	printf("\n");
	
	printf("Vetor 3: ");
	for(int i=0; i<10; i++)
		printf("%02d ", array3[i]);
	printf("\n");
	
	//mesclando
	int p1=0, p2=0, p3=0, num1, num2, num3, indice=0;
	while(indice<30){
		num1=(p1<10)?array1[p1]:101;
		num2=(p2<10)?array2[p2]:101;
		num3=(p3<10)?array3[p3]:101;
		
		if(num1<=num2 && num1<=num3){
			resultado[indice++]=num1;
			p1++;
		}
		if(num2<=num1 && num2<=num3){
			resultado[indice++]=num2;
			p2++;
		}
		if(num3<=num1 && num3<=num2){
			resultado[indice++]=num3;
			p3++;
		}
	}
	
	printf("Resultado:\n");
	for(int i=0; i<30; i++)
		printf("%02d ", resultado[i]);
	return 0;
}
