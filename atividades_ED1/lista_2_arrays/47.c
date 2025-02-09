/*Crie um programa que leia o nome de N alunos. Após isto, para cada aluno cadastrado, imprima o nome
e solicite ao usuário os valores das notas da prova 1, prova 2 e prova 3. Ao final, o programa deverá gerar
um relatório em formato de lista, contendo NOME, NOTA 1, NOTA 2, NOTA 3, MÉDIA, e se está
APROVADO ou REPROVADO.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[35];
	int notas[3];
}Aluno;

int main(){
	int n;
	printf("Digite a quantidade de alunos: ");
	scanf(" %d", &n);
	
	Aluno alunos[n];
	for(int i=0; i<n; i++){
		printf("Aluno %d: \nNome: ", i+1);
		scanf(" %[^\n]s", alunos[i].nome);
		
		int j=0;
		while(j<3){
			printf("Nota %d(0 a 100): ", j+1);
			scanf(" %d", &alunos[i].notas[j]);
			if(alunos[i].notas[j]>=0 && alunos[i].notas[j]<=100)
				j++;
		}
		system("clear");
	}
	
	for(int i=0; i<n; i++){
		printf("Aluno: %s\n", alunos[i].nome);
		printf("Nota1: %d \nNota2: %d \nNota3: %d\n", alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2]);
		
		int media=0;
		for(int j=0; j<3; j++)
			media+=alunos[i].notas[j];
		media/=3;
		
		printf("Média: %d \nSituação: ", media);
		media>=60? printf("APROVADO\n") : printf("REPROVADO\n");
		printf("---------------------------------\n");
	}
	return 0;
}

