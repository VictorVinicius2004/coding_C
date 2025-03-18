#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	int codigo;
	char placa[20];
	int passageiros;
	int manutencao;
}Veiculo_da_frota;

typedef struct{
	char cidade_origem[50];
	char cidade_destino[50];
	int codigo_viagem;
	int codigo_veiculo;
	int poltronas[100];
	int num_passageiros;
	float valor_passagem;
}Viagem;

#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define FIM_COR "\033[0m"
#define FALSO 0
#define VERDADEIRO 1

enum POLTRONAS {VAZIO, CHEIO, FIM_POLTRONAS};

void espera_ENTER(char msg[]){
	printf("%sPressione ENTER para continuar", msg);
	while(getchar()!='\n');
	while(getchar()!='\n');
}

int escolha(){
	int choice;
	printf("Digite: ");
	do{
		scanf(" %d", &choice);
	}while(choice<1 || choice>7);
	return choice;
}

int gera_codigo_veiculo(Veiculo_da_frota veiculo[], int *cont){
	do{
		int cod=rand()%(10000-1000)+1000;
		int repetido=0;
		for(int i=0; i<*cont; i++)
			if(veiculo[i].codigo==cod){
				repetido=1;
				break;
			}
		
		if(!repetido)
			return cod;
	}while(1);
}

int placa_valida(Veiculo_da_frota veiculos[], int *cont){
	for(int i=0; i<*cont; i++)
		if(!strcmp(veiculos[i].placa, veiculos[*cont].placa))
			return 0;
	return 1;
}

void cadastro_veiculo(Veiculo_da_frota veiculos[], int *cont){
	system("clear");
	int saida=0;
	do{
		printf("Digite a placa do veículo: ");
		do{
			scanf(" %s", veiculos[*cont].placa);
		}while(!placa_valida(veiculos, cont));

		printf("Digite a quantidade de passagieros(max 100): ");
		do{
			scanf(" %d", &veiculos[*cont].passageiros);
		}while(veiculos[*cont].passageiros>100 || veiculos[*cont].passageiros<1);
				
		veiculos[*cont].codigo = gera_codigo_veiculo(veiculos, cont);
		printf("O código do veículo será: %d\n", veiculos[*cont].codigo);
		
		printf("Veículo cadastrado\n");
		veiculos[*cont].manutencao = FALSO;

		*cont+=1;

		printf("Deseja sair? 0-não, 1-sim\n");
		scanf(" %d", &saida);
	}while(!saida);
}

int procura_carro(Veiculo_da_frota veiculos[], int cont, int codigo){
	for(int i=0; i<cont; i++)
		if(veiculos[i].codigo==codigo)
			return i;

	return -1;
}

int procura_viagem(Viagem viagens[], int cont, int codigo){
	for(int i=0; i<cont; i++)
		if(viagens[i].codigo_viagem==codigo)
			return i;
	return -1;
}

void inicializa_poltronas(Viagem viagens[], int cont, int passageiros){
	for(int i=0; i<passageiros; i++)
		viagens[cont].poltronas[i]=VAZIO;
	viagens[cont].poltronas[passageiros]=FIM_POLTRONAS;

	int cont_preenchidos=0;
	do{
		int pos=rand()%passageiros;
		if(viagens[cont].poltronas[pos]==VAZIO){
			viagens[cont].poltronas[pos]=CHEIO;
			cont_preenchidos++;
		}
	}while(cont_preenchidos<passageiros/2);
	viagens[cont].num_passageiros=passageiros;
}

void cadastro_viagem(Viagem viagens[], int *cont, Veiculo_da_frota veiculos[], int cont_veiculos){
	system("clear");
	do{
		printf("Cidade de origem: ");
		scanf(" %s", viagens[*cont].cidade_origem);
		printf("Cidade destino: ");
		scanf(" %s", viagens[*cont].cidade_destino);
		printf("Digite o valor da passagem: ");
		scanf(" %f", &viagens[*cont].valor_passagem);

		do{
			printf("Veículos:\n");
			for(int i=0; i<cont_veiculos; i++)
				printf("%d\n", veiculos[i].codigo);

			printf("Código do veículo: ");
			scanf(" %d", &viagens[*cont].codigo_veiculo);

			int posicao_veiculo = procura_carro(veiculos, cont_veiculos, viagens[*cont].codigo_veiculo);
			if(posicao_veiculo!=-1){
				inicializa_poltronas(viagens, *cont, veiculos[posicao_veiculo].passageiros);
				break;
			}
			else
				espera_ENTER("Código inválido ou veículo em manutenção\n");
		}while(1);

		do{
			int code=rand()%(10000-1000)+1000;
			if(procura_viagem(viagens, *cont, code)==-1){
				viagens[*cont].codigo_viagem=code;
				break;
			}
		}while(1);
		*cont+=1;

		int saida;
		printf("Deseja finalizar cadastro de viagens? 1-sim, 0-não\n");
		scanf(" %d", &saida);
		if(saida==1)
			return;
	}while(1);
}

int qntd_lugares_vagos(Viagem viagem){
	int cont=0;
	for(int i=0; i<viagem.num_passageiros; i++)
		if(viagem.poltronas[i]==VAZIO)
			cont++;

	return cont;
}

void print_viagem(Viagem viagem){
		printf("Viagem: \nCódigo da viagem: %d \nCódigo do veículo: %d \nTrajeto: de %s para %s; \nvalor: R$ %.2f; \nN° de lugares vagos: %d\n\n", 
		 viagem.codigo_viagem, viagem.codigo_veiculo, viagem.cidade_origem, viagem.cidade_destino, viagem.valor_passagem, qntd_lugares_vagos(viagem));
}

