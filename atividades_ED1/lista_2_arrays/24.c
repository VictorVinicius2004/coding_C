/*Escreva um programa em C para ler uma frase. A seguir, imprima a frase com: (a) todas as letras
maiusculas, (b) todas as letras minúsculas, (c) início de cada palavra em maiusculo. Em todos os casos,
retirar os espaços em branco em excesso, que são desnecessários. Algoritmo deve ser in-place.*/

#include <stdio.h>
#include <string.h>

int main(){
	char string[100];
	printf("Escreva uma frase.\n");
	scanf(" %[^\n]s", string);
	int len=strlen(string);
	
	//elimina espaços desnessesários
	for(int i=len-1; i>0; i--){
		if(string[len-1]==' ')
			for(int j=len-1; j>0; j--){
				if(string[j]==' ')
					string[j]=0;
				else
					break;
			}
		
		if(string[i]==' ' && string[i-1]==' '){
			int j;
			for(j=i-1; j<len-1; j++)
				string[j]=string[j+1];
			string[j]=0;
		}
		
		len=strlen(string);
	}
	
	printf("\nTodas as letras maiusculas:\n");
	for(int i=0; i<len; i++){
		if(string[i]>='a')
			string[i]-=32;
	}
	printf("%s\n", string);

	printf("\nTodas as letras minúsculas:\n");
		for(int i=0; i<len; i++){
			if(string[i]>='A' && string[i]<='Z')
				string[i]+=32;
		}
		printf("%s\n", string);
		
	printf("\nInício de cada palavra em maiusculo:\n");
	int inicio_palavra=1;
	for(int i=0; i<len; i++){
		if(inicio_palavra){
			if(string[i]>='a' && string[i]<='z')
				string[i]-=32;
			inicio_palavra=0;
		}
		if(string[i]==' ')
			inicio_palavra=1;
	}
	printf("%s", string);
	return 0;
}
