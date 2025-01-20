/*Implemente o algoritmo para checar a validade de um número de CPF*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define t_cpf 11

int main(){
	char cpf[12];
	do{
		int valido=1;
		printf("Digite o CPF(sem espaços ou simbólos):\n");
		scanf(" %s", cpf);
		
		for(int i=0; i<t_cpf; i++)
			if(cpf[i]<'0' || cpf[i]>'9'){
				valido=0;
				break;
			}
		if(strlen(cpf)!=11)
			valido=0;
			
		if(valido)
			break;
		else
			system("clear");
	}while(1);
	
	int dv1=0, dv2=0;
	for(int i=0; i<t_cpf-1; i++){
		
		//dv1
		if(i<=8){
			dv1+=(cpf[i]-'0')*(i+1);
			
			if(i==8){
				dv1=dv1%11;
				
				if(dv1==10)
					dv1=0;
			}
		}
		//dv2
		if(i<=9){
			dv2+=(cpf[i]-'0')*i;
			
			if(i==9){
				dv2=dv2%11;
				
				if(dv2==10)
					dv2=0;
			}
		}
	}
	
	if(dv1==cpf[9]-'0' && dv2==cpf[10]-'0')
		printf("\nCPF válido");
	else
		printf("\nCPF inválido");
	return 0;
}

