/*Faça um programa que leia uma string S, e criptografe-a com o seguinte algoritmo: sorteie um vetor de
strlen(S) números, com valores aleatórios e não-repetitivos entre 0 e strlen(s). Após o sorteio, embaralhe
as letras da mensagem original, de acordo com as posições sorteadas no vetor. Atenção, todos os
caracteres têm que ter sua posição inicial alterada!*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
	srand(time(NULL));
	char string[50];
	printf("Digite uma frase.\n");
	scanf(" %[^\n]s", string);
	int len=strlen(string); 
	int usados[len], vetor_sorteado[len], cont=0;
	char string_cifrada[len+1];
	
	//deixando o vetor usados pronto para uso
	for(int i=0; i<len; i++)
		usados[i]=0;
	
	//sorteando as posições
	do{
		int x=rand()%len;

		if(usados[x]==0 && x!=cont){
			vetor_sorteado[cont++]=x;
			usados[x]=1;
		}
		//impedir um loop infinito que acontece quando só falta sortear última posição com ela mesma
		if(usados[len-1]==0 && cont==len-1){
			for(int i=0; i<len; i++)
				usados[i]=0;
				
			cont=0;
		}
	}while(cont<len);
	
	printf("\nA chave para criptografar:\n");
	for(int i=0; i<len; i++)
		printf("%d ", vetor_sorteado[i]);
	printf("\n");
	
	//trocando as posições
	for(int i=0; i<len; i++){
		string_cifrada[vetor_sorteado[i]]=string[i];
	}string_cifrada[len]=0;
	
	printf("\ntexto cifrado: \n%s", string_cifrada);
	return 0;
}

