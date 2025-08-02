#ifndef SCREEN_H
#define SCREEN_H

#include <gconio.h>
#include "common.h"

SnakePart snakeInPosition(int line, int colum, Snake* snake){
  Part* tail = snake->tail;
  while(tail){
    if(tail->line==line && tail->colum==colum){
      if(tail->part==HEAD) return HEAD;
      return TAIL;
    }
    tail = tail->prev;
  }
  return NONE;
}

void newApple(Snake* snake, ScreenPosition* apple){
  ScreenPosition freePositions[LINES*COLUMS-snake->size];
  int cont = 0;
  for(int i=0; i<LINES; i++){
    for(int j=0; j<COLUMS; j++){
      if(snakeInPosition(i,j,snake)==NONE){
        freePositions[cont].line = i;
        freePositions[cont].colum = j;
        cont++;
      }
    }
  }

  int applePosition = rand()%cont;
  *apple = freePositions[applePosition];
}

void printScreen(Snake* snake, ScreenPosition apple){
  for(int i=-1; i<=LINES; i++){
    for(int j=-1; j<=COLUMS; j++){
      if(i<0 || j<0 || i==LINES || j==COLUMS)
        printf("#");
      else{
        if(i==apple.line && j==apple.colum)
          printf("%sO",CRED);
        else{
          printf("%s",CGREEN);
          switch(snakeInPosition(i,j,snake)){
            case HEAD: printf("@"); break;
            case TAIL: printf("O"); break;
            case NONE: printf(" ");
          }
        }
        printf("%s",END_COLOR);
      }
    }
    printf("\n");
  }
}

#endif
