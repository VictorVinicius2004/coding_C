/*Faça um programa que leia o Nome e a Idade de N pessoas. Imprima a relação de nomes ordenada pelas
idades de forma decrescente.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30];
	int idade;
}Pessoas;

int main(){
	int n;
	printf("Digite a quantidade de pessoas\n");
	scanf(" %d", &n);
	
	Pessoas pessoas[n];
	for(int i=0; i<n; i++){
		printf("%d° Pessoa: \nNome: ", i+1);
		scanf(" %[^\n]s", pessoas[i].nome);
		printf("idade: ");
		scanf(" %d", &pessoas[i].idade);
		system("clear");
	}
	
	for(int i=1; i<n; i++){
		Pessoas temp=pessoas[i];
		int j;
		
		for(j=i-1; j>=0; j--){
			if(temp.idade<=pessoas[j].idade)
				break;
			pessoas[j+1]=pessoas[j];
		}
		pessoas[j+1]=temp;
	}
	
	printf("lista ordenada em ordem decrescente em relação a idade.\n");
	for(int i=0; i<n; i++)
		printf("%d° Pessoa: \nNome: %s \nIdade: %d\n\n", i+1, pessoas[i].nome, pessoas[i].idade);
	return 0;
}

