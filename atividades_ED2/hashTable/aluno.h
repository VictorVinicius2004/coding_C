#ifndef ALUNO_H
#define ALUNO_H

#include <string.h>

typedef struct{
  int id;
  char nome[100];
  char curso[100];
}Aluno;

void print_Aluno(Object object){
  if(!object || !object->item) return;
  Aluno* aluno = object->item;
  printf("Tipo: ALUNO | ");
  printf("ID: %03d | ", aluno->id);
  printf("Nome: %s | ", aluno->nome);
  printf("Curso: %s\n", aluno->curso);
}

Object new_Aluno(const int id,const char* nome,const char* curso){
  Object new_aluno = new(Object);

  Aluno* aluno = pointer(Aluno);
  aluno->id = id;
  strcpy(aluno->curso, curso);
  strcpy(aluno->nome, nome);

  new_aluno->item = aluno;
  new_aluno->print = print_Aluno;
  new_aluno->chave = id;
  new_aluno->type = ALUNO;
  return new_aluno;
}

#endif
