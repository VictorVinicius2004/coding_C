#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int valor;
	struct Lista* next;
	struct Lista* previous;
}Lista;

typedef struct{
	Lista* lista;
	int qntd;
}Cache;

int defineCache(){
	printf("Digite o tamanho do cache\n");
	int cache;
	scanf(" %d", &cache);
	return cache;
}

void printLista(Lista* cache){
	while(cache){
		printf("%d ",cache->valor);
		cache = cache->next;
	}
}

Lista* push(Lista* top, int num){
	Lista* new = malloc(sizeof(Lista));
	new->valor=num;
	new->previous=NULL;
	
	if(!top){
		new->next=NULL;
		return new;
	}
	
	new->next=top;
	top->previous=new;
	return new;
}

int processoExiste(Lista* cache,int alvo){
	while(cache){
		if(cache->valor==alvo)
			return 1;
			
		cache=cache->next;
	}
	return 0;
}

Lista* excluirUltimo(Lista* cache, int tamCache){
	Lista* topo = cache;
	for(int i=1; i<tamCache; i++)
		cache = cache->next;
		
	free(cache->next);
	cache->next=NULL;
	return topo;
}

Lista* excluirItem(Lista* cache, int alvo){
	Lista* topo = cache;
	while(cache->valor!=alvo)
		cache=cache->next;
	
	if(cache->previous==NULL){
		topo=topo->next;
		free(cache->previous);
	}
	else{
		cache->previous->next=cache->next;
		if(cache->next)
			cache->next->previous=cache->previous;
		free(cache);
	}
	
	return topo;
}

Lista* atualizarProcesso(Lista* cache, int* qntdAtual, int valor){
	if(processoExiste(cache,valor)) 
		cache = excluirItem(cache,valor);
	else
		*qntdAtual+=1;
	cache = push(cache,valor);
	
	return cache;
}

Lista* preencheCache(Lista* cache, int tamCache){
	printf("Digite os valores para preencher o cache:\n");
	printf("(valor menor ou igual a zero para encerrar)\n");
	int qntdAtual=0;
	do{
		int valor;
		scanf(" %d", &valor);
		if(valor<=0) break;
		cache = atualizarProcesso(cache,&qntdAtual,valor);
		if(qntdAtual>tamCache)
			cache = excluirUltimo(cache,tamCache);
	}while(1);
	return cache;
}

int main(){
	Cache* cache = malloc(sizeof(Cache));
	cache->qntd = defineCache();
	cache->lista = preencheCache(cache->lista,cache->qntd);
	printLista(cache->lista);
	return 0;
}

