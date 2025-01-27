#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int n, min, max;
	do{
		printf("Digite a quantidade de valores a serem sorteados, o valor mínimo e o máximo respectivamente(min+max>n)\n");
		scanf(" %d %d %d", &n, &min, &max);
		system("clear");
	}while(min+max<=n);
	
	int vetor[n], cont=0;
	do{
		int num=rand()%(max-min+1)+min;
		int repetido=0;
		
		for(int j=0; j<cont; j++)
			if(vetor[j]==num){
				repetido=1;
				break;
			}
		
		if(!repetido){
			vetor[cont]=num;
			printf("[%02d] ", vetor[cont++]);
		}
	}while(cont<n);
	
	//problema 1
	int diff=0, pos, diff_atual;
	for(int i=0; i<n-1; i++){
		int soma;
		diff_atual = (vetor[i]-vetor[i+1]<0)? (vetor[i]-vetor[i+1])*-1 : (vetor[i]-vetor[i+1]);
		if(diff<diff_atual){
			diff=diff_atual;
			soma=vetor[i]+vetor[i+1];
			pos=i;
		}
		else if(diff_atual==diff)
			if(soma<vetor[i]+vetor[i+1]){
				soma=vetor[i]+vetor[i+1];
				pos=i;
			}
	}
	
	printf("\n\nMaior diferença entre valores consecutivos: \n[%02d, %02d]\n", vetor[pos], vetor[pos+1]);
	
	//problema 2
	int pos1=0, pos1_atual=0, pos2=0, pos2_atual=0;
	for(int i=1; i<n; i++){
		int soma=0, soma_atual=0;
		if(vetor[i]>vetor[i-1])
			pos2_atual=i;
			
		if(vetor[i]<vetor[i-1] || i==n-1){
			diff=pos2-pos1;
			diff_atual=pos2_atual-pos1_atual;
			
			if(diff_atual>diff){
				pos1=pos1_atual;
				pos2=pos2_atual;
			}
			if(diff==diff_atual && diff){
				for(int j=pos1; j<=pos2; j++)
					soma+=vetor[j];
				for(int j=pos1_atual; j<=pos2_atual; j++)
					soma_atual+=vetor[j];
				
				if(soma_atual>soma){
					pos1=pos1_atual;
					pos2=pos2_atual;
				}
			}
			
			pos1_atual=i;
		}
	}
	
	printf("\n\nMaior sequência crescente: \n[");
	for(int i=pos1; i<=pos2; i++){
		if(i<pos2)
			printf("%02d, ", vetor[i]);
		else
			printf("%02d]", vetor[i]);
	}
	return 0;
}

