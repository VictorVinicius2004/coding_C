#ifndef LIST_H
#define LIST_H

#include "object.h"

typedef struct _List{
	int size;
	Object head;
	Object tail;
	void (*push)();
	void (*enqueue)();
	void (*listar)();
	Object (*pop)();
	Object (*dequeue)();
	Object (*get)();
	void (*clear)();
}_List;

typedef _List* List;

void listar(List lst){
	Object head = lst->head;
	int indice=0;
	while(head && head->item){
		printf("Índice: [%d]\n",indice++);
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

Object pop(List lst){
	if(!lst->head) return NULL;
	Object retornado =lst->head;
	
	lst->size-=1;
	lst->head=lst->head->next;
	if(lst->head) lst->head->prev = NULL;
	else lst->tail = NULL;
	
	retornado->next=NULL;
	retornado->prev=NULL;
	return retornado;
}

Object dequeue(List lst){
	if(!lst->tail) return NULL;
	Object retornado = lst->tail;
	
	lst->size-=1;
	lst->tail=lst->tail->prev;
	if(lst->tail) lst->tail->next = NULL;
	else lst->head = NULL;

	retornado->next=NULL;
	retornado->prev=NULL;
	return retornado;
}

Object get(List lst, int indice){
	Object obj = lst->head;
	int i=0;
	while(obj){
		if(i==indice){
			lst->size-=1;
			if(!lst->size){
				lst->head=NULL;
				lst->tail=NULL;
			}
			else if(i==0) lst->head = obj->next;
			else if(i==lst->size-1) lst->tail = obj->prev;
			
			if(obj->next) obj->next->prev = obj->prev;
			if(obj->prev) obj->prev->next = obj->next;
			
			obj->next=NULL;
			obj->prev=NULL;
			return obj;
		}
		i++;
		obj=obj->next;
	}
	return NULL;
}

void clear(List lst){
	while(lst->head){
		destroy(pop(lst));
	}
}

List new_List(){
	List lst = pointer(_List);
	lst->head=NULL;
	lst->tail=NULL;
	lst->size=0;
	lst->push=push;
	lst->enqueue=enqueue;
	lst->listar=listar;
	lst->pop=pop;
	lst->dequeue=dequeue;
	lst->get=get;
	lst->clear=clear;
	return lst;
}

#endif
