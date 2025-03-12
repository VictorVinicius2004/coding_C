/*PROJETO SISTEMA ACADEMICO
FACA UM PROGRAMA QUE IMPLEMENTE DUAS STRUCTS:
	DISCENTE: NOME:S, MATRICULA:I, NOTAS:A, COEF.RENDIMENTO:F
	DISCIPLINAS: COD:I, NOME:S, CH:I, DISCENTES:A
OPÇÕES NA INTERFACE:
	1 - CADASTRAR DISCIPLINA
	2 - CADASTRAR ALUNO
	3 - MATRICULAR ALUNO
	4 - LANÇAR NOTAS
	5 - DIARIO DA DISCIPLINA
	6 - HISTORICO DO ALUNO
	7 - RANKING DE CR
REQUISITOS:
	MATRICULA(DISCENTE) E COD(DISCIPLINA) SÃO CAMPOS CHAVE.
	MATRICULA EM CADA DISCIPLINA DEVE SER UNICA.
	NOTA EM CADA DISCIPLINA DEVE SER UNICA.
	DIARIO DA DISCIPLINA DEVE IMPRIMIR TODOS OS ALUNOS 
		MATRICULADOS E SUAS RESPECTIVAS NOTAS
	HISTORICO DO ALUNO DEVE IMPRIMIR TODOS SUAS DISCIPLINAS 
		 SUAS RESPECTIVAS NOTAS
	RANKING DE CR, RELATORIO DE ALUNOS
		ORDENADO DE FORMA DECRESCENTE POR CR*/


//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs
typedef struct{
	float nota;
	int curso;
}Nota; 

typedef struct{
	char nome[50];
	int matricula;
	Nota notas[5];
	int disciplinas_matriculadas;
	float cr;
}Discente;

typedef struct{
	int codigo, ch, alunos_matriculados;
	int discentes[50];
	char nome[50];
}Disciplina;

//implementação
//funções auxiliares
int busca_aluno(Discente discentes[], int cont, int matricula){
	for(int i=0; i<cont; i++)
		if(discentes[i].matricula==matricula)
			return i;
	return -1;
}

int busca_disciplina(Disciplina disciplinas[], int cont, int codigo){
	for(int i=0; i<cont; i++)
		if(codigo==disciplinas[i].codigo)
			return i;
	return -1;
}

int busca_aluno_na_disciplina(Discente dicente, int codigo){
	for(int i=0; i<5; i++)
		if(dicente.notas[i].curso==codigo)
			return i;
	return -1;
}

int verifica_aluno_disciplina(int cont_aluno, int cont_disciplina){
	if(cont_aluno==0){
		printf("Não há alunos cadastrados\n");
		return 0;
	}
	if(cont_disciplina==0){
		printf("Não há disciplinas cadastradas");
		return 0;
	}
	return 1;
}

void sort_cr(Discente discentes[], int cont){
	for(int i=0; i<cont-1; i++)
		for(int j=i+1; j<cont; j++)
			if(discentes[i].cr<discentes[j].cr){
				Discente aux=discentes[i];
				discentes[i]=discentes[j];
				discentes[j]=aux;
			}
}

void calculo_cr(Discente discentes[], int cont){
	for(int i=0; i<cont; i++){
		int soma=0;
		
		for(int j=0; j<5; j++)
			soma+=discentes[i].notas[j].nota;
		
		discentes[i].cr = soma/discentes[i].disciplinas_matriculadas;
	}
}

//funções principais
void cadastro_disciplinas(Disciplina disciplinas[], int *cont){
	do{
		int codigo, conttemp=*cont;
		printf("código: ");
		scanf(" %d", &codigo);

		int repetido = busca_disciplina(disciplinas, conttemp, codigo);
			
		if(repetido==-1)
			disciplinas[*cont].codigo=codigo;
		else{
			system("clear");
			printf("Código já existente\n");
			continue;
		}
		printf("Nome: ");
		scanf(" %[^\n]s", disciplinas[*cont].nome);
		printf("Carga horária: ");
		scanf(" %d", &disciplinas[*cont].ch);
		disciplinas[*cont].alunos_matriculados=0;
		
		system("clear");
		*cont+=1;
		printf("Cadastro realizado\n");
		
		int escolha;
		printf("Deseja sair? 0-não, 1-sim\n");
		do{
			scanf(" %d", &escolha);
		}while(escolha!=0 && escolha!=1);
		if(escolha){
			system("clear");
			break;
		}
	}while(1);
}

