/*Considerando o problema anterior, faça um programa que leia uma String S criptografada, e um vetor de
strlen(s) números inteiros. Valide a consistência do vetor (não deve ter números repetidos e devem estar
no intervalo adequado). Se tudo estiver em conformidade, informe a mensagem decifrada...
Exemplo de Execução:
Texto Cifrado:EADUD LE A
Vetor (Chave):1369847502
Texto Decifrado:AULA DE ED*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
	char texto_cifrado[50];
	printf("Digite o texto cifrado.\n");
	scanf(" %[^\n]s", texto_cifrado);
	int len=strlen(texto_cifrado);
	int chave[len];
	
	printf("Digite a chave.\n");
	for(int i=0; i<len; i++)
		scanf(" %d", &chave[i]);
		
	char texto_decifrado[len+1];
	for(int i=0; i<len; i++)
		texto_decifrado[i]=texto_cifrado[chave[i]];
	texto_decifrado[len]=0;
	
	printf("Texto decifrado: \n%s", texto_decifrado);

	return 0;
}

