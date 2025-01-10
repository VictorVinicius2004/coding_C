#ifndef MINHA_BIBLIOTECA_H
#define MINHA_BIBLIOTECA_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <gconio.h>

typedef struct{
	int linha;
	int coluna;
}Posicao;

int entre_string(char c,  const char *str){
	int p_util=strlen(str);
	
	for(int i=0; i<p_util; i++)
		if(c==str[i])
			return 1;
		
	return 0;
}

entre_vetor(int num, int indice, const int *vetor){
	for(int i=0; i<indice; i++)
		if(num==vetor[i])
			return 1;
	
	return 0;
}

Posicao wasd(Posicao posicao){
	char tecla;
	tecla=getch();
	
	switch(tecla){
		case 'w': posicao.linha--; break;
		case 'a': posicao.coluna--; break;
		case 's': posicao.linha++; break;
		case 'd': posicao.coluna++; break;
		default: printf("Movimento inválido\n");
	}
	return posicao;
}

int sorteio(float porcentagem, int vezes){
	srand(time(NULL));
	int cento=100;
	
	if(vezes<=0)
		return 0;
		
	if(porcentagem<100 && porcentagem>0){
		while(porcentagem-(int)porcentagem){
			porcentagem*=10;
			cento*=10;
		}
		
		for(int i=cento; i>0; i--)
			if(cento%i==0 && (int)porcentagem%i==0){
				cento/=i;
				porcentagem/=i;
				
			}

		for(int i=0; i<vezes; i++){
			int num=rand()%cento+1;

			if(num<=porcentagem)
				return 1;
		}
		
		return 0;
	}
	else{
		if(porcentagem>=100)
			return 1;
		if(porcentagem<=0)
			return 0;
	}
}
#endif
