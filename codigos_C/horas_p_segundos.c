#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MULTI(hora, i, multi) ((((hora[i]-48)*10)+(hora[i+1]-48))*multi)

int main(){
	char hora[9];
	printf("Digite as horas na formatação hh:mm:ss\n");
	scanf(" %8s", hora);
	
	if(strlen(hora)!=8 || hora[2]!= ':' || hora[5]!=':'){
		printf("Formato inválido\n");
		return 1;
	}
	
	int num, segundos=0, multi=3600;
	for(int i=0; i<7; i+=3){
		num= MULTI(hora, i, multi);
		multi/=60;
		segundos+=num;
	}
	printf("As horas convertidas em segundos são: %d", segundos);
	return 0;
}
