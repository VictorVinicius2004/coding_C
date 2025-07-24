#ifndef LIST_H
#define LIST_H

#include "object.h"

typedef struct _List{
	int size;
	Object head;
	Object tail;
	void (*push)(struct _List*,struct _Node*);
	void (*enqueue)(struct _List*,struct _Node*);
	void (*listar)(struct _Node*);
}_List;

typedef _List* List;

void listar(Object head){
	while(head){
		head->print(head);
		head=head->next;
	}
}

void push(List lst,Object novo){
	if(!novo)
		novo=new(Object);
	novo->next=lst->head;
	if(novo->next)
		novo->next->prev=novo;
	lst->head=novo;
	if(!lst->tail)
		lst->tail=lst->head;
	lst->size+=1;
}

void enqueue(List lst,Object novo){
	if(!novo)
		novo=new(Object);
	novo->prev=lst->tail;
	if(novo->prev)
		novo->prev->next=novo;
	lst->tail=novo;
	if(!lst->head)
		lst->head=lst->tail;
	lst->size+=1;
}

List new_List(){
	List lst = pointer(_List);
	lst->head=NULL;
	lst->tail=NULL;
	lst->size=0;
	lst->push=push;
	lst->enqueue=enqueue;
	lst->listar=listar;
	return lst;
}

#endif
