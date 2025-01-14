/*Faça um programa que leia, em formato de string, um valor numérico representado na base binária. O
programa deve validar se o valor informado pelo usuário realmente é um número binário. Em caso
positivo, o programa deve informar o valor correspondente na base decimal.*/

#include <string.h>
#include <stdio.h>
#include <math.h>

int main(){
	char bin[20];
	printf("Digite um número binário.\n");
	scanf(" %s", bin);
	
	int num=0, isbin=1, expoente=0;
	for(int i=strlen(bin)-1; i>=0; i--){
		if(bin[i]=='1')
			num+=(int)pow(2, expoente++);
		else if(bin[i]=='0')
			expoente++;
		else{
			isbin=0;
			break;
		}
	}
	
	(isbin==1)? printf("Número em decimal: %d", num) : printf("O número não é binário");
	return 0;
}

