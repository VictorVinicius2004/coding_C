/*Escreva um programa em C para ler uma frase qualquer e contar o número de palavras existentes na
frase. Considere uma palavra como sendo um conjunto maior que dois caracteres separados por um ou
mais espaços em branco.*/

#include <string.h>
#include <stdio.h>

int main(){
	char texto[50];
	printf("Digite uma frase.\n");
	scanf(" %[^\n]s", texto);
	
	int cont=0, palavras=0;
	for(int i=0; i<strlen(texto); i++){
		if( (texto[i]>='A' && texto[i]<='Z') || (texto[i]>='a' && texto[i]<='z') ){
			cont++;
			if(cont==3)
				palavras++;
		}
		
		if(texto[i]==' ')
			cont=0;
		
	}
	
	printf("O números de palavras nessa frase é de: %d", palavras);
	return 0;
}

