#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ORDEM 10

int main(){
	srand(time(NULL));
	int matriz[ORDEM][ORDEM], contl=0, contc=0;
	
	//repetição de valores permitido
	//for(int i=0; i<ORDEM; i++){	
		//for(int j=0; j<ORDEM; j++){
			//matriz[i][j]=rand()%(ORDEM*ORDEM);
			//printf("%02d ", matriz[i][j]);
		//}
		//printf("\n");
	//}
	
	//sem repetição de valores
	do{
		int num=rand()%(ORDEM*ORDEM);
		int repetido=0;
		
		for(int i=0; i<ORDEM; i++){
			for(int j=0; j<=contc; j++){
				if(matriz[i][j]==num){
					repetido=1;
					break;
				}
				
				if(i==contl && j==contc)
					break;
			}
		}
		
		if(!repetido){
			matriz[contl++][contc]=num;
			printf("%02d ", num);
			if(contl==ORDEM){
				contl=0;
				contc++;
				printf("\n");
			}
		}
	}while(contl<ORDEM && contc<ORDEM);
	
	for(int j=0; j<ORDEM; j++){
		for(int i=0; i<ORDEM; i++){
			
			for(int J=j; J<ORDEM; J++){
				for(int I=0; I<ORDEM; I++){
					int aux=matriz[i][j];
					
					if(J==j && I<=i)
						continue;
					else
						if(matriz[i][j]>matriz[I][J]){
							matriz[i][j]=matriz[I][J];
							matriz[I][J]=aux;
						}
				}
			}
		}
	}
	
	printf("\nOrdenado:\n");
	for(int i=0; i<ORDEM; i++)	{
		for(int j=0; j<ORDEM; j++)
			printf("%02d ", matriz[i][j]);
		printf("\n");
	}
	return 0;
}

