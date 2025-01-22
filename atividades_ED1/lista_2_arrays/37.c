/*Um algoritmo básico de compactação de arquivos consiste em: ler o texto, indexar um código-valor para
cada palavra do texto, e após isso, representar o texto através destes códigos. As palavras repetidas,
portanto, podem ser substituídas por um único código, conseguindo assim diminuir consideravelmente o
tamanho final do arquivo. Implemente um protótipo deste algoritmo de compactação.*/

#include <string.h>
#include <stdio.h>

int main(){
	char texto[100], palavra[15], palavras[90][15];
	printf("Digite um texto:\n");
	scanf(" %[^\n]s", texto);
	int len=strlen(texto), cont1=0, cont2=0;
	
	for(int i=0; i<=len; i++){
		int igual=0;
		
		//verifica se iniciou outra palavra
		if( i<len && ((texto[i]>='a' && texto[i]<='z') || (texto[i]>='A' && texto[i]<='Z')) )
			palavra[cont2++]=texto[i];
		if(texto[i]==' ' || texto[i]==0){
			palavra[cont2]=0;
			cont2=0;
			
			//verifica se a palavra já possui um código
			for(int j=0; j<cont1; j++){
				if(!strcmp(palavra, palavras[j])){
					igual=1;
					break;
				}
			}
			
			//se a palavra ainda não recebeu um código
			if(!igual)
				strcpy(palavras[cont1++], palavra);
		}
		
	}
	
	//printando os códigos
	cont2=0;
	for(int i=0; i<=len; i++){
		int pos_palavra;

		if( i<len && ((texto[i]>='a' && texto[i]<='z') || (texto[i]>='A' && texto[i]<='Z')) )
			palavra[cont2++]=texto[i];
		if(texto[i]==' ' || texto[i]==0){
			palavra[cont2]=0;
			cont2=0;

			for(int j=0; j<cont1; j++){
				if(!strcmp(palavra, palavras[j])){
					pos_palavra=j;
					break;
				}
			}
			printf("%02d ", pos_palavra);
		}
	}
	return 0;
}

