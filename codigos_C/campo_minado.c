//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

//constantes
#define LINHAS 15
#define COLUNAS 11
#define BOMBAS 25

#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define AMARELO "\033[33m"
#define AZUL "\033[34m"
#define FIM_COR "\033[0m"

enum {LIMPO, CHEIO, MARCADO, NEUTRO, VISIVEL};

//structs
typedef struct{
	int bomba;
	int bombas_proximas;
	int estado;
}Campo;

typedef struct{
	int linha;
	int coluna;
}Posicao;

//Variáveis globais 
Campo campo[LINHAS][COLUNAS];
Posicao posicao;
int inicializado=0;
int perdeu=0;
int posicoes_abertas=0;
int marcacoes=0;

//implementação
void revelar(int i, int j){
	//se não está nos limites do campo ou se a posição já foi revelada
	if(i<0 || i>=LINHAS || j<0 || j>=COLUNAS || campo[i][j].estado==VISIVEL)
		return;
	
	campo[i][j].estado=VISIVEL;
	posicoes_abertas++;
	
	//se a posicao não tiver nenhuma bomba próxima revela as posições ao redor
	if(campo[i][j].bombas_proximas==0)
		for(int variacao_i=-1; variacao_i<=1; variacao_i++)
			for(int variacao_j=-1; variacao_j<=1; variacao_j++)
				if(variacao_i!=0 || variacao_j!=0)
					revelar(i+variacao_i, j+variacao_j);
}

void mostrar_bombas(){
	for(int i=0; i<LINHAS; i++){
		for(int j=0; j<COLUNAS; j++){
			if(campo[i][j].bomba==CHEIO)
				printf(" %s#%s ", VERMELHO, FIM_COR);
			else if(campo[i][j].bombas_proximas>0)
				printf(" %d ", campo[i][j].bombas_proximas);
			else
				printf("   ");
		}
		printf("\n");
	}
}

int marcas_proximas(){
	int min_linha = (posicao.linha-1>=0)? posicao.linha-1 : 0;
	int min_coluna = (posicao.coluna-1>=0)? posicao.coluna-1 : 0;
	int max_linha = (posicao.linha+1<LINHAS)? posicao.linha+1 : LINHAS-1;
	int max_coluna = (posicao.coluna+1<COLUNAS)? posicao.coluna+1 : COLUNAS-1;
	
	int cont=0;
	for(int i=min_linha; i<=max_linha; i++)
		for(int j=min_coluna; j<=max_coluna; j++)
			if((i!=0 || j!=0) && campo[i][j].estado==MARCADO)
				cont++;
	
	return cont;
}

void opcao(char escolha, int linha, int coluna){
	switch(escolha){
		case '1'://revelar
			if(campo[linha][coluna].bomba==LIMPO)
				revelar(linha, coluna);
			else
				perdeu=1;
			break;
		case '2'://marcar ou desmarcar
			if(campo[linha][coluna].estado!=VISIVEL){
				if(campo[linha][coluna].estado==MARCADO){
					campo[linha][coluna].estado=NEUTRO;
					marcacoes--;
					break;
				}
				campo[linha][coluna].estado=MARCADO;
				marcacoes++;
			}
	}
}

int selecao(){
	char direcao = getch();
	switch(direcao){
		case 'W':
		case 'w':
			posicao.linha = (posicao.linha-1>=0)? posicao.linha-1 : 0;
			break;
		case 'A':
		case 'a':
			posicao.coluna = (posicao.coluna-1>=0)? posicao.coluna-1 : 0;
			break;
		case 'S':
		case 's':
			posicao.linha = (posicao.linha+1<LINHAS)? posicao.linha+1 : LINHAS-1;
			break;
		case 'D':
		case 'd':
			posicao.coluna = (posicao.coluna+1<COLUNAS)? posicao.coluna+1 : COLUNAS-1;
			break;
		case '1':
			if(!inicializado)
				return 1;
			
			//caso o jogador queira revelar todas as casas ao redor da posição escolhida
			//a posição ja deve estar revelada e deve ter o número de marcações ao seu redor igual ao número de bombas próximas
			if(campo[posicao.linha][posicao.coluna].estado==VISIVEL && 
			marcas_proximas()==campo[posicao.linha][posicao.coluna].bombas_proximas){
				int min_linha = (posicao.linha-1>=0)? posicao.linha-1 : 0;
				int min_coluna = (posicao.coluna-1>=0)? posicao.coluna-1 : 0;
				int max_linha = (posicao.linha+1<LINHAS)? posicao.linha+1 : LINHAS-1;
				int max_coluna = (posicao.coluna+1<COLUNAS)? posicao.coluna+1 : COLUNAS-1;
				
				for(int i=min_linha; i<=max_linha; i++)
					for(int j=min_coluna; j<=max_coluna; j++)
						if((i!=posicao.linha || j!=posicao.coluna) && campo[i][j].estado==NEUTRO)
							opcao(direcao, i, j);
			}
		case '2':
			if(!inicializado)
				return 1;
				
			opcao(direcao, posicao.linha, posicao.coluna);
				
			return 1;
	}
	return 0;
}

