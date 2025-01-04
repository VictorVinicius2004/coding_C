#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int tentativas, lados[6]={0}, num;
	printf("Digite quantas vezes o dado será rolado.\n");
	scanf(" %d", &tentativas);
	
	for(int i=0; i<tentativas; i++){
		num=rand()%6+1;
		printf("Tentativa %02d: %02d\n", i+1, num);
		switch(num){
			case 1:
				lados[0]++;
				break;
			case 2:
				lados[1]++;
				break;
			case 3:
				lados[2]++;
				break;
			case 4:
				lados[3]++;
				break;
			case 5:
				lados[4]++;
				break;
			case 6:
				lados[5]++;
				break;
		}
	}
	
	printf("\n");
	for (int i = 0; i < 6; i++){
		printf("lado %d: %d vezes   | porcentagem: %.2f%%\n", i+1, lados[i], ((float)lados[i]/tentativas)*100);
	}
	return 0;
}

