#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
	char string[1000];
	printf("Digite uma frase.\n");
	scanf(" %[^\n]s", string);
	int tam=strlen(string), espaco=1, palavras=0;

	for (int i = 0; i < tam; i++){
		if(string[i]!=' ' && espaco){
			palavras++;
			espaco=0;
		}
		if(string[i]==' ')
			espaco=1;
	}
	
	printf("A frase tem %d palavras", palavras);
	return 0;

}
