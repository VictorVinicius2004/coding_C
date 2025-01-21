/*Em uma eleição para representante da turma, existem K candidatos. Faça com que seu programa leia o
valor de K e o nome de cada um dos candidatos.
Após isso, programe uma espécie de urna eletrônica, onde o voto do candidato é representado pelo seu
número de sequência de cadastro na urna (p.ex.: 1 - 2 - 3 - ... - K).
O valor 0 corresponde a um voto em BRANCO, e um valor superior a K representa um voto NULO.
A votação deve ser encerrada assim que for informado um voto com valor negativo.
Ao final da votação, seu programa deve gerar o seguinte relatório:
a) A quantidade total de votos;
b) O nome e a quantidade de votos para cada candidato;
c) A quantidade de votos nulos;
d) A quantidade de votos em branco;
e) O nome do vencedor das eleições;
f) O percentual do vencedor em relação ao número de votos válidos;*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int k;
	printf("Digite a quantidade de candidatos.\n");
	scanf(" %d", &k);
	
	char candidatos[k][20];
	printf("Digite os nomes dos candidatos a seguir:\n");
	for(int i=0; i<k; i++){
		printf("Candidato %d\n",i+1);
		scanf(" %s", candidatos[i]);
		system("clear");
	}
		
	int votos[k], nulos=0, em_branco=0, total_votos=0, votos_validos=0;
	for(int i=0; i<k; i++)
		votos[i]=0;
		
	do{
		int escolha;
		printf("Digite seu voto(0 em branco, >=%d nulo, -1 encerra os votos): ", k+1);
		scanf(" %d", &escolha);
		system("clear");
		
		if(escolha>=0)
			total_votos++;
		
		if(escolha>0 && escolha<=k){
			votos[escolha-1]++;
			votos_validos++;
		}
		else if(escolha==0)
			em_branco++;
		else if(escolha>=k+1)
			nulos++;
		else
			break;
	}while(1);
	
	//a
	printf("Quantidade total de votos: %d\n\n", total_votos);
	
	//b
	printf("Votos por candidato:\n");
	for(int i=0; i<k; i++)
		printf("%s - %d votos\n", candidatos[i], votos[i]);
		
	//c
	printf("\nquantidade de votos nulos: %d\n\n", nulos);
	
	//d
	printf("quantidade de votos em branco: %d\n\n", em_branco);
	
	//e
	int vencedor=0;
	for(int i=1; i<k; i++)
		if(votos[vencedor]<votos[i])
			vencedor=i;
	printf("O vencedor foi o candidato %s com %d votos\n\n", candidatos[vencedor], votos[vencedor]);
	
	//f
	printf("Percentual de votos do vencedor em relação ao total de votos válidos: %.1f%%", ((float)votos[vencedor]/votos_validos)*100);
	return 0;
}

