#ifndef OBJECT_H
#define OBJECT_H

#define new(type,...) new_##type(__VA_ARGS__)
#define pointer(type) malloc(sizeof(type))
#define init(type) init_##type

typedef struct _Node{
	void* item;
	struct _Node* prev;
	struct _Node* next;
	void(*print)(struct _Node*);
}_Node;

typedef _Node* Object;

typedef struct{
	void* item;
	Object obj;
}ItemObject;

Object new_Object(){
	Object novo = pointer(_Node);
	novo->item=NULL;
	novo->next=NULL;
	novo->prev=NULL;
	return novo;
}

#endif
