#include <stdlib.h>
#include <stdio.h>

//convertor Binário para decimal
int potencia(int base, int expoente){
	int resultado=1;
	for (int i = 0; i < expoente; i++){
		resultado*=base;
	}
	return resultado;
}

int main(){ 
	int bin, dec=0, base=2, exp=0;
	printf("Digite um número binário.\n");
	scanf(" %d", &bin);
	
	while (1){
		if (bin%10==1){
			dec+=potencia(base, exp);
		}
		bin=bin/10;
		exp++;
		if (bin<1){
			break;
		}
	}
	printf("%d", dec);
}
