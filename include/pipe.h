#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <stdint.h>
#include "../include/game.h"

#define PIPE_W 52
#define PIPE_H 320
#define PIPE_OFFSET 60


typedef struct {
  uint16_t xpos;
  uint16_t top_ypos;
  uint16_t bottom_ypos;
  
  // TODO: offset to be variable
  //uint16_t offset
} Pipes;


void SpawnPipe(); 
void DrawPipe(Pipes*,Game*);
void MovePipe(Pipes*);
