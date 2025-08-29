#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include "list.h"

#define M_INICIAL 53
#define HT_NAOINSERIDO 0
#define HT_INSERIDO 1

#define HASH(key,m)(key%m)

typedef struct _HashTable{
  List* buckets;
  int m;
  int n;
  void (*insert)();
  void (*printHT)();
  Object (*search)();
  void (*rmv)();
  void (*clear)();
}_HashTable;

typedef _HashTable* HashTable;

void rmv(HashTable ht, int chave){
  int posicao = HASH(chave,ht->m);
  if(ht->buckets[posicao]){
    ht->buckets[posicao]->del(ht->buckets[posicao],
        inList(ht->buckets[posicao],chave));
    ht->n-=1;
  }
}

int _insert(HashTable ht, Object obj){
  int posicao = HASH(obj->chave,ht->m);
  if(!ht->buckets[posicao]) ht->buckets[posicao] = new(List);
  if(ht->buckets[posicao]->inList(ht->buckets[posicao],obj->chave)!=NOT_IN_LIST) return HT_NAOINSERIDO;

  ht->buckets[posicao]->enqueue(ht->buckets[posicao],obj);
  ht->n+=1;
  return HT_INSERIDO;
}

void insert(HashTable ht, Object obj){
  if(_insert(ht,obj)==HT_NAOINSERIDO){
    rmv(ht,obj->chave);
    _insert(ht,obj);
  }
}

void printHT(HashTable ht){
  for(int i=0; i<ht->m; i++){
    printf("[%02d]:\n",i);
    if(ht->buckets[i]) ht->buckets[i]->listar(ht->buckets[i],QUALQUER);
  }
}

Object search(HashTable ht,int chave){
  int posicao = HASH(chave,ht->m);
  if(!ht->buckets[posicao]) return NULL;

  Object head = ht->buckets[posicao]->head;
  while(head){
    if(head->chave==chave) return head;
    head = head->right;
  }
  return NULL;
}

void clearHT(HashTable ht){
  for(int i=0; i<ht->m; i++){
    if(ht->buckets[i]){
      ht->n -= ht->buckets[i]->size;
      ht->buckets[i]->clear(ht->buckets[i]);
    }
    if(ht->n<=0) break;
  }
}

HashTable new_HashTable(){
  HashTable ht = malloc(sizeof(_HashTable));
  ht->m = M_INICIAL;
  ht->n = 0;
  ht->buckets = calloc(ht->m,sizeof(List));
  ht->insert = insert;
  ht->printHT=printHT;
  ht->search=search;
  ht->rmv=rmv;
  ht->clear=clearHT;
  return ht;
}
#endif
