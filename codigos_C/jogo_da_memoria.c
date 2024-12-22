#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(){
	srand(time(NULL));
	int esc, cont=0;
	printf("Digite o número de pares.\n");
	scanf(" %d", &esc);
	
	//preenchendo o baralho
	int baralho[esc*2], mao[esc*2];
	for (int i = 0; i < esc*2; i+=2){
		cont++;
		for (int j = 0; j < 2; j++){
			baralho[i+j]=cont;
		}
	}
	
	//colocando as cartas na mão
	cont=0;
	do{
		int x=rand()%(esc*2);
		if(baralho[x]){
			mao[cont]=baralho[x];
			baralho[x]=0;
			cont++;
		}
	} while (cont<esc*2);
	
	//parte principal
	int pos1, pos2, acertos=0;
	cont=0;
	
	do{
		do{
			for (int i = 0; i < esc*2; i++){
				if(!mao[i])
					printf("   ");
				else{
					if((pos1!=i && pos2!=i) || cont==0)
						printf("[] ");
					else
						printf("%02d ", mao[i]);
				}
			}
			printf("\n");
			for (int i = 0; i < esc*2; i++){
				if(!mao[i])
					printf("   ");
				else
					printf("%02d ", i);
			}
			printf("\n");
			
			if(mao[pos1]==mao[pos2] && cont==1){
				acertos++;
				mao[pos1]=0;
				mao[pos2]=0;
			}
			if(acertos==esc)
				break;
			
			printf("Digite duas posições.\n");
			scanf(" %d %d", &pos1, &pos2);
			system("clear");
			if((pos1>=0 && pos1<esc*2)&&(pos2>=0 && pos2<esc*2)&&(pos1!=pos2)&&(mao[pos1]!=0)&&(mao[pos2]!=0))
				break;
		}while(1);
		cont=1;
	} while (1);
	system("clear");
	printf("Parabens!! Você acertou todos os pares.\n");
	return 0;
}

