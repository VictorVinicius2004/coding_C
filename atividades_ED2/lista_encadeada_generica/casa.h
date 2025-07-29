#ifndef CASA_H
#define CASA_H

typedef struct{
	char rua[100], bairro[100];
	int numero;
}Casa;

void print_Casa(Object object){
	Casa* casa = object->item;
	printf("Bairro: %s\n",casa->bairro);
	printf("Rua: %s\n",casa->rua);
	printf("Numero: %d\n\n",casa->numero);
}

Object new_Casa(char* bairro,char* rua,int numero){
	Casa* newCasa = pointer(Casa);
	strcpy(newCasa->bairro,bairro);
	strcpy(newCasa->rua,rua);
	newCasa->numero=numero;
	
	Object novo = new(Object);
	novo->item=newCasa;
	novo->print=print_Casa;
	return  novo;
}

#endif
