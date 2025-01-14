/*Faça um programa em C que leia um valor inteiro correspondente ao seu número de matrícula no curso
e, como saída, gera e imprime a string formada pelos dígitos deste número. P.Ex.: 2024 == “2024”.*/

#include <stdio.h>
#include <string.h>

int main(){
	int num;
	char string[20];
	printf("Digite seu número de matrícula.\n");
	scanf(" %d", &num);
	
	int cont=0;
	while(num>0){
		string[cont++]=num%10+'0';
		num/=10;
	}
	string[cont--]=0;
	
	for(int i=0; i<=cont; i++){
		int aux=string[i];
		string[i]=string[cont];
		string[cont--]=aux;
	}
	
	printf("Número convertido para string: \n%s", string);
	return 0;
}

