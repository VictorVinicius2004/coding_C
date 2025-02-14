#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[50], curso[50];
	int matricula;
	float notas[10];
}Aluno;

float calculo_media(Aluno aluno){
	int media=0;
	for(int i=0; i<10; i++)
		media+=aluno.notas[i];
	return media/=10;
}

int main(){
	Aluno cadastros[100];
	
	printf("Recebendo dados...\n");
	int contalunos=0;
	do{
		printf("Nome('exit' para sair): ");
		scanf(" %[^\n]s", cadastros[contalunos].nome);
		if(!strcmp(cadastros[contalunos].nome, "exit")) break;
		
		printf("Curso: ");
		scanf(" %[^\n]s", cadastros[contalunos].curso);
		
		printf("N° de matrícula: ");
		scanf(" %d", &cadastros[contalunos].matricula);
		
		contalunos++;
	}while(contalunos<100);
	system("clear");
	printf("Dados cadastrados\n\n");
	
	for(int i=0; i<contalunos-1; i++)
		for(int j=i+1; j<contalunos; j++)
			if(cadastros[i].matricula>cadastros[j].matricula){
				Aluno aux=cadastros[i];
				cadastros[i]=cadastros[j];
				cadastros[j]=aux;
			}
			
	do{
		int inicio=0, fim=contalunos-1, meio;
		int num;
		printf("Digite um N° de matrícula(-1 para sair): ");
		scanf(" %d", &num);
		if(num==-1) break;
		
		do{
		meio=(inicio+fim)/2;
		if(cadastros[meio].matricula==num){
			printf("Nome: %s \nCurso: %s \nMatrícula: %d \nMédia: %.2f\n\n",
				cadastros[meio].nome,
				cadastros[meio].curso,
				cadastros[meio].matricula,
				calculo_media(cadastros[meio]));
				
			int esc;
			printf("Deseja lancar as notas do aluno? 0-não, 1-sim\n");
			scanf(" %d", &esc);
			if(esc)
				for (int i = 0; i < 10; i++){
					printf("Nota %d: ", i+1);
					scanf(" %f", &cadastros[meio].notas[i]);
				}
			system("clear");
			break;
		}
		else if(cadastros[meio].matricula>num)
			fim=meio-1;
		else
			inicio=meio+1;
		}while(inicio<=fim);
	}while(1);
	return 0;
}

