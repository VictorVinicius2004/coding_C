/*Faça um programa que preencha o cadastro de N pessoas. “Pessoa” possui os atributos “Nome” (string)
e “Data de Nascimento”. O usuário deve preencher apenas a informação “Nome”.
“Data de Nascimento” deve ser gerada aleatoriamente através da biblioteca "datetime.h".
Imprima o relatório de pessoas cadastradas, ORDENADAS pelas suas idades atuais (Obs.: verifique se a
pessoa já completou ou não o aniversário no ano atual).*/

#include <stdlib.h>
#include <stdio.h>
#include <datetime.h>

typedef struct{
	char nome[60];
	int idade;
	Datetime birth_date;
}Pessoa;

int calculaidade(Datetime dtbirth){
	Datetime dtnow=dt_now();
	int idade=dtnow.year-dtbirth.year;
	
	idade-=(dtnow.mon<dtbirth.mon)? 1 :
	(dtnow.day<dtbirth.day && dtnow.mon==dtbirth.mon)? 1 :0;
	
	return idade;
}

void printdata(Datetime data){
	printf("%02d/%02d/%d\n",
		data.day,
		data.mon,
		data.year);
}

int main(){
	srand(time(NULL));
	int n;
	printf("Digite o número de pessoas:\n");
	scanf(" %d", &n);
	
	printf("digite o nome de cada pessoa:\n");
	Pessoa pessoas[n];
	for(int i=0; i<n; i++){
		scanf(" %[^\n]s", pessoas[i].nome);//recebe o nome
		pessoas[i].birth_date=dt_rand_birth(50);//recebe a data de nascimento
		pessoas[i].idade=calculaidade(pessoas[i].birth_date);//calcula a idade com base na data atual e de nascimento
	}
	system("clear");
	
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(pessoas[i].idade>pessoas[j].idade){
				Pessoa aux=pessoas[i];
				pessoas[i]=pessoas[j];
				pessoas[j]=aux;
			}
	
	for(int i=0; i<n; i++){
		printf("%s\n", pessoas[i].nome);
		printdata(pessoas[i].birth_date);
		printf("%d\n\n", pessoas[i].idade);
	}
	return 0;
}