void cadastro_discentes(Discente discentes[], int *cont){
	do{
		int matricula, conttemp=*cont;
		printf("Matrícula: ");
		scanf(" %d", &matricula);

		int repetido = busca_aluno(discentes, conttemp, matricula);
			
		if(repetido==-1)
			discentes[*cont].matricula=matricula;
		else{
			system("clear");
			printf("Código já existente\n");
			continue;
		}
		printf("nome: ");
		scanf(" %[^\n]s", discentes[*cont].nome);

		discentes[*cont].disciplinas_matriculadas=0;
		for(int i=0; i<5; i++){
			discentes[*cont].notas[i].nota=0;
			discentes[*cont].notas[i].curso=-1;
		}
		system("clear");
		*cont+=1;
		printf("Cadastro realizado\n");
		
		int escolha;
		printf("Deseja sair? 0-não, 1-sim\n");
		do{
			scanf(" %d", &escolha);
		}while(escolha!=0 && escolha!=1);
		if(escolha){
			system("clear");
			break;
		}
	}while(1);
}

void matricula_aluno(Discente discentes[], Disciplina disciplinas[], int cont_discentes, int cont_disciplinas){
	do{
		int matricula;
		printf("digite a matrícula do aluno(-1 para encerrar a matrícula): ");
		scanf(" %d", &matricula);
		if(matricula==-1){
			system("clear");
			break;
		}
		int pos = busca_aluno(discentes, cont_discentes, matricula);
		if(pos!=-1){
			if(discentes[pos].disciplinas_matriculadas<5){
				do{
					int codigo;
					printf("digite o código da disciplina que deseja matricular(-1 para sair): ");
					scanf(" %d", &codigo);
					if(codigo==-1){
						system("clear");
						break;
					}
					int matriculado = busca_aluno_na_disciplina(discentes[pos], codigo);
					if(matriculado==-1){
						int disc = busca_disciplina(disciplinas, cont_disciplinas, codigo);
						if(disc!=-1){
							disciplinas[disc].discentes[disciplinas[disc].alunos_matriculados++]=discentes[pos].matricula;
							discentes[pos].notas[discentes[pos].disciplinas_matriculadas++].curso=disciplinas[disc].codigo;
							system("clear");
							printf("Matrícula realizada\n");
							break;
						}
						else
							printf("Código inválido\n");
					}
					else
						printf("Aluno já matriculado nesta disciplina\n");
				}while(1);
			}
			else
				printf("O discente atingiu o máximo de disciplinas matriculadas\n");
		}
		else
			printf("matrícula inválida\n");
	}while(1);
}

void lancar_notas(Discente discentes[], Disciplina disciplinas[], int cont_discentes, int cont_disciplinas){
	do{
		int codigo;
		printf("Digite a o código da disciplina(-1 para sair): ");
		scanf(" %d", &codigo);
		if(codigo==-1){
			system("clear");
			break;
		}
		
		int pos_disciplina = busca_disciplina(disciplinas, cont_disciplinas, codigo);
		if(pos_disciplina!=-1){
			do{
				int matricula;
				printf("digite o código do aluno(-1 para sair): ");
				scanf(" %d", &matricula);
				if(matricula==-1){
					system("clear");
					break;
				}
				
				int pos_discente = busca_aluno(discentes, cont_discentes, matricula);
				if(pos_discente!=-1){
					int pos_nota = busca_aluno_na_disciplina(discentes[pos_discente], codigo);
					if(pos_nota!=-1){
						int nota;
						printf("Digite a nota(0 a 100): ");
						do{
							scanf(" %d", &nota);
						}while(nota<0 || nota>100);
						discentes[pos_discente].notas[pos_nota].nota=nota;
					}
					else
						printf("aluno não pertence a disciplina\n");
				}
				else
					printf("Matrícula inválida\n");
			}while(1);
		}
		else
			printf("código inválido\n");
	}while(1);
}

