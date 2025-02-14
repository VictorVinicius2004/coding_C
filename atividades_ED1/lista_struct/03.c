/*Um ano tem 365 dias (às vezes 366). Qual a chance de duas pessoas fazerem aniversário no mesmo dia?
O paradoxo do aniversário diz que, se em uma festa tiver pelo menos 23 convidados, a chance de duas
pessoas fazerem aniversário no mesmo dia é de 50%. Se tiver 30 pessoas, a chance aumenta para 70%, e
se tiver 50 pessoas apenas, a chance é de 97%. Interessante não?!
Faça um programa que leia um valor N correspondente ao número de convidados de uma festa.
Gere N datas aleatórias - dt_rand_birth(), verifique se há ou não pessoas que podem comemorar
juntos, e que dia é esse. Informe também, dentre todas as datas geradas, qual dia da semana em que
mais pessoas nasceram, e que dia da semana é esse.*/

#include <datetime.h>
#include <stdio.h>

typedef struct{
	int dia;
	int repeticao;
}Dia;

void printdata(Datetime data){
	printf("%02d/%02d/%d\n", 
	data.day,
	data.mon,
	data.year);
}

int comparadata(Datetime data1, Datetime data2){
	if(data1.day==data2.day && data1.mon==data2.mon && data1.year==data2.year)
		return 1;
	return 0;
}

int main(){
	srand(time(NULL));
	int n;
	printf("Digite o número de convidados: ");
	scanf(" %d", &n);
	
	//gera as datas
	printf("Datas de aniversário dos convidados:\n");
	Datetime aniversarios[n];
	for(int i=0; i<n; i++)
		aniversarios[i]=dt_rand_birth(50);
	
	//ordena as datas(mais antiga para mais recente)
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(aniversarios[i].year>aniversarios[j].year){
				Datetime aux=aniversarios[i];
				aniversarios[i]=aniversarios[j];
				aniversarios[j]=aux;
			}
			else if(aniversarios[i].mon>aniversarios[j].mon 
			&& aniversarios[i].year==aniversarios[j].year){
				Datetime aux=aniversarios[i];
				aniversarios[i]=aniversarios[j];
				aniversarios[j]=aux;
			}
			else if(aniversarios[i].day>aniversarios[j].day 
			&& aniversarios[i].mon==aniversarios[j].mon 
			&& aniversarios[i].year==aniversarios[j].year){
				Datetime aux=aniversarios[i];
				aniversarios[i]=aniversarios[j];
				aniversarios[j]=aux;
			}
		}
	}
	
	//imprime as datas ordenadas
	for (int i = 0; i < n; i++)
		printdata(aniversarios[i]);
		
	printf("Datas comuns entre convidados:\n");
	Dia dia_mais_repetido;
	dia_mais_repetido.repeticao=0;
	for(int i=0; i<n-1; i++){
		Datetime datacomun;
		int cont=1;
		int datarepetida=0;
		
		for(int j=i+1; j<n; j++){
			//verifica se a uma data repetida
			if(comparadata(aniversarios[i], aniversarios[j])){
				datacomun=aniversarios[i];
				datarepetida=1;
			}
			
			//conta dias do mês repetidos
			if(aniversarios[j].day==aniversarios[i].day)
				cont++;
		}
		//se há uma data repetida printa
		if(datarepetida)
			printdata(datacomun);
		
		//verifica o dia mais repetido até o momento
		if(cont>dia_mais_repetido.repeticao){
			dia_mais_repetido.repeticao=cont;
			dia_mais_repetido.dia=aniversarios[i].day;
		}
	}
	
	printf("Dia do mês mais repetido: %d", dia_mais_repetido.dia);
	return 0;
}
