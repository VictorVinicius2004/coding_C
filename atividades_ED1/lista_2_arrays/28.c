/*Faça um programa que leia, em formato de string, dois números inteiros excepcionalmente grandes e
imprima o valor da soma destes números.*/

#include <string.h>
#include <stdio.h>

int main(){
	char num1[20], num2[20];
	printf("Digite os números a serem somados:\n");
	scanf(" %s %s", num1, num2);
	int len1=strlen(num1)-1, len2=strlen(num2)-1, mult=1, n1=0, n2=0;
	
	for(int i=len1; i>=0; i--){
		n1+=(num1[i]-'0')*mult;
		mult*=10;
	}
	mult=1;
	
	for(int i=len2; i>=0; i--){
		n2+=(num2[i]-'0')*mult;
		mult*=10;
	}
	printf("\n%s + %s == %d", num1, num2, n1+n2);
	return 0;
}
