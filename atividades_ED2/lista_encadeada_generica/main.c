#include <stdio.h>
#include <stdlib.h>
#include "interfaces.h"
#include "list.h"
#include "pessoa.h"
#include "casa.h"

void waitEnter(char* msg){
	printf("%s",msg);
	setbuf(stdin,NULL);
	getchar();
}

void waitAndClear(char* msg){
	waitEnter(msg);
	system("clear");
}

int main(){
	List lst = new(List);
	//Pessoa : (nome,idade,altura,peso)
	//Casa : (bairro,rua,numero)

	while(1){
		system("clear");
		switch(interface()){
			case 1: cadastroPessoa(lst); break;
			case 2: cadastroCasa(lst); break;
			case 3: interfaceListar(lst); break;
			case 4: Object k = lst->pop(lst); if(k) k->destroy(k); break;
			case 5: interfaceDelete(lst); break;
			case 6: lst->clear(lst); break;
			case 0: return 0;
		}
		waitAndClear("Pressione ENTER para continuar\n");
	}
}