void print_poltronas(Viagem viagem){
	for(int i=0; i<viagem.num_passageiros; i++){
		if(viagem.poltronas[i]==VAZIO)
			printf("%s%02d%s ", VERDE, i, FIM_COR);
		else
			printf("%s%02d%s ", VERMELHO, i, FIM_COR);
		if((i+1)%3==0)
			printf("\n");
	}
	printf("\n");
}

void vender_passagem(Viagem viagens[], int cont_viagens){
	system("clear");
	do{
		system("clear");
		char origem[30], destino[30];
		printf("Digite a cidade de origem(SAIR para sair): ");
		scanf(" %s", origem);
		if(!strcmp("SAIR", origem))
			return;
		printf("Digite a cidade de destino: ");
		scanf(" %s", destino);

		int encontrado=0;
		for(int i=0; i<cont_viagens; i++)
			if(!strcmp(viagens[i].cidade_origem, origem) && !strcmp(viagens[i].cidade_destino, destino)){
				print_viagem(viagens[i]);
				encontrado=1;
			}
		if(!encontrado){
			espera_ENTER("Não há viagens com essa rota");
			continue;
		}

		int codigo;
		printf("digite o código da viagem que deseja escolher: ");
		scanf(" %d", &codigo);

		int posicao = procura_viagem(viagens, cont_viagens, codigo);
		if(posicao==-1)
			espera_ENTER("Código inválido\n");
		else{
			print_poltronas(viagens[posicao]);
			printf("digite o/s lugares desejados(-1 para sair):\n");
			do{
				int lugar;
				scanf(" %d", &lugar);
				if(lugar==-1)
					break;

				if(viagens[posicao].poltronas[lugar]==CHEIO)
					espera_ENTER("Lugar já ocupado\n");
				else
					viagens[posicao].poltronas[lugar]=CHEIO;
			}while(1);
		}
	}while(1);
}

void relatorio_veiculos(Veiculo_da_frota veiculos[], int cont){
	for(int i=0; i<cont; i++){
		printf("Veículo: \nCódigo: %d \nPlaca: %s \nQuantidade de passageiros: %d\n", veiculos[i].codigo, veiculos[i].placa, veiculos[i].passageiros);
		if(veiculos[i].manutencao==VERDADEIRO)
			printf("Em manutenção: SIM\n\n");
		else
			printf("Em manutenção: NÃO\n\n");
	}
	espera_ENTER("");
}

void relatorio_viagens(Viagem viagens[], int cont){
	for(int i=0; i<cont; i++){
		float valor_arrecadado = viagens[i].valor_passagem*(viagens[i].num_passageiros - qntd_lugares_vagos(viagens[i]));
		printf("Valor arrecadado: %.2f\n", valor_arrecadado);
		print_viagem(viagens[i]);
		print_poltronas(viagens[i]);
	}
	espera_ENTER("");
}

void manutencao(Veiculo_da_frota veiculos[], int cont){
	do{
		system("clear");

		for(int i=0; i<cont; i++){
			printf("Código co carro: %d \nEm manutenção? ", veiculos[i].codigo);
			if(veiculos[i].manutencao==VERDADEIRO)
				printf("SIM\n");
			else
				printf("NÃO\n");
		}

		printf("Digite o código do carro que deseja modificar o status(-1 para sair): ");
		int codigo;
		scanf(" %d", &codigo);
		if(codigo==-1)
			return;

		int pos = procura_carro(veiculos, cont, codigo);

		if(pos==-1)
			espera_ENTER("código inválido\n");
		else{
			veiculos[pos].manutencao = (veiculos[pos].manutencao==VERDADEIRO)? FALSO : VERDADEIRO;
			espera_ENTER("Status alterado\n");
		}
	}while(1);
}

void interface(){
	system("clear");
	printf("1 - Cadastrar veículo na frota\n");
	printf("2 - Cadastrar viagem\n");
	printf("3 - Vender passagem\n");
	printf("4 - Relatório: frota de veículos\n");
	printf("5 - Relatório: viagens e passagens vendidas\n");
	printf("6 - Carros em manutenção\n");
	printf("7 - Sair\n");
}

int main(){
	srand(time(NULL));
	Veiculo_da_frota veiculos_da_frota[100]; 
	int cont_veiculos=0;
	Viagem viagens[100];
	int cont_viagens=0;
	int sair=0;

	do{
		interface();

		switch(escolha()){
			case 1:
				cadastro_veiculo(veiculos_da_frota, &cont_veiculos);
				break;
			case 2:
				if(cont_veiculos>0)
					cadastro_viagem(viagens, &cont_viagens, veiculos_da_frota, cont_veiculos);
				else
					espera_ENTER("Não há veiculos para realizar viagem\n");
				break;
			case 3:
				if(cont_viagens>0)
					vender_passagem(viagens, cont_viagens);
				else
					espera_ENTER("Não há viagens cadastradas\n");
				break;
			case 4:
				if(cont_veiculos>0)
					relatorio_veiculos(veiculos_da_frota, cont_veiculos);
				else
					espera_ENTER("Não há veículos cadastrados\n");
				break;
			case 5:
				if(cont_viagens>0)
					relatorio_viagens(viagens, cont_viagens);
				else
					espera_ENTER("Não há viagens cadastradas\n");
				break;
			case 6:
				if(cont_veiculos>0)
					manutencao(veiculos_da_frota, cont_veiculos);
				else
					espera_ENTER("Não há veículos cadastrados");
				break;
			case 7:
				sair=1;
				break;
		}
	}while(!sair);
}
