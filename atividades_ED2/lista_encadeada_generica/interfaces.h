#include <stdio.h>
#include <string.h>

void esperaEnter(char* msg){
	printf("%s\nAperte ENTER para continuar\n",msg);
	setbuf(stdin,NULL);
	getchar();
}

void cadastroPessoa(List lst){
	char nome[100];
	int idade;
	float altura, peso;
	printf("Nome(SAIR para cancelar): ");
	scanf(" %s",nome);
	if(!strcmp(nome,"SAIR")) return;
	printf("Idade: ");
	scanf(" %d",&idade);
	printf("Altura: ");
	scanf(" %f",&altura);
	printf("peso: ");
	scanf(" %f",&peso);
	
	int escolha;
	printf("\n1) push \n2)enqueue\n");
	do{
		scanf(" %d",&escolha);
	}while(escolha!=1 && escolha!=2);
	if(escolha==1) lst->push(lst,new(Pessoa,nome,idade,altura,peso));
	else lst->enqueue(lst,new(Pessoa,nome,idade,altura,peso));
}

void cadastroCasa(List lst){
	char bairro[100], rua[100];
	int numero;
	printf("Bairro(SAIR para cancelar): ");
	scanf(" %s",bairro);
	if(!strcmp(bairro,"SAIR")) return;
	printf("Rua: ");
	scanf(" %s",rua);
	printf("Número: ");
	scanf(" %d",&numero);
	
	int escolha;
	printf("\n1) push \n2)enqueue\n");
	do{
		scanf(" %d",&escolha);
	}while(escolha!=1 && escolha!=2);
	if(escolha==1) lst->push(lst,new(Casa,bairro,rua,numero));
	else lst->enqueue(lst,new(Casa,bairro,rua,numero));
}

void interfaceGet(List lst){
	int indice;
	printf("digite o índice do item a ser excluído\n");
	scanf(" %d",&indice);
	lst->head->destroy(lst->get(lst,indice));
}

int interface(){
	printf("1) adicionar pessoa\n");
	printf("2) adicionar casa\n");
	printf("3) listar\n");
	printf("4) pop\n");
	printf("5) dequeue\n");
	printf("6) get\n");
	printf("7) clear\n");
	printf("0) sair\n");
	int escolha;
	scanf(" %d",&escolha);
	return escolha;
}
