/*Implemente o algoritmo para checar a validade de um número de cartão de crédito*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char cartao[17];
	//verificando se a string está dentro dos paramêtros
	do{
		int valido=1;
		printf("Digite o número do cartao(16 números sem espaços ou símbolos).\n");
		scanf(" %s", cartao);
		
		for(int i=0; i<16; i++)
			if(!(cartao[i]>='0' && cartao[i]<='9')){
				valido=0;
				break;
			}
			
		if(strlen(cartao)!=16)
			valido=0;
			
		if(valido==1) 
			break;
		else	
			system("clear");
	}while(1);
	
	//validando o cartão 
	int g1=0, g2=0;
	for(int i=0; i<16; i++){
		int numg1=(cartao[i]-'0')*2;
		
		if(i%2==0)
			g1 += (numg1<10)? numg1 : numg1%10 + numg1/10;
		else
			g2+=cartao[i]-'0';
	}
	
	if((g1+g2)%10==0)
		printf("\nCartão válido");
	else
		printf("\nCartão inválido");
	return 0;
}

