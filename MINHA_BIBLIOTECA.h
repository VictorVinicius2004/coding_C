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

#endif
