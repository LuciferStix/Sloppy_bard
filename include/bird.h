#ifndef __BIRD__
#define __BIRD__

#include<SDL2/SDL.h>

typedef struct {
  uint16_t xpos;
  uint16_t ypos;
  int8_t flaptime;
  uint8_t curflap; //mid , down , up
}Bird;



Bird* BirdSpawn();
void BirdDestroy(Bird*);
void BirdDraw(Bird*,SDL_Renderer*,SDL_Texture*);
void BirdMove(Bird*);


#endif
