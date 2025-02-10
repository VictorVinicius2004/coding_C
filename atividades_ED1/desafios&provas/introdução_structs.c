#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char cpf[12], nome[45];
	int idade;
	float altura, peso, imc;
}Pessoa;

#define caixabaixa(caractere) ((caractere>='A' && caractere<='Z' && caractere!=0)? (caractere+32) : caractere)

int main(){
	Pessoa cadastro[100];
	int contpessoa=0;
	
	printf("Recebendo dados...\n");
	do{
		printf("Nome: ");
		scanf(" %[^\n]s", cadastro[contpessoa].nome);
		printf("Idade: ");
		scanf(" %d", &cadastro[contpessoa].idade);
		printf("Altura: ");
		scanf(" %f", &cadastro[contpessoa].altura);
		printf("Peso: ");
		scanf(" %f", &cadastro[contpessoa].peso);
		printf("CPF: ");
		scanf(" %s", cadastro[contpessoa].cpf);
		
		cadastro[contpessoa].imc=cadastro[contpessoa].peso/(cadastro[contpessoa].altura*cadastro[contpessoa].altura);
		contpessoa++;
		
		int saida;
		printf("Deseja encerrar a entrada de dados? 1-não, 2-sim\n");
		scanf(" %d", &saida);
		if(saida==2) break;
	}while(1);
	system("clear");
	
	int escolha_ordenacao;
	printf("Dados recebidos \nDeseja ordenar os cadastros de acordo com:\n");
	printf("1-Nome \n2-idade \n3-altura \n4-peso \n5-imc\n");
	scanf(" %d", &escolha_ordenacao);
	system("clear");
	
	switch(escolha_ordenacao){
		case 1://nome
			for(int i=0; i<contpessoa-1; i++){
				for(int j=i+1; j<contpessoa; j++){
					for(int k=0; k<35; k++){
						char c1=caixabaixa(cadastro[i].nome[k]);
						char c2=caixabaixa(cadastro[j].nome[k]);
						
						if(c1==0 && c2==0)
							break;
							
						if(c1>c2){
							Pessoa aux=cadastro[i];
							cadastro[i]=cadastro[j];
							cadastro[j]=aux;
							break;
						}
					}
				}
			}
			break;
		case 2://idade
			for(int i=0; i<contpessoa-1; i++)
				for(int j=i+1; j<contpessoa; j++)
					if(cadastro[i].idade>cadastro[j].idade){
						Pessoa aux=cadastro[i];
						cadastro[i]=cadastro[j];
						cadastro[j]=aux;
					}
			break;
		case 3://altura
			for(int i=0; i<contpessoa-1; i++)
				for(int j=i+1; j<contpessoa; j++)
					if(cadastro[i].altura>cadastro[j].altura){
						Pessoa aux=cadastro[i];
						cadastro[i]=cadastro[j];
						cadastro[j]=aux;
					}
			break;
		case 4://peso
			for(int i=0; i<contpessoa-1; i++)
				for(int j=i+1; j<contpessoa; j++)
					if(cadastro[i].peso>cadastro[j].peso){
						Pessoa aux=cadastro[i];
						cadastro[i]=cadastro[j];
						cadastro[j]=aux;
					}
			break;
		case 5://imc
			for(int i=0; i<contpessoa-1; i++)
				for(int j=i+1; j<contpessoa; j++)
					if(cadastro[i].imc>cadastro[j].imc){
						Pessoa aux=cadastro[i];
						cadastro[i]=cadastro[j];
						cadastro[j]=aux;
					}
			break;
	}
	
	for(int i=0; i<contpessoa; i++){
	printf("Nome: %s\n", cadastro[i].nome);
	printf("CPF: %s\n", cadastro[i].cpf);
	printf("Idade: %d\n", cadastro[i].idade);
	printf("Altura: %.2f\n", cadastro[i].altura);
	printf("Peso: %.2f\n", cadastro[i].peso);
	printf("IMC: %.2f\n", cadastro[i].imc);
	if(cadastro[i].imc<18.5)
		printf("Abaixo do peso\n\n");
	else if(cadastro[i].imc<24.5)
		printf("Saudável\n\n");
	else if(cadastro[i].imc<30)
		printf("Acima do peso\n\n");
	else
		printf("Obesidade\n\n");
	}
	return 0;
}
