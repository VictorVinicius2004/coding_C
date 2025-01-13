/*Faça um programa que alimenta um array de N inteiros sorteados entre 1 e 10, e onde cada valor
representa o número de chocolates em um pacote. Considerando que existam M alunos (M < N) na
turma, a tarefa do seu programa é informar quais pacotes de chocolate devem ser distribuídos de forma
que: (i) cada aluno deve receber apenas um pacote; (ii) A diferença entre a quantidade de chocolates que
cada aluno irá receber deve ser a mínima possível. Em caso de empate a
distribuição deve ser dos pacotes que contiverem mais chocolates.*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	srand(time(NULL));
	int num_pacotes, num_alunos;
	do{
		printf("Digite a quantidade de pacotes de chocolate a serem gerados(min 2).\n");
		scanf(" %d", &num_pacotes);
	}while(num_pacotes<2);
	do{
		printf("Digite a quantidade de alunos(alunos<pacotes).\n");
		scanf(" %d", &num_alunos);
	}while(num_alunos>=num_pacotes);
	
	int pacotes[num_pacotes], alunos[num_alunos];
	for(int i=0; i<num_pacotes; i++)
		pacotes[i]=rand()%10+1;
	
	for(int i=0; i<num_pacotes-1; i++)
		for(int j=i+1; j<num_pacotes; j++)
			if(pacotes[i]>pacotes[j]){
				int aux=pacotes[i];
				pacotes[i]=pacotes[j];
				pacotes[j]=aux;
			}
	printf("Pacotes:\n");
	for(int i=0; i<num_pacotes; i++)
		printf("%d ", pacotes[i]);
	printf("\n");
	
	int menorsoma=10, inicio, fim;
	for(int i=num_pacotes-1; i>=num_alunos-1; i--){
		if(pacotes[i]-pacotes[i-num_alunos+1]<menorsoma){
			menorsoma=pacotes[i]-pacotes[i-num_alunos+1];
			inicio=i-num_alunos+1;
			fim=i;
		}
	}
	
	int cont=0;
	printf("Pacotes distribuidos entre os alunos:\n");
	for(int i=inicio; i<=fim; i++){
		alunos[cont++]=pacotes[i];
		printf("%d ", alunos[cont-1]);
	}
	return 0;
}

