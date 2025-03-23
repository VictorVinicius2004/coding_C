#include <stdio.h>

enum ESTADOS{I, U0, U1, D0, D1, X};

#define INVALIDO 0
#define VALIDO 1

int valida_alfabeto(char numero[]){
	for(int i=0; i<100; i++){
		if(numero[i]==0)
			break;

		int num = numero[i]-'0';

		if(num!=0 && num!=1)
			return INVALIDO;
	}

	return VALIDO;
}

int troca_estado(int estado, int num){
	switch(estado){
		case I:
			if(num==0)
				return  U0;
			else
				return  U1;
			break;
		case U0:
			if(num==0)
				return  D0;
			else
				return  X;
			break;
		case U1:
			if(num==0)
				return  X;
			else
				return  D1;
			break;
		case D0:
			if(num==0)
				return  U0;
			else
				return  U1;
			break;
		case D1:
			if(num==0)
				return  U0;
			else
				return  U1;
	}
	return X;
}

int valida_estados(char numero[]){
	int estado = I; 

	for(int i=0; i<100; i++){
		if(numero[i]==0)
			break;

		int num=numero[i]-'0';

		estado = troca_estado(estado, num);
	}

	if(estado==D1 || estado==D0)
		return VALIDO;
	else
		return INVALIDO;
}

int main(){
	char numero[100]={0};
	printf("Digite um número binário(apenas 0 ou 1)\n");
	scanf(" %s", numero);
	if(valida_alfabeto(numero)==INVALIDO)
		return 1;

	if(valida_estados(numero)==INVALIDO)
		return 2;

	printf("Número válido\n");
	return 0;
}
