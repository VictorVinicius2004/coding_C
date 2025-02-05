#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int revolver[6]={0}, tambor=0, vencedor=0;
	revolver[rand()%6]=1;

	printf("O computador irá escolher um número entre 0 e 99(inclusive) e você terá que adivinha-lo, depois os papeis irão se inverter\n");
	printf("Quem acertar o número do outro com mais tentativas irá ter que disparar o revólver\n");
	printf("Pressione ENTER para continuar\n");
	getchar();
	system("clear");
	
	do{
		int numpc, contpc=0, contusr=0, escolhapc, escolhausr, min=0, max=100;
		char dica;
		
		numpc=rand()%100;
		printf("O computador escolheu um número entre 0 e 99.\n");
		do{
			if(contusr>0){
				if(escolhausr>numpc)
					printf("tente um número menor\n");
				else if(escolhausr<numpc)
					printf("Tente um número maior\n");
				else
					break;
			}
			
			printf("Tentativa %d \nDigite: ", ++contusr);
			scanf(" %d", &escolhausr);
			system("clear");
		}while(1);
		while(getchar()!='\n');
		
		printf("Vez do computador, pense em um número entre 0 e 99\n");
		printf("Caso o computador escolha um número menor digite '>', se for um número maior digite '<', se acertar digite '=', se quiser resetar digite '#'\n");
		printf("Pressione Enter para continuar.\n");
		getchar();
		system("clear");
		do{
			int acertou=0, valido=1;
			
			if(contpc>0){
				printf("Digite: ");
				scanf(" %c", &dica);
				system("clear");
				switch(dica){
					case '>':
						min=escolhapc+1;
						break;
					case '<':
						max=escolhapc;
						break;
					case '=':
						acertou=1;
						break;
					case '#':
						max=100;
						min=0;
						valido=0;
						contpc=0;
						break;
					default:
						printf("Opção inválida\n");
						valido=0;
				}
			}
			
			if(acertou)
				break;
			
			if(valido){
				escolhapc=(max-min)/2+min;
				contpc++;
			}
			printf("Tentativa %d \nO computador escolheu %d\n", contpc, escolhapc);
			printf("'>' = tente um maior, '<' = tente um menor, '=' = acertou, '#' = resetar\n");
		}while(1);
		while(getchar()!='\n');
		
		printf("PC vs usr\n");
		printf("%02d vs %02d\n", contpc, contusr);
		if(contpc<contusr){
			printf("Você perdeu a rodada e agora terá que disparar o revolvér.\n pressione ENTER para continuar\n");
			getchar();
			system("clear");
			printf("Revolver[%d/6]\n", ++tambor);
			system("sleep 2.5");
			
			switch(revolver[tambor]){
				case 0:
					printf("CLICK \nParece que não foi desta vez\n"); break;
				case 1: 
					printf("BAM \nVocê perdeu\n"); vencedor=1;
			}
		}
		else if(contpc>contusr){
			printf("O computador perdeu a rodada\n");
			printf("Revolver[%d/6]\n", ++tambor);
			system("sleep 2.5");
			
			switch(revolver[tambor]){
				case 0:
					printf("CLICK \nParece que não foi desta vez\n"); break;
				case 1: 
					printf("BAM \nVocê venceu\n"); vencedor=1;
			}
		}
		else
			printf("Empate, tentem novamente\n");
	}while(!vencedor);
	return 0;
}

