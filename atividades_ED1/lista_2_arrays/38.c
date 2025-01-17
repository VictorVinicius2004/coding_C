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
			vetor_sorteado[cont]=cont-1;
			vetor_sorteado[cont-1]=cont;
			cont++;
		}
	}while(cont<len);
	
	//trocando as posições
	for(int i=0; i<len; i++){
		char aux=string[i];
		string[i]=string[vetor_sorteado[i]];
		string[vetor_sorteado[i]]=aux;
	}
	
	printf("\ntexto cifrado: \n\n%s", string);
	return 0;
}

