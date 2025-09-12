#include <SDL2/SDL.h>
#include <stdint.h>
#include "../include/pipe.h"
#include "../include/game.h"
#include "../include/utils.h"

#define PIPEPAIR_COUNT  1
static Pipes pipepairs[PIPEPAIR_COUNT];

void SpawnPipe(){
  Pipes p = { .xpos = WINDOW_W , .top_ypos = 0 };
  p.bottom_ypos = p.top_ypos + PIPE_H + PIPE_OFFSET;

 }


void DrawPipe(Pipes *pipes,Game* game){
  /* static SDL_Rect top_pipe ={ .y = pipes->top_ypos , .w = PIPE_W, .h = PIPE_H}; */
  /* top_pipe.x = WINDOW_W; */


}

void MovePipe(Pipes *pipes){
  
}
