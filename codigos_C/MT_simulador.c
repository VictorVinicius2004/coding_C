#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char estado_atual[10];
    char simbolo_atual;
    char novo_estado[10];
    char novo_simbolo;
    int direcao;
    int excluido;
}Funcao;

enum {RIGHT, LEFT};

#define TAMANHO_FITA 200
#define INICIO_CONTEUDO 90

void espera_enter(char *msg){
    printf("%s\nPressione ENTER para continuar\n",msg);
    setbuf(stdin,NULL);
    getchar();
}

FILE *abrir_arquivo(int criar_arquivo){
    char nome[60];
    printf("Digite o nome do arquivo\n");
    scanf(" %59s", nome);

    FILE *arq = NULL;
    arq = fopen(nome, "rb+");
    if(!arq && criar_arquivo){
        arq = fopen(nome, "wr+");
        espera_enter("Arquivo criado");
	}
    if(!arq && !criar_arquivo)
        espera_enter("Arquivo não encontrado\n");
    return arq;
}

int procurar_regra(FILE *mt, int num){
	int cont=1;
	Funcao temp;
	fseek(mt,0,SEEK_SET);
	while(fread(&temp,sizeof(Funcao),1,mt)){
		if(cont==num && !temp.excluido){
			fseek(mt,-sizeof(Funcao),SEEK_CUR);
			return 1;
		}
		if(!temp.excluido)
			cont++;
	}
	return 0;
}

void nova_regra(FILE *mt){
    do{
		system("clear");
        fseek(mt,0,SEEK_END);
        Funcao new;
        new.excluido=0;
        printf("Estado atual(SAIR para sair): ");
        scanf(" %9s", new.estado_atual);
        if(!strcmp("SAIR",new.estado_atual))
            return;
        printf("Símbolo atual(Utilize 'B' para espaço vazio): ");
        scanf(" %c", &new.simbolo_atual);
        printf("Novo estado: ");
        scanf(" %9s", new.novo_estado);
        printf("Novo símbolo: ");
        scanf(" %c", &new.novo_simbolo);
        do{
            printf("Direção de avanço(%d-Direita, %d-esquerda): ",RIGHT, LEFT);
            scanf(" %d", &new.direcao);
            while(getchar()!='\n');
        }while(new.direcao!=RIGHT && new.direcao!=LEFT);

        int escolha;
        printf("\n1) confirmar \n2)cancelar \nDigite: ");
        scanf(" %d", &escolha);
        if(escolha==1){
            fwrite(&new,sizeof(Funcao),1,mt);
            fflush(mt);
        }
    }while(1);
}

void print_funcao(Funcao temp){
	printf("(%s,%c) -> (%s,%c,",temp.estado_atual,temp.simbolo_atual,temp.novo_estado,temp.novo_simbolo);
		if(temp.direcao==RIGHT)
			printf("->)\n");
		else
			printf("<-)\n");
}

void print_regras(FILE *mt){
	int cont=1;
	Funcao temp;
	fseek(mt,0,SEEK_SET);
	printf("(estado atual, símbolo atual) -> (novo estado, novo símbolo, direção)\n");
	while(fread(&temp,sizeof(Funcao),1,mt)){
		if(temp.excluido)
			continue;
		printf("%d. ",cont);
		print_funcao(temp);
		cont++;
	}
}

void excluir_regra(FILE *mt){
	print_regras(mt);
	int num;
	do{
		printf("Digite o número da regra que deseja excluir(-1 para sair): ");
		scanf(" %d", &num);
		if(num==-1)
			return;
		if(procurar_regra(mt,num)){
			Funcao temp;
			fread(&temp,sizeof(Funcao),1,mt);
			temp.excluido=1;
			fseek(mt,-sizeof(Funcao),SEEK_CUR);
			fwrite(&temp,sizeof(Funcao),1,mt);
		}
	}while(1);
}

int interface_edicao(){
    printf("1) Vizualizar regras de transição\n");
    printf("2) Excluir regra\n");
    printf("3) Criar nova regra\n");
    printf("4) Sair\n");
    printf("Digite: ");
    int escolha;
    scanf(" %d", &escolha);
    return escolha;
}

void editar_MT(FILE *mt){
    do{
        system("clear");
        switch(interface_edicao()){
            case 1:
				print_regras(mt);
				espera_enter("");
                break;
            case 2:
				excluir_regra(mt);
                break;
            case 3:
                nova_regra(mt);
                break;
            case 4:
                fclose(mt);
                return;
        }
    }while(1);
}

