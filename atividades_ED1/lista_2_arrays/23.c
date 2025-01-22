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
	char num_R[20], is_R=1;
	do{
		printf("Digite um número romano.\n");
		scanf(" %s", num_R);
		int len=strlen(num_R);
		int num_D[len], num=0;
		
		//finaliza o código
		if(!strcmp(num_R, "exit"))
			break;
			
		for(int i=0; i<len; i++){
			//atribui um símbolo ao seu valor
			if(i==0){
				for(int j=0; j<len; j++){
					switch(num_R[j]){
						case 'I': num_D[j]=I; break;
						case 'V': num_D[j]=V; break;
						case 'X': num_D[j]=X; break;
						case 'L': num_D[j]=L; break;
						case 'C': num_D[j]=C; break;
						case 'D': num_D[j]=D; break;
						case 'M': num_D[j]=M; break;
						default: is_R=0; break;
					}
					if(!is_R)
						break;
				}
			}
			
			//se for inválido
			if(!is_R){
				printf("A string recebida não é um número romano.\n\n");
				break;
			}
			//calculo do número
			if(i==len-1)
				num+=num_D[i];
			else if(num_D[i]>=num_D[i+1])
				num+=num_D[i];
			else 
				num-=num_D[i];
		}
			
		if(is_R)
			printf("Número convertido para decimal: %d\n\n", num);
	}while(1);
	return 0;
}
