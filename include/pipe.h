#ifndef __PIPE__
#define __PIPE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef struct {
  int16_t xpos;
  int16_t top_ypos;
  int16_t bottom_ypos;

} PipeConfig;


PipeConfig* PipeSpawn(); 
void PipeDestroy(PipeConfig*);
void PipeDraw(PipeConfig*,SDL_Renderer* , SDL_Texture*);
void PipeMoveAndRespawn(PipeConfig*);
#endif
