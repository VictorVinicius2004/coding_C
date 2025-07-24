#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "pessoa.h"
#include "casa.h"
#include "interfaces.h"

int main(){
	List lst = new(List);
	do{
		system("clear");
		switch(interface()){
			case 1: cadastroPessoa(lst);
				break;
			case 2: cadastroCasa(lst);
				break;
			case 3: lst->listar(lst);
				break;
			case 4:	lst->head->destroy(lst->pop(lst));
				break;
			case 5:	lst->head->destroy(lst->dequeue(lst));
				break;
			case 6:
				int indice;
				printf("digite o índice do item a ser excluído\n");
				scanf(" %d",&indice);
				lst->head->destroy(lst->get(lst,indice));
				break;
			case 7: lst->clear(lst);
				break;
			case 0: return 0;
		}
		esperaEnter("");
		system("clear");
	}while(1);
	return 0;
}