void diario_disciplina(Disciplina disciplinas[], int cont){
	if(cont)
		for(int i=0; i<cont; i++){
			printf("Nome: %s\n", disciplinas[i].nome);
			printf("Código: %d\n", disciplinas[i].codigo);
			printf("Carga horária: %d\n", disciplinas[i].codigo);
			printf("Alunos matriculados: %d\n\n", disciplinas[i].alunos_matriculados);
		}
	else
		printf("Nenhuma disciplina cadastrada\n");
		
	while(getchar()!='\n');
	printf("Aperte ENTER para continuar");
	getchar();
	system("clear");
}

void historico_discente(Discente discentes[], int cont){
	if(cont){
		do{
			int matricula;
			printf("Digite o código do discente(-1 para encerrar): ");
			scanf(" %d", &matricula);
			if(matricula==-1){
				system("clear");
				break;
			}
			
			int pos=busca_aluno(discentes, cont, matricula);
			if(pos!=-1){
				printf("Nome: %s\n", discentes[pos].nome);
				printf("Matrícula: %d\n", discentes[pos].matricula);
				printf("Notas:\n");
				for(int j=0; j<5; j++)
					if(discentes[pos].notas[j].curso!=-1)
						printf("matricula: %d   nota: %.2f\n", discentes[pos].notas[j].curso, discentes[pos].notas[j].nota);
				printf("Coeficiente de rendimento: %.2f\n\n", discentes[pos].cr);
				
				while(getchar()!='\n');
				printf("Aperte ENTER para continuar");
				getchar();
				system("clear");
			}
			else
				printf("Matrícula inválida\n");
		}while(1);
	}
	else
		printf("Nenhum aluno cadastrado\n");
}

void ranking_cr(Discente discentes[], int cont){
	printf("Ranking CR:\n");
	for(int i=0; i<cont; i++)
		printf("Nome: %s \nCoeficiente de rendimento: %.2f\n\n", discentes[i].nome, discentes[i].cr);
	
	while(getchar()!='\n');
	printf("Aperte ENTER para continuar");
	getchar();
	system("clear");
}

int interface(){
	printf("Escolha:\n");
	printf("1 - CADASTRAR DISCIPLINA\n");
	printf("2 - CADASTRAR ALUNO\n");
	printf("3 - MATRICULAR ALUNO\n");
	printf("4 - LANÇAR NOTAS\n");
	printf("5 - DIARIO DA DISCIPLINA\n");
	printf("6 - HISTORICO DO ALUNO\n");
	printf("7 - RANKING DE CR\n");
	printf("8 - ENCERRAR PROGRAMA\n");
	
	int escolha;
	do{
		scanf(" %d", &escolha);
	}while(!(escolha>=1 && escolha<=8));
	system("clear");
	return escolha;
}

int main(){
	Disciplina disciplinas[50];
	Discente discentes[200];
	int cont_discentes=0;
	int cont_disciplinas=0;
	
	do{
		int saida=0;
		switch(interface()){
			case 1:
				cadastro_disciplinas(disciplinas, &cont_disciplinas);
				break;
			case 2:
				cadastro_discentes(discentes, &cont_discentes);
				break;
			case 3:
				if(verifica_aluno_disciplina(cont_discentes, cont_disciplinas))
					matricula_aluno(discentes, disciplinas, cont_discentes, cont_disciplinas);
				break;
			case 4:
				if(verifica_aluno_disciplina(cont_discentes, cont_disciplinas))
					lancar_notas(discentes, disciplinas, cont_discentes, cont_disciplinas);
				calculo_cr(discentes, cont_discentes);
				break;
			case 5:
				diario_disciplina(disciplinas, cont_disciplinas);
				break;
			case 6:
				historico_discente(discentes, cont_discentes);
				break;
			case 7:
				sort_cr(discentes, cont_discentes);
				ranking_cr(discentes, cont_discentes);
				break;
			case 8:
				saida=1;
		}
		if(saida) break;
	}while(1);
	return 0;
}
