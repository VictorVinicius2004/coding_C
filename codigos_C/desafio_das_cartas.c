#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

#define CARTAS 7
#define VAZIO 0

int main(){
	int player1[CARTAS], player2[CARTAS];
	srand(time(NULL));
	
	for (int i = 0; i < CARTAS; i++){
		player1[i]=rand()%10+1;
		player2[i]=rand()%10+1;
	}
	
	do{
		int base[2], topo[2], cont1=0, cont2=0, pos1, pos2, aux;
		
		//pegando a carta do topo e da base
		for (int i = cont1; i < CARTAS; i++)
			if(player1[i]){
				topo[0]=player1[i];
				topo[1]=i;
				break;
			}
		for (int i = 6-cont2; i >= 0 ; i--)
			if(player2[i]){
				base[0]=player2[i];
				base[1]=i;
				break;
			}
			
		//interface
		printf("Player 1: ");
		for (int i = 0; i < CARTAS; i++){
			if(player1[i])
				printf("[%02d] ", player1[i]);
			else
				printf("     ");
		}
		printf("\n\nPlayer 2: ");
		for (int i = 0; i < CARTAS; i++)
			if(player2[i])
				printf("[%02d] ", player2[i]);
		printf("\n\nCONFRONTO:\n");
		printf("[%02d] VS [%02d]\n", topo[0], base[0]);
		
		//comparando as cartas
		if(topo[0]>base[0]){
			printf("Player 1 venceu a rodada\n");
			player1[topo[1]]=VAZIO;
			cont1++;
			for (int i = 0; i < 100; i++){
				pos1=rand()%CARTAS;
				pos2=rand()%CARTAS;
				if(player2[pos1]>0 && player2[pos2]>0){
					aux=player2[pos1];
					player2[pos1]=player2[pos2];
					player2[pos2]=aux;
				}
			}
		}
		
		if(topo[0]<base[0]){
			printf("Player 2 venceu a rodada\n");
			player2[base[1]]=VAZIO;
			cont2++;
			for (int i = 0; i < 100; i++){
				pos1=rand()%CARTAS;
				pos2=rand()%CARTAS;
				if(player1[pos1]>0 && player1[pos2]>0){
					aux=player1[pos1];
					player1[pos1]=player1[pos2];
					player1[pos2]=aux;
				}
			}
		}
		
		if(topo[0]==base[0]){
			printf("Empate\n");
			player1[topo[1]]=VAZIO;
			player2[base[1]]=VAZIO;
		}
		
		printf("Aperte qualquer tecla para continuar\n");
		getch();
		system("clear");
		
		//verificando o vencedor
		if(!player1[6]){
			system("clear");
			printf("Player 1 venceu");
			getch();
			break;
		}
		if(!player2[0]){
			system("clear");
			printf("Player 2 venceu");
			getch();
			break;
		}
	} while (1);
	
	return 0;
}

