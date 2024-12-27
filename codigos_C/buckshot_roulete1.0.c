#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gconio.h>
#include <time.h>

#define VERDADEIRO 1
#define FALSO 0
#define JOGADOR 1
#define BOT 0
#define BALAS 6

typedef struct{
	int municao[BALAS];
	int cheio[BALAS];
	int verdadeiras;
	int falsas;
}Arma;

typedef struct{
	int usuario;
	int pc;
	int vez;
}Vida;

void inicio(){
	int escolha;
	do{
		printf("1-Regras / 2-Início\n");
		scanf(" %d", &escolha);
		system("clear");
		switch(escolha){
			case 1:
				printf("Você está em uma mesa com uma escopeta com capacidade de 6 munições no centro, ela será abastecida aletoriamente com munições verdadeiras e falsas. Você estará jogando \ncontra o bot, cada um com 5 vidas, os dois terão a vez de atirar com a escopeta no oponente ou em si mesmo, quem for atigido por uma munição verdadeira perde uma vida, \nquem atirar em si mesmo com uma munição falsa pode atirar de novo. Um CLICK quer dizer que a munição era falsa, um BAM quer dizer que era verdadeira.\n");
				break;
			case 2:
				printf("Bom jogo\n");
		}
	}while(escolha!=2);
}

//carrega e descarrega a arma
Arma arma(Arma escopeta){
	
	if(!escopeta.cheio[BALAS-1]){
		do{
			escopeta.verdadeiras=rand()%2+2;
			escopeta.falsas=rand()%BALAS;
		} while (escopeta.verdadeiras+escopeta.falsas!=BALAS);
		
		for (int i = 0; i < escopeta.verdadeiras; i++){
			escopeta.municao[i]=VERDADEIRO;
			escopeta.cheio[i]=VERDADEIRO;
		}
		for (int i = escopeta.verdadeiras; i < BALAS; i++){
			escopeta.municao[i]=FALSO;
			escopeta.cheio[i]=VERDADEIRO;
		}
		
		for (int i = 0; i < 100; i++){
			int pos1, pos2, aux;
			pos1=rand()%BALAS;
			pos2=rand()%BALAS;
			
			aux=escopeta.municao[pos1];
			escopeta.municao[pos1]=escopeta.municao[pos2];
			escopeta.municao[pos2]=aux;
		}
		printf("Arma carregada \n%d munições verdadeiras, %d munições falsas\nPressione ENTER para continuar\n", escopeta.verdadeiras, escopeta.falsas);
		getch();
		system("clear");
	}
	else{
		for (int i = 0; i < BALAS; i++){
			if(escopeta.cheio[i]){
				if(escopeta.municao[i])
					escopeta.verdadeiras--;
				else
					escopeta.falsas--;
				escopeta.cheio[i]=0;
				break;
			}
		}
	}
	return escopeta;
}

int computador(Arma escopeta){
	printf("Vez do computador\n");
	system("sleep 1");
	
	if(escopeta.falsas>escopeta.verdadeiras)
		return 0;
	else
		return 1;
}

Vida mesa(Arma escopeta, Vida vida){
	int escolha, municaoatual;
	printf("Vida BOT: ");
	for (int i = 0; i < vida.pc; i++){
		printf("#");
	}
	printf("\nSua vida: ");
	for (int i = 0; i < vida.usuario; i++){
		printf("#");
	}
	printf("\n");
	for (int i = 0; i < BALAS; i++){
		if(escopeta.cheio[i]){
			municaoatual=escopeta.municao[i];
			break;
		}
	}

	if(vida.vez==JOGADOR){
		printf("0-atirar em si mesmo, 1-atirar no oponente\n");
		scanf(" %d", &escolha);
		system("clear");
		switch(escolha){
			case 0:
				switch(municaoatual){
					case 0:
						printf("...   ");
						system("sleep 1.5");
						printf("Click\n");
						break;
					case 1:
						printf("...   ");
						system("sleep 1.5");
						printf("BAM\n");
						vida.usuario--;
						vida.vez=BOT;
				}
				break;
			case 1:
				switch(municaoatual){
					case 0:
						printf("...   ");
						system("sleep 1.5");
						printf("Click\n");
						vida.vez=BOT;
						break;
					case 1:
						printf("...   ");
						system("sleep 1.5");
						printf("BAM\n");
						vida.pc--;
						vida.vez=BOT;
				}
		}
		
	}
	else{
		escolha=computador(escopeta);
		switch(escolha){
			case 0:
				printf("Ele escolheu atirar em si mesmo\n");
				switch(municaoatual){
					case 0:
						printf("...   ");
						system("sleep 1.5");
						printf("Click\n");
						break;
					case 1:
						printf("...   ");
						system("sleep 1.5");
						printf("BAM\n");
						vida.pc--;
						vida.vez=JOGADOR;
				}
				break;
			case 1:
				printf("Ele escolheu atirar em você\n");
				switch(municaoatual){
					case 0:
						printf("...   ");
						system("sleep 1.5");
						printf("Click\n");
						vida.vez=JOGADOR;
						break;
					case 1:
						printf("...   ");
						system("sleep 1.5");
						printf("BAM\n");
						vida.usuario--;
						vida.vez=JOGADOR;
				}
		}
	}
	printf("Pressione ENTER para continuar:\n");
	getch();
	system("clear");
	return vida;
}

int main(){
	Arma escopeta;
	Vida vida;
	vida.pc=5;
	vida.usuario=5;
	vida.vez=JOGADOR;
	escopeta.cheio[BALAS-1]=0;
	srand(time(NULL));
	inicio();
	do{
		escopeta=arma(escopeta);
		if(escopeta.cheio[BALAS-1])
			vida=mesa(escopeta, vida);
	}while(vida.usuario>0 && vida.pc>0);
	system("clear");
	if(vida.pc==0)
		printf("Parabéns! Você venceu");
	else
		printf("Sem sorte hoje?");
}

