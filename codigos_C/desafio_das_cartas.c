#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CARTAS 7
#define VAZIO 0

int main(){
	srand(time(NULL));
	int p1[CARTAS], p2[CARTAS];
	for(int i=0; i<CARTAS; i++){
		p1[i]=rand()%10+1;
		p2[i]=rand()%10+1;
	}
	
	int base=0, topo=CARTAS-1;
	do{
		//interface
		printf("P1: ");
		for(int i=0; i<CARTAS; i++){
			if(p1[i])
				printf("[%02d] ", p1[i]);
			else
				printf("     ");
		}
		
		printf("\n\nP2: ");
		for(int i=0; i<CARTAS; i++)
			if(p2[i])
				printf("[%02d] ", p2[i]);
		
		printf("\n\n%d vs %d\n", p1[base], p2[topo]);
		
		//comparando as cartas
		if(p1[base]>p2[topo]){
			printf("P1(%d): ganhou\n", p1[base]);
			p1[base++]=0;
			
			for(int i=0; i<=60; i++){
				int pos1=rand()%CARTAS;
				int pos2=rand()%CARTAS;
				
				if(p2[pos1] && p2[pos2]){
					int aux=p2[pos1];
					p2[pos1]=p2[pos2];
					p2[pos2]=aux;
				}
			}
		}
		else if(p1[base]<p2[topo]){
			printf("P2(%d): ganhou\n", p2[topo]);
			p2[topo--]=0;
			
			for(int i=0; i<=60; i++){
				int pos1=rand()%CARTAS;
				int pos2=rand()%CARTAS;
				
				if(p1[pos1] && p1[pos2]){
					int aux=p1[pos1];
					p1[pos1]=p1[pos2];
					p1[pos2]=aux;
				}
			}
		}
		else{
			printf("Empate\n");
			p1[base++]=0;
			p2[topo--]=0;
		}
		
		printf("Pressione ENTER para continuar\n");
		getchar();
		system("clear");
	}while(base<CARTAS && topo>=0);
	
	if(base==CARTAS && topo>=0)
		printf("P1 ganhou");
	else if(topo<0 && base <CARTAS)
		printf("P2 ganhou");
	else
		printf("Empate");
	return 0;
}
