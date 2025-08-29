#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "hash.h"
#include "aluno.h"

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

void wait(){
  setbuf(stdin, NULL);
  getchar();
}

int getID(){
  printf("ID: ");
  int id;
  scanf(" %d",&id);
  return id;
}

void cadastroAluno(HashTable ht){
  int id;
  char nome[100];
  char curso[100];
  printf("Aviso: cada id é único, em caso de id duplicado\n");
  printf("será considerado o mais recente\n");
  printf("ID: ");
  scanf(" %d",&id);
  printf("nome: ");
  scanf(" %s",nome);
  printf("curso: ");
  scanf(" %s",curso);
  ht->insert(ht,new(Aluno,id,nome,curso));
}

void printAluno(HashTable ht){
  int id = getID();

  Object temp = ht->search(ht,id);
  if(temp) temp->print(temp);
}

int interface(){
  printf("1) inserir aluno\n");
  printf("2) procurar aluno\n");
  printf("3) printar tabela hash\n");
  printf("4) remover aluno\n");
  printf("5) limpar tabela\n");
  printf("0) sair\n");
  int escolha;
  printf("Digite: ");
  scanf(" %d",&escolha);
  return escolha;
}

int main(){
  HashTable ht = new(HashTable);
  while(1){
    system(CLEAR);
    switch(interface()){
      case 1: cadastroAluno(ht); break;
      case 2: printAluno(ht); wait(); break;
      case 3: ht->printHT(ht); wait(); break;
      case 4: ht->rmv(ht,getID()); break;
      case 5: ht->clear(ht); break;
      case 0: return 0;
    }
  }
}
