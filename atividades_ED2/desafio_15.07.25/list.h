#ifndef LIST_H
#define LIST_H

#include "object.h"

#define listar(type,...) listar_##type(__VA_ARGS__);

typedef struct _List{
	Object head;
	Object tail;
	int qntd;
	int id;
}_List;

typedef _List* List;

List new_List(){
	List novo = malloc(sizeof(_List));
	novo->head=NULL;
	novo->tail=NULL;
	novo->qntd=0;
	novo->id=0;
	return novo;
}

void enqueue(List lst){
	Object novo = new(Object);
	if(lst->tail){
		novo->ant=lst->tail;
		lst->tail->prox=novo;
	}
	
	lst->tail=novo;
	if(!lst->head)
		lst->head=lst->tail;
	
	novo->id=lst->id;
	lst->id+=1;
	lst->qntd+=1;
}

#endif
