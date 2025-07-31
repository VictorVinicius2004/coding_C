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
	Object (*get)();
	void (*clear)();
	void (*del)();
}_List;

typedef _List* List;

void printTipo(TypeObject type){
	printf("Tipo: ");
	switch(type){
		case CASA: printf("Casa\n"); break;
		case PESSOA: printf("Pessoa\n"); break;
		case QUALQUER: break;
	}
}

void listar(List lst, TypeObject type){
	Object head = lst->head;
	int indice=0;
	while(head){
		if(head->item){
			if(type!=head->type && type!=QUALQUER){
				indice++;
				head=head->next;
				continue;
			}
			printf("Índice: [%d]\n",indice++);
			printTipo(head->type);
			head->print(head);
		}
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
			else if(i==lst->size) lst->tail = obj->prev; 
			
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

void del(List lst,int indice){
	destroy(lst->get(lst,indice));
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
	lst->get=get;
	lst->clear=clear;
	lst->del=del;
	return lst;
}

#endif
