#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "bst.h"
#include "aluno.h"

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

void waitEnter(){
  setbuf(stdin,NULL);
  getchar();
}

void printAndWait(const char* msg){
  printf("%s",msg);
  waitEnter();
}

int getID(){
  printf("ID: ");
  int id;
  scanf(" %d",&id);
  return id;
}

void cadastro_aluno(BSTree abb){
  int id;
  char nome[100];
  char curso[100];
  printf("ID(-1 para cancelar): ");
  scanf(" %d", &id);
  if(id==-1) return;
  printf("Nome: ");
  scanf(" %s",nome);
  printf("Curso: ");
  scanf(" %s",curso);
  abb->insert(abb,new(Aluno,id,nome,curso));
}

void printAluno(BSTree abb,int id){
  if(abb->raiz) abb->raiz->print(abb->search(abb,id,QUALQUER));
  waitEnter();
}

int interface(){
  printf("1) inserir aluno\n");
  printf("2) print aluno\n");
  printf("3) remover aluno\n");
  printf("4) preorder\n");
  printf("5) inorder\n");
  printf("6) postorder\n");
  printf("7) print árvore\n");
  printf("8) clear\n");
  printf("0) sair\n");
  int escolha;
  printf("Escolha: ");
  scanf(" %d", &escolha);
  return escolha;
}

int main(){
  BSTree abb = new(BSTree);
  while(1){
    system(CLEAR);
    switch(interface()){
      case 1: cadastro_aluno(abb); break;
      case 2: printAluno(abb,getID()); break;
      case 3: abb->rmv(abb,getID(),QUALQUER); break;
      case 4: abb->preorder(abb); waitEnter(); break;
      case 5: abb->inorder(abb); waitEnter(); break;
      case 6: abb->postorder(abb); waitEnter(); break;
      case 7: abb->printTree(abb); waitEnter(); break;
      case 8: abb->clear(abb); break;
      case 0: return 0;
    }
  }
}
