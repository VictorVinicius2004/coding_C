#ifndef OBJECT_H
#define OBJECT_H

#define new(type,...) new_##type(__VA_ARGS__)
#define cadastro(type,...) cadastro_##type(__VA_ARGS__)

typedef struct _Node{
	void* item;
	struct _Node* prox;
	struct _Node *ant;
	int id;
}_Node;

typedef _Node* Object;

Object new_Object(){
	Object novo = malloc(sizeof(_Node));
	novo->ant=NULL;
	novo->item=NULL;
	novo->prox=NULL;
	return novo;
}

#endif
