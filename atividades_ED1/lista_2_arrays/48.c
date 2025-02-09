/*Gere uma matriz 10 x 100, com números aleatórios entre 1 e 4, que se refere às respostas de 10 questões
de múltipla escolha, referentes a 100 alunos. Leia (a partir do usuário) um vetor de 10 posições contendo
o gabarito de respostas corretas. O seu programa deverá comparar as respostas de cada candidato com o
gabarito, e emitir a nota final de cada aluno. O programa também deverá informar: qual foi a média das
notas, a maior nota, quantos alunos atingiram a maior nota e quantos alunos atingiram a menor nota.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum ALTERNATIVAS{A=1, B, C, D};

int main(){
	int respostas[10][100], gabarito[10], alunos[100]={0};
	printf("Digite o gabarito:\n");
	for(int i=0; i<10; i++){
		char alternativa;
		printf("Alternativa %d(A, B, C, D): ", i+1);
		scanf(" %c", &alternativa);
		
		switch(alternativa){
			case 'A': gabarito[i]=A; break;
			case 'B': gabarito[i]=B; break;
			case 'C': gabarito[i]=C; break;
			case 'D': gabarito[i]=D; break;
			default: printf("Inválido\n"); i--;
		}
	}
	
	
	int media=0, maior_nota=0, menor_nota=10;
	printf("\nNotas:\n");
	for(int j=0; j<100; j++){
		for(int i=0; i<10; i++){
			respostas[i][j]=rand()%4+1;
			
			alunos[j] += respostas[i][j]==gabarito[i]? 1 : 0;
		}
		
		printf("Aluno %03d: %02d\n", j+1, alunos[j]);
		
		media+=alunos[j];
		
		if(alunos[j]>maior_nota)
			maior_nota=alunos[j];
		if(alunos[j]<menor_nota)
			menor_nota=alunos[j];
	}
	
	media/=100;
	int qntd_maiornota=0, qntd_menornota=0;
	for(int i=0; i<100; i++){
		if(alunos[i]==maior_nota)
			qntd_maiornota++;
		if(alunos[i]==menor_nota)
			qntd_menornota++;
	}
	
	printf("Média das notas: %d\n", media);
	printf("Maior nota: %d \nQuantidade de alunos que atingiram a maior nota: %d\n", maior_nota, qntd_maiornota);
	printf("Menor nota: %d \nQuantidade de alunos que atingiram a menor nota: %d", menor_nota, qntd_menornota);
	return 0;
}

