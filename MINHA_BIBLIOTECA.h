#ifndef MINHA_BIBLIOTECA_H
#define MINHA_BIBLIOTECA_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <gconio.h>

typedef struct{
	char c;
	const char *s;
	int d;
}Tipos;

typedef struct{
	int linha;
	int coluna;
}Posicao;

int entre(char c,  const char *str){
	int p_util=strlen(str);
	
	for(int i=0; i<p_util; i++)
		if(c==str[i])
			return 1;
		
	return 0;
}

int inputd(const char *str){
	int x;
	printf("%s", str);
	scanf(" %d", &x);
	return x;
}

char inputc(const char *str){
	char x;
	printf("%s", str);
	scanf(" %c", &x);
	return x;
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
