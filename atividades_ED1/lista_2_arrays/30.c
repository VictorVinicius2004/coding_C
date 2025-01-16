/*Faça um algoritmo de "Pattern Search". Dada uma string "text" e outra string "pattern", imprima a
quantidade de vezes que a sub-string "pattern" pode ser encontrada dentro da string "text".
P.Ex.: Text = "AABACAABAABAABAABB" Pattern = "AABA" ==> 04 Ocorrências partindo de: [0, 5, 8, 11]*/

#include <string.h>
#include <stdio.h>

int main(){
	char text[50], pattern[50];
	printf("Text:\n");
	scanf(" %[^\n]s", text);
	printf("Pattern:\n");
	scanf(" %[^\n]s", pattern);
	short int cont=0, ocorrencias[50], inicio=0, fim=strlen(pattern)-1; 
	
	do{
		int igual=1, cont_p=0;
		for(int i=inicio; i<=fim; i++)
			if(text[i]!=pattern[cont_p++]){
				igual=0;
				break;
			}
		if(igual)
			ocorrencias[cont++]=inicio;
		
		inicio++;
		fim++;
	}while(fim<strlen(text));
	
	printf("%d Ocorrências partindo de: [", cont);
	for(int i=0; i<cont; i++)
		(i<cont-1)? printf("%d, ", ocorrencias[i]) : printf("%d", ocorrencias[i]);
	printf("]");
	return 0;
}

