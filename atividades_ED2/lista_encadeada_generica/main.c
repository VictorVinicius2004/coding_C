#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "carro.h"
#include "casa.h"

int main(){
	List lst = new(List);
	
	lst->push(lst,new(Casa,"São Vicente","25",100));
	
	lst->push(lst,new(Carro,"camaro","seila",2000));
	lst->listar(lst->head);
	return 0;
}
