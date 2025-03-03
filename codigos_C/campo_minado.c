//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

//constantes
#define LINHAS 10
#define COLUNAS 10
#define BOMBAS 25

#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define AMARELO "\033[33m"
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
				printf("%s", VERMELHO);
			else
				printf("%s", VERDE);
			printf("#%s ", FIM_COR);
		}
		printf("\n");
	}
}

void opcao(char escolha){
	switch(escolha){
		case '1':
			if(campo[posicao.linha][posicao.coluna].bomba==LIMPO)
				revelar(posicao.linha, posicao.coluna);
			else
				perdeu=1;
			break;
		case '2':
			if(campo[posicao.linha][posicao.coluna].estado!=VISIVEL){
				if(campo[posicao.linha][posicao.coluna].estado==MARCADO){
					campo[posicao.linha][posicao.coluna].estado=NEUTRO;
					marcacoes--;
					break;
				}
				campo[posicao.linha][posicao.coluna].estado=MARCADO;
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
		case '2':
			if(inicializado)
				opcao(direcao);
			return 1;
	}
	return 0;
}

void interface(){
	do{
		system("clear");
		printf("BOMBAS: %d     MARCAÇÕES: %d\n", BOMBAS, marcacoes);
		for(int i=0; i<LINHAS; i++){
			for(int j=0; j<COLUNAS; j++){
				if(inicializado){
					if(i==posicao.linha && j==posicao.coluna)
						printf("@ ");
					else if(campo[i][j].estado==VISIVEL){
						if(campo[i][j].bombas_proximas>0)
							printf("%d ", campo[i][j].bombas_proximas);
						else
							printf("  ");
					}
					else if(campo[i][j].estado==MARCADO)
						printf("%s#%s ", AMARELO, FIM_COR);
					else 
						printf("%s#%s ", VERDE, FIM_COR);
				}
				else{
					if(i!=posicao.linha || j!=posicao.coluna)
						printf("%s#%s ", VERDE, FIM_COR);
					else
						printf("@ ");
					
				}
			}
			printf("\n");
		}
		printf("WASD para se mover, 1 para vizualizar, 2 para marcar,\n");
		int confirmado = selecao();
		
		if(confirmado) break;
	}while(1);
}

void inicializa_campo(){
	//trata o lixo no campo
	for(int i=0; i<LINHAS; i++)
		for(int j=0; j<COLUNAS; j++){
			campo[i][j].bomba=LIMPO;
			campo[i][j].bombas_proximas=0;
			campo[i][j].estado=NEUTRO;
		}
	
	//coloca as bombas
	int cont=0;
	do{
		int l = rand()%LINHAS;
		int c = rand()%COLUNAS;
		
		//se não estiver perto do ponto inicial 
		//e nem a posicao escolhida já tiver uma bomba, uma nova bomba é posicionada
		if(!((l>=posicao.linha-2 && l<=posicao.linha+2) && (c>=posicao.coluna-2 && c<=posicao.coluna+2)) &&
		campo[l][c].bomba==LIMPO){
			cont++;
			campo[l][c].bomba=CHEIO;
		}
	}while(cont<BOMBAS);
	
	//calcula o número de bombas próximas de cada casa
	for(int i=0; i<LINHAS; i++)
		for(int j=0; j<COLUNAS; j++){
			//calcula a área que será analizada evitando áreas fora do campo
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

int main(){
	srand(time(NULL));
	
	posicao.linha = posicao.coluna = 0;
	
	interface();
	inicializa_campo();
	revelar(posicao.linha, posicao.coluna);
	
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
			system("clear");
			printf("Parabéns! você venceu\n");
			break;
		}
	}while(1);
	return 0;
}
