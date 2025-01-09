#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*Gere um vetor de tamanho aleatório (no máximo 30) e preencha-o com valores também aleatórios entre
0 e 10. Sabe-se que o ponto de equilíbrio de um vetor é o índice no qual, partindo deste índice o lado
esquerdo possui exatamente o mesmo valor de soma do que o lado direito. Gere e imprima inúmeros
vetores até encontrar algum que possua ponto de equilíbrio, e qual é este ponto.*/

int main(){
	srand(time(NULL));
	int vetor[30], qntd, cont=0, p_equilibrio, suml, sumr;
	
	printf("vetores:\n");
	do{
		p_equilibrio=0;
		cont++;
		
		//gerando e printando o vetor
		for(int i=0; i<30; i++)
			vetor[i]=-1;
			
		printf("%02d°: valores - ", cont);
		qntd=rand()%28+3;
		for(int i=0; i<qntd; i++){
			vetor[i]=rand()%11;
			printf("%02d ", vetor[i]);
		}
		printf("\n     índices - ");
		for(int i=0; i<qntd; i++)
			printf("%02d ", i);
		printf("\n\n");
		
		//verificando ponto de equilíbrio
		for(int i=1; i<qntd-1; i++){
			suml=0;
			sumr=0;
			for(int j=0; j<qntd; j++){
				if(j<i)
					suml+=vetor[j];
				if(j>i)
					sumr+=vetor[j];
			}
			
			if(suml==sumr){
				p_equilibrio=i;
				break;
			}
		}
	}while(!p_equilibrio);
	
	printf("Ponto de equilíbrio do %d° vetor= índice:%d, valor:%d\n", cont, p_equilibrio, vetor[p_equilibrio]);
	printf("Soma do lado esquerdo: %d\nSoma do lado direito: %d\n", suml, sumr);
	return 0;
}
