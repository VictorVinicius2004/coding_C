/*Desenvolva um programa em C que faça a geração de senhas fortes. Uma senha forte é uma string
contendo entre 8 e 16 caracteres, com obrigatoriamente: 1 caractere numérico, 1 caractere maiusculo,
1 minúsculo e 1 caractere especial. Imprima 10 senhas fortes geradas aleatoriamente.*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	srand(time(NULL));
	
	int cont=0;
	do{
		int senha[16], caracteres=rand()%(9)+8, m=0, M=0, n=0, cs=0;
		for(int i=0; i<caracteres; i++){			
			switch(rand()%4){
				case 0: 
					senha[i]=rand()%('z'-'a'+1)+'a'; 
					m=1; 
					break;
				case 1: 
					senha[i]=rand()%('Z'-'A'+1)+'A'; 
					M=1; 
					break;
				case 2: 
					senha[i]=rand()%('9'-'0'+1)+'0'; 
					n=1; 
					break;
				case 3: 
					senha[i]=rand()%(38-33+1)+33; 
					cs=1; 
					break;
			}
		}
		
		if(m && M && n && cs){
			printf("%02d°: ", ++cont);
			for(int i=0; i<caracteres; i++)
				printf("%c", senha[i]);
			printf("\n");
		}
	}while(cont<10);
	return 0;
}
