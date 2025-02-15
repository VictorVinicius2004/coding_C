/*O gestor de arquivos de qualquer sistema operacional apresenta informações básicas dos arquivos em
um diretório, tais como: Nome do Arquivo (s), Tamanho em Bytes (i), Data de Criação do Arquivo
(datetime), Tipo de Arquivo (Imagem, Documento, Vídeo, Diretório, etc.). Faça um programa que simule
o gestor de arquivos de um S.O. Na primeira etapa, faça o cadastro de N arquivos. Encerre essa fase
quando o usuário informar a palavra “exit” para o nome do arquivo. Na segunda etapa, o programa
deverá listar todos os arquivos na ordem de preferência do usuário. Digitando a letra ‘N’ o sistema
deverá imprimir a lista ordenada considerando os Nomes. Digitando ‘B’ considere a quantidade de Bytes.
Digitando ‘D’ considere a data de criação, e digitando ‘T’ imprima a lista considerando o tipo. Repita
várias opções de listagem, até informar ‘X’ para encerrar a execução.*/

#include <stdio.h>
#include <stdlib.h>
#include <datetime.h>
#include <string.h>

#define caixabaixa(c) ((c>='A' && c<='Z')? c+32 : (c>='a' && c<='z')? c : ' ')

typedef struct{
	char nome[50];
	int tamanho;//em bytes
	Datetime criacao;
	char tipo[10];
}Diretorio;

Diretorio preenche_arquivo(){
	Diretorio arquivo;
	printf("Nome do arquivo: ");
	scanf(" %s", arquivo.nome);
	arquivo.tamanho=rand()%2048+1;
	arquivo.criacao=dt_rand_birth(5);
	printf("Tipo do arquivo: ");
	scanf(" %s", arquivo.tipo);
	system("clear");
	
	return arquivo;
}

int contdias(Datetime data){
	int dias;
	dias=data.year*360;
	dias+=data.mon*30;
	dias+=data.day;
	return dias;
}

void printdiretorios(Diretorio arquivo){
	printf("%s \n%s \n%d Bytes\n", arquivo.nome, arquivo.tipo, arquivo.tamanho);
	dt_print(arquivo.criacao);
	printf("\n");
}

int main(){
	srand(time(NULL));
	int n;
	printf("Quantos arquivos serão armazenados?\n");
	scanf(" %d", &n);
	
	Diretorio arquivos[n];
	for(int i=0; i<n; i++)
		arquivos[i]=preenche_arquivo();
	
	do{
		char escolha;
		int saida=0;
		printf("escolha a ordenação: N-nome, B-Bytes, D-data de criação, T-Tipo, X-sair\n");
		scanf(" %c", &escolha);
		system("clear");
		
		switch(escolha){
			case 'N'://nome
				for(int i=0; i<n-1; i++){
					for(int j=i+1; j<n; j++){
						for(int k=0; k<35; k++){
							char c1=caixabaixa(arquivos[i].nome[k]);
							char c2=caixabaixa(arquivos[j].nome[k]);
							
							if(c1==0 && c2==0)
								break;
								
							if(c1>c2){
								Diretorio aux=arquivos[i];
								arquivos[i]=arquivos[j];
								arquivos[j]=aux;
								break;
							}
						}
					}
				}
				break;
			case 'B'://bytes
				for(int i=0; i<n-1; i++)
					for(int j=i+1; j<n; j++)
						if(arquivos[i].tamanho<arquivos[j].tamanho){
							Diretorio aux=arquivos[i];
							arquivos[i]=arquivos[j];
							arquivos[j]=aux;
						}
				break;
			case 'D'://data
				for(int i=0; i<n-1; i++)
					for(int j=i+1; j<n; j++)
						if(contdias(arquivos[i].criacao)>contdias(arquivos[j].criacao)){
							Diretorio aux=arquivos[i];
							arquivos[i]=arquivos[j];
							arquivos[j]=aux;
						}
			case 'T'://tipo
				for(int i=0; i<n-1; i++){
					for(int j=i+1; j<n; j++){
						for(int k=0; k<35; k++){
							char c1=caixabaixa(arquivos[i].tipo[k]);
							char c2=caixabaixa(arquivos[j].tipo[k]);
							
							if(c1==0 && c2==0)
								break;
								
							if(c1>c2){
								Diretorio aux=arquivos[i];
								arquivos[i]=arquivos[j];
								arquivos[j]=aux;
								break;
							}
						}
					}
				}
				break;
			case 'X':
				saida=1;
				break;
			default:
				printf("opção inválida\n");
				continue;
		}
		for(int i=0; i<n; i++)
			printdiretorios(arquivos[i]);
		
		if(saida) break;	
	}while(1);
	return 0;
}

