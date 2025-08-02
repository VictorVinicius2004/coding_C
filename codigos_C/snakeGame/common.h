#ifndef COMMON_H
#define COMMON_H

#define LINES 30
#define COLUMS 40

#define CRED "\033[31m"
#define CGREEN "\033[32m"
#define END_COLOR "\033[0m"

typedef enum{
  NONE,
  HEAD,
  TAIL,
}SnakePart;

typedef enum{
  UP,
  DOWN,
  RIGHT,
  LEFT,
  NO_DIRECTION,
}Directions;

typedef struct Part{
  SnakePart part;
  Directions direction;
  int line;
  int colum;
  int prevLine;
  int prevColum;
  struct Part* next;
  struct Part* prev;
}Part;

typedef struct Snake{
  Part* head;
  Part* tail;
  int size;
}Snake;

typedef struct ScreenPosition{
  int line, colum;
}ScreenPosition;

#endif
