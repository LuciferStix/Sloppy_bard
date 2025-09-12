#include<SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "../include/pipe.h"
#include <time.h>
PipeConfig* PipeSpawn(int pipecount){
  srand(time(NULL));

  /* PipeConfig* pipes = (PipeConfig*) malloc(sizeof(PipeConfig)); */
  PipeConfig* pipes = (PipeConfig*) malloc(sizeof(PipeConfig));
  pipes[0] = (PipeConfig){.xpos = 0 , .top_ypos = 0 };
  pipes->bottom_ypos = pipes->top_ypos + PIPE_H + PIPE_OFFSET;
  return pipes;
} 

void PipeDestroy(PipeConfig* pipes){
  free(pipes);
}

void PipeDraw(PipeConfig *pipes,SDL_Renderer* renderer,SDL_Texture* texture){

  static SDL_Rect toppipe ,bottompipe;
  toppipe  = (SDL_Rect){ .x = pipes->xpos , .y = pipes->top_ypos,.w=PIPE_W,.h=PIPE_H};
  bottompipe = (SDL_Rect){ .x = pipes->xpos , .y = pipes->bottom_ypos,.w=PIPE_W,.h=PIPE_H};


  SDL_RenderCopyEx(renderer, texture,NULL,&toppipe, 0,NULL,SDL_FLIP_VERTICAL); 
  SDL_RenderCopy(renderer,texture ,NULL, &bottompipe);
  
}
#define SCROLLING_VELOCITY 4 
void PipeMove(PipeConfig* pipes ){
  pipes->xpos += SCROLLING_VELOCITY;

}

