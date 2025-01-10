#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int sorteio(float porcentagem, int vezes){
	srand(time(NULL));
	int cento=100;
	
	if(vezes<=0)
		return 0;
		
	if(porcentagem<100 && porcentagem>0){
		while(porcentagem-(int)porcentagem){
			porcentagem*=10;
			cento*=10;
		}
		
		for(int i=cento; i>0; i--)
			if(cento%i==0 && (int)porcentagem%i==0){
				cento/=i;
				porcentagem/=i;
				
			}

		for(int i=0; i<vezes; i++){
			int num=rand()%cento+1;

			if(num<=porcentagem)
				return 1;
		}
		
		return 0;
	}
	else{
		if(porcentagem>=100)
			return 1;
		if(porcentagem<=0)
			return 0;
	}
	
	//em caso de falha
	return 0;
}

int main(){
	float porcentagem;
	int vezes;
	printf("Digite a porcentagem.\n");
	scanf(" %f", &porcentagem);
	printf("Digite a quantidade de vezes a serem sorteadas.\n");
	scanf(" %d", &vezes);
	
	printf("\n%d", sorteio(porcentagem, vezes));
	return 0;
}
