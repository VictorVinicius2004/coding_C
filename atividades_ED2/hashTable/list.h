#ifndef LIST_H
#define LIST_H

#include "object.h"
#include <stdlib.h>

#define NOT_IN_LIST -1

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
  int (*inList)();
}_List;

typedef _List* List;

void listar(List lst, TypeObject type){
	Object head = lst->head;
	int indice=0;
	while(head){
		if(head->item){
			if(type!=head->type && type!=QUALQUER){
				indice++;
				head=head->right;
				continue;
			}
			printf("Índice: [%d]\n",indice++);
			head->print(head);
		}
		head=head->right;
	}
}

void push(List lst,Object novo){
	if(!novo)
		novo=new(Object);
	novo->right=lst->head;
	if(novo->right)
		novo->right->left=novo;
	lst->head=novo;
	if(!lst->tail)
		lst->tail=lst->head;
	lst->size+=1;
}

void enqueue(List lst,Object novo){
	if(!novo)
		novo=new(Object);
	novo->left=lst->tail;
	if(novo->left)
		novo->left->right=novo;
	lst->tail=novo;
	if(!lst->head)
		lst->head=lst->tail;
	lst->size+=1;
}

Object pop(List lst){
	if(!lst->head) return NULL;
	
	Object retornado =lst->head;
	
	lst->size-=1;
	lst->head=lst->head->right;
	if(lst->head) lst->head->left = NULL;
	else lst->tail = NULL;
	
	retornado->right=NULL;
	retornado->left=NULL;
	return retornado;
}

Object get(List lst, int indice){
	if(indice<0) return NULL;
  Object obj = lst->head;
	int i=0;
	while(obj){
		if(i==indice){
			lst->size-=1;
			if(!lst->size){
				lst->head=NULL;
				lst->tail=NULL;
		}
		else if(i==0) lst->head = obj->right;
		else if(i==lst->size) lst->tail = obj->left; 
			
		if(obj->right) obj->right->left = obj->left;
		if(obj->left) obj->left->right = obj->right;
			
		obj->right=NULL;
		obj->left=NULL;
    return obj;
		}
		i++;
		obj=obj->right;
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

int inList(List lst, int key){
  Object head = lst->head;
  int indice=0;
  while(head){
    if(head->chave==key)
      return indice;
    indice++;
    head = head->right;
  }
  return NOT_IN_LIST;
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
  lst->inList=inList;
	return lst;
}

#endif
