#ifndef __PIPE__
#define __PIPE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
// #include "game.h"

#define PIPE_W         52
#define PIPE_H         320
#define PIPE_OFFSET    60
#define PIPEPAIR_COUNT 3

typedef struct {
  int16_t xpos;
  int16_t top_ypos;
  int16_t bottom_ypos;

} PipeConfig;


PipeConfig* PipeSpawn(int ); 
void PipeDestroy(PipeConfig*);
void PipeDraw(PipeConfig*,SDL_Renderer* , SDL_Texture*);
void PipeMove(PipeConfig*);
#endif
