#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "screen.h"
#include "snake.h"

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
void wait_ms(long milliseconds){
	Sleep(milliseconds)
}
#else
#define CLEAR "clear"
void wait_ms(long milliseconds){
	struct timespec req;
	req.tv_sec = milliseconds/1000;
	req.tv_nsec = (milliseconds%1000)*1000000L;
	nanosleep(&req,NULL);
}
#endif

void gameOver(Snake* snake){
  printf("==========GAME OVER==========\n");
  printf("SCORE: %d\n", snake->size-2);
}

int main(){
  srand(time(NULL));
  Snake* snake = initSnake();
  char movement;
  ScreenPosition apple;

  newApple(snake,&apple);
  while(1){
    system(CLEAR);
    printScreen(snake,apple);
    if(kbhit(&movement)){
      switch(movement){
        case 'w':
        case 'W':
          if(snake->head->direction!=DOWN) moveSnake(snake,UP);
          else moveSnake(snake,NO_DIRECTION);
          break;
        case 'A':
        case 'a':
          if(snake->head->direction!=RIGHT)moveSnake(snake,LEFT);
          else moveSnake(snake,NO_DIRECTION);
          break;
        case 's':
        case 'S':
          if(snake->head->direction!=UP)moveSnake(snake,DOWN);
          else moveSnake(snake,NO_DIRECTION);
          break;
        case 'd':
        case 'D':
          if(snake->head->direction!=LEFT)moveSnake(snake,RIGHT);
          else moveSnake(snake,NO_DIRECTION);
          break;
        case 'q':
        case 'Q':
          return 0;
      }
    }
    else
      moveSnake(snake,NO_DIRECTION);
    if(snake->head->line<0 || snake->head->line==LINES ||
        snake->head->colum<0 || snake->head->colum==COLUMS ||
        snakeInPosition(snake->head->line, snake->head->colum, snake)==TAIL){
      gameOver(snake);
      return 0;
    }
    if(snake->size==COLUMS*LINES){
      printf("I don't know how, but you won. CONGRADULATIONS!!\n");
      return 0;
    }

    if(snake->head->line==apple.line && snake->head->colum==apple.colum){
      growTail(snake);
      newApple(snake,&apple);
    }
    printf("WASD to move         q to quit\n");
    wait_ms(170);
  }
}
