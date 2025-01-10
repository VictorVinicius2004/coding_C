/*A bandeira da Itália possui três cores, nesta sequência: verde, branco e vermelho
Faça um programa que sorteia aleatoriamente um vetor de tamanho N com valores que representam as
03 cores da bandeira italiana. Seu programa deve gerar como resultado a quantidade de bandeiras que
podem ser formadas a partir desse Array. Todas operações devem ser in-place (Não é permitido usar
arrays auxiliares).*/

#include <stdlib.h>
#include <stdio.h>

enum cores{VERDE, BRANCO, VERMELHO};

int main(){
	int bandeira[3]={VERDE, BRANCO, VERMELHO}, pos1=1, pos2=2;
	
	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++)
			switch(bandeira[j]){
				case VERDE: printf("Verde, "); break;
				case BRANCO: printf("Branco, "); break;
				case VERMELHO: printf("Vermelho, "); break;
			}
		printf("\n");
		
		int aux=bandeira[pos1];
		bandeira[pos1]=bandeira[pos2];
		bandeira[pos2]=aux;
		
		pos2= (pos2==2)? 0:2;
	}
	return 0;
}
