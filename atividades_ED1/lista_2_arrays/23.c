/*Números romanos são representados por letras, sendo:
'I' == 1   'L' == 50    'M' == 1000
'V' == 5   'C' == 100
'X' == 10  'D' == 500
Faça um programa que leia uma string em formato de número romano, verifique se é válida (não possui
caracteres inválidos) e, estando válida, converta para o número decimal respectivo. Repita a operação
até ser informada a string "exit" para encerrar a execução do programa.*/

#include <string.h>
#include <stdio.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int main(){
	char num_R[15], is_R=1;
	printf("Digite um número romano.\n");
	scanf(" %s", num_R);
	int len=strlen(num_R);
	int num_D[len];
	
	for(int i=0; i<len; i++){
		if(num_R[i]=='I')
			num_D[i]=I;
		else if(num_R[i]=='V')
			num_D[i]=V;
		else if(num_R[i]=='X')
			num_D[i]=X;
		else if(num_R[i]=='L')
			num_D[i]=L;
		else if(num_R[i]=='C')
			num_D[i]=C;
		else if(num_R[i]=='D')
			num_D[i]=D;
		else if(num_R[i]=='M')
			num_D[i]=M;
		else{ 
			is_R=0;
			break;
		}
	}
		
	if(is_R){
		int num=num_D[0];
		for(int i=1; i<len; i++){
			if(num_D[i]<=num_D[i-1])
				num+=num_D[i];
			else
				num+=num_D[i]-num_D[i-1]*2;
		}
		printf("Número convertido para decimal: %d", num);
	}
	else
		printf("A string recebida não é um número romano.\n");
	return 0;
}

