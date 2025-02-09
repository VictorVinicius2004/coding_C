/*Leia uma matriz N x 3, onde cada linha representa uma data de nascimento, e as colunas representam,
respectivamente: dia, mês e ano. Após ler todos os valores, faça a impressão das datas ordenadas, em
formato: DD/MM/AAAA.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}Data;

int main(){
	int n;
	scanf(" %d", &n);
	
	Data datas[n];
	for(int i=0; i<n; i++){
		printf("%d° data de nascimento:\n", i+1);
		printf("Dia: ");
		scanf(" %d", &datas[i].dia);
		
		printf("Mês: ");
		scanf(" %d", &datas[i].mes);

		printf("Ano: ");
		scanf(" %d", &datas[i].ano);
		system("clear");
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			int trocado=0;
			if(datas[j].ano>datas[j+1].ano){
				Data aux=datas[j];
				datas[j]=datas[j+1];
				datas[j+1]=aux;
				trocado=1;
			}
			if(datas[j].mes>datas[j+1].mes && !trocado){
				Data aux=datas[j];
				datas[j]=datas[j+1];
				datas[j+1]=aux;
				trocado=1;
			}
			if(datas[j].dia>datas[j+1].dia && !trocado){
				Data aux=datas[j];
				datas[j]=datas[j+1];
				datas[j+1]=aux;
			}
		}
	}
	
	printf("Lista:\n");
	for(int i=0; i<n; i++){
		printf("%d°: %02d/%02d/%d\n", i+1, datas[i].dia, datas[i].mes, datas[i].ano); 
	}
	return 0;
}

