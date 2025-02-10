#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum {VERMELHO=37, BRANCO, VERDE, PAR, IMPAR};

typedef struct{
	int num;
	int cor;
}Roleta;

typedef struct{
	float valor;
	int saida;
}Saldoesaida;

void printroleta(float saldo){
	printf("Saldo atual: R$ %.2f\n\n", saldo);
	printf("        \033[32m0\033[0m\n");
	for(int i=1; i<37; i++){
		if(i%2==0)
			printf("\033[31m%02d \033[0m", i);
		else
			printf("%02d ", i);
		if((i)%6==0)
			printf("\n");
	}
}

int escolha(float saldo){
	printroleta(saldo);
	
	if(saldo<=0)
		return -1;
		
	int choice;
	
	printf("Digite: \n1-Apostar em um número(1 a 36). Multi=36x\n");
	printf("2-Apostar em par ou impar. Multi=2x\n");
	printf("3-Apostar em uma cor(VERMELHO ou BRANCO). Multi=2x\n");
	printf("4-Cash out\n");
	do{
		scanf(" %d", &choice);
		while(getchar()!='\n');
	}while(choice<1 || choice >4);
	
	int decisao;
	switch(choice){
		case 1:
			printf("escolha um número de 1 a 36: ");
			do{
				scanf(" %d", &decisao);
				while(getchar()!='\n');
			}while(decisao<1 || decisao>36);
			break;
		case 2:
			printf("Escolha: 1-impar, 2-par(0 não é considerado par ou impar)\n");
			do{
				scanf(" %d", &decisao);
				while(getchar()!='\n');
			}while(decisao!=1 && decisao!=2);
			decisao = (decisao==1)? IMPAR : PAR;
			break;
		case 3:
			printf("Escolha: 1-Vermelho, 2-Branco\n");
			do{
				scanf(" %d", &decisao);
				while(getchar()!='\n');
			}while(decisao!=1 && decisao!=2);
			decisao = (decisao==1)? VERMELHO : BRANCO;
			break;
		case 4:
			decisao=-1;
	}
	
	return decisao;
}

Saldoesaida roleta(int decisao, Saldoesaida saldo){
	if(decisao==-1 || saldo.valor<=0){
		saldo.saida=1;
		return saldo;
	}
	
	saldo.saida=0;
	
	Roleta roleta[37];
	for(int i=0; i<37; i++){
		roleta[i].num=i;
		if(i==0)
			roleta[i].cor=VERDE;
		else if(i%2==0)
			roleta[i].cor=VERMELHO;
		else
			roleta[i].cor=BRANCO;
	}
	
	int aposta;
	printf("Digite quanto deseja apostar: ");
	scanf(" %d", &aposta);
	while(getchar()!='\n');
	
	if(aposta>saldo.valor)
		aposta=saldo.valor;
	if(aposta<0)
		aposta=0;
	saldo.valor-=aposta;
	
	int sorteio=rand()%37;
	if(sorteio%2==0 && sorteio!=0)
		printf("Número sorteado: \033[31m");
	else if(sorteio==0) 
		printf("Número sorteado: \033[32m");
		
	printf("%d\033[0m\n", sorteio);
	switch(decisao){
		case PAR:
			aposta = (sorteio%2==0 && sorteio!=0)? aposta*2 : 0;
			break;
			
		case IMPAR:
			aposta = (sorteio%2==1)? aposta*2 : 0;
			break;
			
		case VERMELHO:
			aposta = (roleta[sorteio].cor==VERMELHO)? aposta*2 : 0;
			break;
			
		case BRANCO:
			aposta = (roleta[sorteio].cor==BRANCO)? aposta*2 : 0;
			break;
			
		default:
			aposta = (sorteio==decisao)? aposta*36 : 0;
	}
	printf("Aperte ENTER para continuar");
	getchar();
	
	system("clear");
	
	saldo.valor+=aposta;
	return saldo;
}

int main(){
	srand(time(NULL));
	Saldoesaida saldo;
	saldo.valor=1000;
	
	do{
		saldo=roleta(escolha(saldo.valor), saldo);
	}while(saldo.valor>0 && saldo.saida==0);
	
	printf("Saldo final: R$ %.2f\n", saldo.valor);
	if(saldo.valor>1000)
		printf("Lucro: R$ %.2f", saldo.valor-1000.00);
	else if(saldo.valor<1000)
		printf("Prezuízo: R$ %.2f", 1000-saldo.valor);
	else
		printf("Sem lucro ou prejuízo");
	return 0;
}

