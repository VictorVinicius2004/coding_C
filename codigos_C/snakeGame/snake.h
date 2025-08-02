#ifndef SNAKE_H
#define SNAKE_H

#include "common.h"

void growTail(Snake* snake){
  Part* newPart = malloc(sizeof(Part));
  Part* tail = snake->tail;

  newPart->line = tail->prevLine;
  newPart->colum = tail->prevColum;
  newPart->direction = tail->direction;
  newPart->part = TAIL;
  newPart->next = NULL;
  newPart->prev = tail;
  tail->next = newPart;
  snake->size+=1;
  snake->tail = newPart;
}

void moveSnake(Snake* snake, Directions direction){
  Part* part = snake->head;
  if(direction!=NO_DIRECTION)
    part->direction = direction;

  part->prevLine = part->line;
  part->prevColum = part->colum;
  switch(part->direction){
    case UP: part->line-=1; break;
    case DOWN: part->line+=1; break;
    case LEFT: part->colum-=1; break;
    case RIGHT: part->colum+=1; break;
    case NO_DIRECTION: break;
  }
  part = part->next;

  while(part){
    part->prevLine = part->line;
    part->prevColum = part->colum;

    part->line = part->prev->prevLine;
    part->colum = part->prev->prevColum;

    part = part->next;
  }
}

Snake* initSnake(){
  Part* head = malloc(sizeof(Part));
  Part* tail = malloc(sizeof(Part));
  head->prev = NULL;
  head->next = tail;
  head->part = HEAD;
  head->direction = UP;
  head->line = LINES/2;
  head->colum = COLUMS/2;

  tail->next = NULL;
  tail->prev = head;
  tail->direction = NO_DIRECTION;
  tail->part = TAIL;
  tail->line = head->line+1;
  tail->colum = head->colum;
  Snake* snake = malloc(sizeof(Snake));
  snake->head = head;
  snake->tail = tail;
  snake->size = 2;
  return snake;
}

#endif
