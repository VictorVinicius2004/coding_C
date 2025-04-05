#include <stdio.h>
#include <stdlib.h>

FILE *abrirarquivo(char *nome);//abre o arquivo, se não existir ele o cria
void cadastro_discente(FILE *discentes); //cadastra um novo discente no arquivo

typedef struct{
	int codigo;
	char nome[50];
	int disciplinas[10];
}Discente;

typedef struct{
	int codigo;
	char professor[50];
	char nome[50];
	int discentes[50];
}Disciplina;

FILE *abrirarquivo(char *nome){
	FILE *arq = NULL;
	arq = fopen(nome, "rb+");
	if(!arq)
		fopen(nome, "wb+");
	if(!arq)
		printf("Erro ao gerar arquivo\n");
	return arq;
}

int procurar_discente(int codigo_alvo, FILE *discentes){
	Discente alvo;
	fseek(discentes,0,SEEK_SET);
	while(fread(&alvo,sizeof(Discente),1,discentes))
		if(alvo.codigo==codigo_alvo)
			return 1;
			
	return 0;
}

void cadastro_discente(FILE *discentes){
	Discente novo_discente;
	printf("digite o nome do discente\n");
	scanf(" %s", novo_discente.nome);
	
	do{
		int code = rand()%10000;
		
		if(!procurar_discente(code,discentes)){
			fseek(discentes, 0, SEEK_END);
			novo_discente.codigo=code;
			fwrite(&novo_discente,sizeof(Discente), 1, discentes);
			fflush(discentes);
			break;
		}
	}while(1);
	
	
}

int interface(){
	system("clear");
	printf("1-Cadastrar discente\n");
	printf("2-Cadastrar  disciplina\n");
	printf("3-relatório discentes\n");
	printf("4-Matricular discentes\n");
	printf("5-Sair\n");
	
	int escolha;
	scanf(" %d", &escolha);
	
	return escolha;
}

int main(){
	FILE* discentes = abrirarquivo("discentes.dat");
	FILE* disciplinas = abrirarquivo("disciplinas.dat");
	
	do{
		int sair = 0;
		switch(interface()){
			case 1: cadastro_discente(discentes);
					break;
			case 2:
			case 3:
			case 4:
			case 5: fclose(discentes);
					fclose(disciplinas);
					sair = 1;
					break;
			case 666: remove("nomedoarquivo.dat");
			default: printf("Opção inválida\n");
		}
		if(sair)
			break;
	}while(1);
	
	return 0;
}