void interface(){
	do{
		system("clear");
		printf("BOMBAS: %d       MARCAÇÕES: %d\n", BOMBAS, marcacoes);
		for(int i=0; i<LINHAS; i++){
			for(int j=0; j<COLUNAS; j++){
				if(inicializado){//se o campo já foi inicializado
					if(i==posicao.linha && j==posicao.coluna)
						printf("%s",AZUL);
					if(campo[i][j].estado==VISIVEL){
						if(campo[i][j].bombas_proximas>0){
							if(i==posicao.linha && j==posicao.coluna)
								printf("{%d}", campo[i][j].bombas_proximas);
							else
								printf(" %d ", campo[i][j].bombas_proximas);
						}
						else{
							if(i!=posicao.linha || j!=posicao.coluna)
								printf("   ");
							else
								printf("{@}");
						}
						printf("%s", FIM_COR);
						continue;
					}
					else if(campo[i][j].estado==MARCADO && (i!=posicao.linha || j!=posicao.coluna))
						printf("%s", AMARELO);
					else if(i!=posicao.linha || j!=posicao.coluna)
						printf("%s", VERDE);
					if(i!=posicao.linha || j!=posicao.coluna)
						printf(" #%s ", FIM_COR);
					else
						printf("{#}%s", FIM_COR);
				}
				else{
					if(i!=posicao.linha || j!=posicao.coluna)
						printf(" %s#%s ", VERDE, FIM_COR);
					else
						printf("%s{#}%s", AZUL, FIM_COR);
				}
			}
			printf("\n");
		}
		printf("WASD para se mover, 1 para vizualizar, 2 para marcar ou desmarcar,\n");
		int confirmado = selecao();
		
		if(confirmado) break;
	}while(1);
}

void tratar_lixo_no_campo(){
	for(int i=0; i<LINHAS; i++)
		for(int j=0; j<COLUNAS; j++){
			campo[i][j].bomba=LIMPO;
			campo[i][j].bombas_proximas=0;
			campo[i][j].estado=NEUTRO;
		}
}

void colocar_bombas(){
	int cont=0;
	do{
		int l = rand()%LINHAS;
		int c = rand()%COLUNAS;
		
		//se não estiver perto do ponto inicial 
		//e a posicao escolhida não tiver nenhuma bomba, uma nova bomba é posicionada
		if(!((l>=posicao.linha-2 && l<=posicao.linha+2) && (c>=posicao.coluna-2 && c<=posicao.coluna+2)) &&
		campo[l][c].bomba==LIMPO){
			cont++;
			campo[l][c].bomba=CHEIO;
		}
	}while(cont<BOMBAS);
}

void calcular_bombas_proximas(){
	for(int i=0; i<LINHAS; i++)
		for(int j=0; j<COLUNAS; j++){
			//delimita a área que será analizada evitando áreas fora do campo
			int min_linha = (i-1>=0)? i-1 : 0;
			int min_coluna = (j-1>=0)? j-1 : 0;
			int max_linha = (i+1<LINHAS)? i+1 : LINHAS-1;
			int max_coluna = (j+1<COLUNAS)? j+1 : COLUNAS-1;
	
			//incrementa as bombas póximas a posição
			for(int l=min_linha; l<=max_linha; l++)
				for(int c=min_coluna; c<=max_coluna; c++)
					if(campo[l][c].bomba==CHEIO && (l!=i || c!=j))
						campo[i][j].bombas_proximas++;
				}
}

int pelo_menos_uma_bomba_por_linha(){
	for(int i=0; i<LINHAS; i++){
		int bomba_encontrada=0;
		for(int j=0; j<COLUNAS; j++)
			if(campo[i][j].bomba==CHEIO){
				bomba_encontrada=1;
				break;
			}
		if(!bomba_encontrada)
			return 0;
	}
	
	return 1;
}

void inicializa_campo(){
	do{
		tratar_lixo_no_campo();
		colocar_bombas();
		calcular_bombas_proximas();
	}while(!pelo_menos_uma_bomba_por_linha());
}

int main(){
	srand(time(NULL));
	
	posicao.linha = posicao.coluna = 0;
	
	interface();
	inicializa_campo();
	revelar(posicao.linha, posicao.coluna);
	int temp_inicial=time(NULL);
	
	inicializado=1;
	do{
		interface();
		
		if(perdeu){
			system("clear");
			printf("Você pisou em uma mina\n");
			mostrar_bombas();
			break;
		}
		if(posicoes_abertas==LINHAS*COLUNAS-BOMBAS){
			int temp_final=time(NULL);
			printf("Parabéns! você venceu \nTempo: %d segundos\n", temp_final-temp_inicial);
			break;
		}
	}while(1);
	return 0;
}
