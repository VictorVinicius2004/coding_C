#ifndef OBJECT_H
#define OBJECT_H

#define new(type,...) new_##type(__VA_ARGS__)
#define pointer(type) malloc(sizeof(type))
#define init(type) init_##type

typedef enum{
	CASA,
	PESSOA,
	QUALQUER
}TypeObject;

typedef struct _Node{
	void* item;
	TypeObject type;
	struct _Node* prev;
	struct _Node* next;
	void(*print)();
	void(*destroy)();
}_Node;

typedef _Node* Object;

void destroy(Object obj){
	if(!obj) return;
	if(obj->item) free(obj->item);
	free(obj);
}

Object new_Object(){
	Object novo = pointer(_Node);
	novo->item=NULL;
	novo->next=NULL;
	novo->prev=NULL;
	novo->destroy=destroy;
	novo->print=NULL;
	return novo;
}


#endif
