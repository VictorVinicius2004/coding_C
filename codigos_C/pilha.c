#include <stdio.h>
#include <stdlib.h>

typedef struct Num{
	int num;
	struct Num *next;
}Num;

void espera_enter(char *msg){
	printf("%s\nAperte ENTER para continuar\n",msg);
	while(getchar()!='\n');
	getchar();
}

Num *push(Num *top){
	int valor;
	printf("Digite o valor a ser colocado na pilha:\n");
	scanf(" %d", &valor);

	Num *novo_num = malloc(sizeof(Num));
	novo_num->num=valor;
	novo_num->next=top;
	return novo_num;
}

void listar(Num *top){
	while(top){
		printf("[%02d] ", top->num);
		top = top->next;
	}
}

Num *pop(Num *top){
	if(!top){
		espera_enter("Pilha vazia");
		return top;
	}
	Num *novo_topo = top->next;
	free(top);
	return novo_topo; 
}

int procura_num(Num *top, int valor){
	int cont=0;
	while(top){
		if(top->num==valor)
			return cont;
			
		cont++;
		top = top->next;
	}
	return -1;
}

void search(Num *top){
	printf("Digite o número que deseja encontrar:\n");
	int valor;
	scanf(" %d", &valor);
	int posicao = procura_num(top,valor);
	
	if(posicao!=-1)
		printf("Número encontrado na posição %d\n",posicao);
	else
		printf("Número não encontrado\n");
	espera_enter("");
}

Num *excluir_num(Num *top){
	int num;
	printf("Digite o número que deseja excluir\n");
	scanf(" %d", &num);
	
	int posicao = procura_num(top,num);
	Num *top_temp;
	if(posicao==0){
		top_temp = top->next;
		free(top);
		return top_temp;
	}
	
	if(posicao!=-1){
		int cont = 0;
		Num *guarda_topo = top;
		while(top){
			Num *temp;
			if(cont==posicao-1)
				temp = top;
			if(cont==posicao){
				temp->next = top->next;
				free(top);
				return guarda_topo;
			}
			top=top->next;
			cont++;
		}
	}
	
	espera_enter("Número não encontrado");
	return top;
	
}

int interface(){
	printf("1) Push\n");
	printf("2) Pop\n");
	printf("3) Listar\n");
	printf("4) Procurar número\n");
	printf("5) Excluir número\n");
	printf("6) Sair\n");
	
	int escolha;
	scanf(" %d", &escolha);
	return escolha;
}

int main(){
	Num *top = NULL;
	do{
		system("clear");
		switch(interface()){
			case 1:	top = push(top);
					break;
			case 2:	top = pop(top);
					break;
			case 3:	listar(top);
					espera_enter("");
					break;
			case 4:	search(top);
					break;
			case 5:	top = excluir_num(top);
					break;
			case 6:	return 0;
		}
		
	}while(1);
}

