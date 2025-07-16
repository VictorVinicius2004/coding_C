#ifndef PESSOA_H
#define PESSOA_H

typedef struct{
	char nome[100];
	int idade;
	float peso;
	float altura;
}Pessoa;

Pessoa* preenche_pessoa(char* nome, int idade, float peso, float altura){
	Pessoa* pessoa = malloc(sizeof(Pessoa));
	strcpy(pessoa->nome,nome);
	pessoa->idade=idade;
	pessoa->peso=peso;
	pessoa->altura=altura;
	return pessoa;
}

void new_Pessoa(List lst,char* nome,int idade, float peso, float altura){
	enqueue(lst);
	lst->tail->item =  preenche_pessoa(nome,idade,peso,altura);
}

void listar_Pessoa(List lst){
	Object temp = lst->head;
	while(temp){
		Pessoa* pessoa = temp->item;
		
		printf("Item: [%02d]\n",temp->id);
		printf("Nome: %s\n",pessoa->nome);
		printf("Idade: %d\n",pessoa->idade);
		printf("Peso: %.2f\n",pessoa->peso);
		printf("Altura: %.2f\n\n",pessoa->altura);
		temp=temp->prox;
	}
}

#endif
