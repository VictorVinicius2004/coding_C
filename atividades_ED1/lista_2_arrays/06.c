#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Gere um array de N números inteiros sorteados no intervalo entre X e Y (inclusive). Imprima o array
sorteado e depois elimine deste array os valores repetidos, mantendo a ordem original.
A solução deve ser in place, ou seja, todas as operações devem acontecer diretamente no mesmo array
de entrada (in-place), não sendo permitido portanto utilizar outros arrays auxiliares para ajudar na tarefa.
Imprima o array resultante após as exclusões.*/

int main(){
	srand(time(NULL));
	int n, x, y;
	printf("Digite um número:\n");
	scanf(" %d", &n);
	printf("Digite o mínimo e o máximo:\n");
	scanf(" %d %d", &x, &y);
	int array[n], num;
	
	printf("Array antes da exclusão dos repetidos:\n");
	for (int i = 0; i < n; i++){
		array[i]=rand()%(y-x+1)+x;
		printf("%d ", array[i]);
	}
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(array[i]==array[j] && i!=j){
				num=array[i];
				
				for(int k=0; k<n; k++)
					if(num==array[k])
						array[k]=y+1;
			}
		
	printf("\n\nArray depois da exclusão dos repetidos:\n");
	for (int i = 0; i < n; i++)
		if(array[i]<=y)
			printf("%d ", array[i]);
	return 0;
}

