#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*O algoritmo LRU (Least Recently Used) é uma política de gerenciamento de memória cache que invalida o
item que foi acessado menos recentemente. Isso significa que se um item não foi acessado há muito
tempo, ele terá prioridade na remoção. Considere um vetor com N elementos, sorteados no intervalo
entre X e Y (inclusive). Considerando que os primeiros índices foram os acessados recentemente, exclua
da lista o elemento conforme algoritmo LRU (todos os itens iguais devem ser excluídos na mesma
iteração). Solução in-place (não deve-se usar vetor auxiliar). Execute essa operação N vezes, ou seja, até
que o array esteja vazio novamente. Imprima o conteúdo da “memória cache” em cada iteração.*/

int main(){
	srand(time(NULL));
	int n, x, y;
	printf("Digite o valor de n.\n");
	scanf(" %d", &n);
	printf("Digite o min e o max.\n");
	scanf(" %d %d", &x, &y);
	int array[n];
	
	for (int i = 0; i < n; i++)
		array[i]=rand()%(y-x+1)+x;
		
	for (int i = y+1; i >=x ; i--){
		int removido=0;
		for(int j=0; j<n; j++)
			if(array[j]==i){
				array[j]=y+1;
				removido=1;
			}
		
		for(int j=0; j<n; j++)
			if((array[j]<=y && removido) || i==y+1)
				printf("%02d ", array[j]);
		if(removido || i==y+1)
		printf("\n");
	}
	printf("Programa finalizado.");
	return 0;
}

