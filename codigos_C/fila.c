#include <stdio.h>
#include <stdlib.h>

typedef struct Num{
	int num;
	struct Num* next;
}Num;

void espera_enter(char* msg){
	printf("%s\nPressione ENTER para continuar\n",msg);
	setbuf(stdin,NULL);
	getchar();
}

int interface(){
	printf("1) Enqueue\n");
	printf("2) Dequeue\n");
	printf("3) List\n");
	printf("4) Sair\n");
	int escolha;
	scanf(" %d", &escolha);
	return escolha;
}

Num* enqueue(Num* tail){
	Num* new = malloc(sizeof(Num));
	printf("Digite um número: ");
	scanf(" %d", &new->num);
	if(tail)
		tail->next=new;
	new->next=NULL;
	return new;
}

Num* dequeue(Num* head){
	if(!head){
		espera_enter("Fila vazia");
		return head;
	}
	head = head->next;
	return head;
}

void list(Num* head){
	while(head){
		printf("[%02d] ", head->num);
		head = head->next;
	}
	espera_enter("");
}

int main(){
	Num* head = NULL;
	Num* tail = NULL;
	
	do{
		system("clear");
		
		switch(interface()){
			case 1:	tail = enqueue(tail);
					if(!head)
						head = tail;
					break;
			case 2:	head = dequeue(head);
					break;
			case 3:	list(head);
					break;
			case 4:	return 0;
		}
	}while(1);
	return 0;
}

