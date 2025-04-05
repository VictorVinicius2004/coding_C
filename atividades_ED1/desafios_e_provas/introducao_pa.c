#include <stdio.h>

typedef struct{
	int placa;
	char modelo[30];
}Carro;

int main() {
	FILE *arq = fopen("arq.dat", "rb+");
	if(!arq)
		arq = fopen("arq.dat", "wb+");
	if(!arq){
		printf("Erro ao criar o arquivo\n");
		return 1;
	}

	Carro car;
	scanf(" %29s", car.modelo);
	scanf(" %d", &car.placa);

	if(fwrite(&car, sizeof(Carro), 1, arq)){
		fflush(arq);
		printf("arquivo salvo\n");
	}
	
	fseek(arq,0,SEEK_END);
	Carro copia;
	if(fread(&copia, sizeof(Carro), 1, arq))
		printf("%s: %d\n", copia.modelo, copia.placa);
	
	printf("Deseja excluir o arquivo? 1-sim, 2-não\n");
	int escolha;
	scanf(" %d", &escolha);
	if(escolha==1)
		if(!remove("arq.dat"))
			printf("Arquivo excluído com sucesso\n");
	
	int i = fclose(arq);
	if(!i)
		printf("Arquivo fechado\n\n");
    return 0;
}
