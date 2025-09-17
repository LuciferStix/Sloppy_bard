#ifndef __BASE__
#define __BASE__
#include <SDL2/SDL.h>
#include <stdint.h>
typedef struct{
  int16_t xpos;
  int16_t ypos;
} Base;




Base* BaseSpawn();
void BaseDestroy(Base*);
void BaseMoveAndRespawn(Base*);
void BaseDraw(Base*,SDL_Renderer*,SDL_Texture*);

#endif