int definir_inicio_fim(FILE *mt, char q0[], char aceitacao[]){
	printf("Estado de inicial(SAIR para cancelar): ");
	scanf(" %s", q0);
	if(!strcmp("SAIR",q0))
		return 0;
	printf("Estado de aceitação: ");
	scanf(" %s", aceitacao);
	return 1;
}

void limpa_fita(char fita[]){
	for(int i=0; i<TAMANHO_FITA; i++)
		fita[i]='B';
}

int definir_fita(char fita[]){
	char conteudo[65];
	printf("Digite o conteúdo da fita(SAIR para sair):\n");
	scanf(" %64s", conteudo);
	if(!strcmp("SAIR",conteudo))
		return 0;
		
	limpa_fita(fita);
	
	int cont=0;
	for(int i=INICIO_CONTEUDO; i<strlen(conteudo)+INICIO_CONTEUDO; i++)
		fita[i]=conteudo[cont++];
	return 1;
}

void print_fita(char fita[], int posicao){
	for(int i=0; i<TAMANHO_FITA; i++){
		if(i==posicao){
			if(fita[i]=='B')
				printf("{ }");
			else
				printf("{%c}", fita[i]);
		}
		else if(fita[i]!='B'){
			printf("%c", fita[i]);
		}
	}
	printf("\n");
}

int vasculhar_regras(FILE *mt, char estado[], char simbolo){
	Funcao temp;
	int cont=1;
	fseek(mt,0,SEEK_SET);
	while(fread(&temp,sizeof(temp),1,mt)){
		if(!strcmp(temp.estado_atual,estado) && temp.simbolo_atual==simbolo && !temp.excluido){
			fseek(mt,-sizeof(Funcao),SEEK_CUR);
			return cont;
		}
		
		if(!temp.excluido)
			cont++;
	}
	return 0;
}

void verifica_final(char estado[], char f[]){
	if(!strcmp(estado,f))
		espera_enter("Válido");
	else
		espera_enter("Inválido");
}

void execucao_MT(FILE *mt, char fita[], char estado[], char f[]){
	char copia_fita[TAMANHO_FITA];
	char copia_estado[10];
	strcpy(copia_fita,fita);
	strcpy(copia_estado,estado);
	int posicao=INICIO_CONTEUDO;
	
	do{
		system("clear");
		print_fita(copia_fita,posicao);
		if(!vasculhar_regras(mt,copia_estado,copia_fita[posicao])){
			verifica_final(copia_estado,f);
			return;
		}
		Funcao temp;
		fread(&temp,sizeof(Funcao),1,mt);
		print_funcao(temp);
		copia_fita[posicao]=temp.novo_simbolo;
		strcpy(copia_estado,temp.novo_estado);
		if(temp.direcao==RIGHT)
			posicao++;
		else
			posicao--;
		
		printf("1) continuar, 2) interromper execução\n");
		int escolha;
		scanf(" %d",&escolha);
		if(escolha==2)
			return;
	}while(1);
}

int interface_execucao(){
	printf("1) Mostrar funções de transição\n");
	printf("2) Definir estado inicial e de aceitação\n");
	printf("3) Definir conteúdo da fita\n");
	printf("4) executar máquina de turing\n");
	printf("5) Sair\n");
	printf("Digite: ");
	int escolha;
	scanf(" %d", &escolha);
	return escolha;
}

void executar_MT(FILE *mt){
	char fita[TAMANHO_FITA];
	char estado_inicial[10];
	char aceitacao[10];
	int estados_definidos=0;
	int fita_definida=0;
	
	do{
		system("clear");
		switch(interface_execucao()){
			case 1:
				print_regras(mt);
				espera_enter("");
				break;
			case 2:
				estados_definidos = definir_inicio_fim(mt,estado_inicial,aceitacao);
				break;
			case 3:
				fita_definida = definir_fita(fita);
				break;
			case 4:
				if(estados_definidos && fita_definida)
					execucao_MT(mt,fita,estado_inicial,aceitacao);
				else
					espera_enter("Preparações não satisfeitas");
				break;
			case 5:
				fclose(mt);
				return;
		}
	}while(1);
}

int interface(){
    printf("1) Criar ou editar maquina de turing\n");
    printf("2) Executar máquina de Turing\n");
    printf("3) Sair\n");
    printf("Digite: ");
    int escolha;
    scanf(" %d", &escolha);
    return escolha;
}

int main(){
    FILE *mt;
    do{
        system("clear");
        switch(interface()){
            case 1:
                mt = abrir_arquivo(1);
                editar_MT(mt);
                break;
            case 2:
                mt = abrir_arquivo(0);
                if(!mt)
                    return 1;
                executar_MT(mt);
                break;
            case 3:
                return 0;
        }
    }while(1);
}
