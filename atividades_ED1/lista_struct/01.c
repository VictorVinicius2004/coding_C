#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char arquitetura[35], cpu[35];
	int nucleos, ram, m_secundaria;
	float clock;
}Computador;

int main(){
	Computador pcs[50];
	int contpc=0;
	do{
		printf("Qntd de núcleos(-1 para finalizar a entrada de dados): ");
		scanf(" %d", &pcs[contpc].nucleos);
		if(pcs[contpc].nucleos<0) break;
		
		printf("Arquitetura: ");
		scanf(" %[^\n]s", pcs[contpc].arquitetura);
		
		printf("CPU: ");
		scanf(" %[^\n]s", pcs[contpc].cpu);
		
		printf("Memória principal: ");
		scanf(" %d", &pcs[contpc].ram);
		
		printf("Memória secundária: ");
		scanf(" %d", &pcs[contpc].m_secundaria);
		
		printf("Clocks: ");
		scanf(" %f", &pcs[contpc].clock);
		
		system("clear");
		contpc++;
	}while(1);
	
	for(int i=0; i<contpc; i++){
		printf("PC %d\n", i+1);
		printf("Qntd de núcleos: %d\n", pcs[i].nucleos);
		printf("Arquitetura: %s\n", pcs[i].arquitetura);
		printf("CPU: %s\n", pcs[i].cpu);
		printf("Memória principal: %d\n", pcs[i].ram);
		printf("Memória secundária: %d\n", pcs[i].m_secundaria);
		printf("Clocks: %.2f\n\n", pcs[i].clock);
	}
	return 0;
}

