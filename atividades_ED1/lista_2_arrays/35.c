/*Faça um programa que leia a data de nascimento do usuário no seguinte formato string DD/MM/AAAA
O seu programa deve validar a entrada, tanto no formato indicado, quanto na validade dos valores
informados. Após isto, leia novamente outra string DD/MM/AAAA correspondente ao dia atual e calcule
a idade completa do usuário (anos, meses e dias).*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
	char nascimento[11], dia_atual[11];
	do{
		int valido=1; 
		
		printf("Digite a sua data de nascimento, no formato (DD/MM/AAAA).\n");
		scanf(" %s", nascimento);
		printf("Digite a data atual, mesmo formato.\n");
		scanf(" %s", dia_atual);
		
		for(int i=0; i<10; i++){
			if(i!=2 && i!=5)
				if(nascimento[i]<'0' || nascimento[i] >'9'|| dia_atual[i]<'0' || dia_atual[i]>'9'){
					valido=0;
					break;
				}
			
			if((i==2 || i==5) && (nascimento[i]!='/' || dia_atual[i]!='/')){
				valido=0;
				break;
			}
		}
		
		if(valido)
			break;
		else
			system("clear");
	}while(1);
	
	
	return 0;
}

