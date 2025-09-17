#include<SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <time.h>

#include "../include/pipe.h"
#include "../include/constants.h"



// INFO: API architecture should be such that each functions 
// should handle atomic responsibilities
//
// INFO: Here PipeMoveAndRespawn function handles 
// mutiple resposibilities like moving and respawning
//
// BUG: for this reason this API uses
// multiple loops for iterating and performing any operations



PipeConfig* PipeSpawn(){
  
  srand(time(NULL));
  PipeConfig* pipes = (PipeConfig*) malloc(PIPEPAIR_COUNT*sizeof(PipeConfig));
  for(int i=0 ; i<PIPEPAIR_COUNT;i++){

    pipes[i] = (PipeConfig){.xpos = (WINDOW_W + i * PIPE_HSEP), .top_ypos =-100 + (rand()%100)} ;

    pipes[i].bottom_ypos = (pipes[i].top_ypos + PIPE_H + PIPE_VSEP );
  }
  return pipes;
} 

void PipeDestroy(PipeConfig* pipes){
  free(pipes);
  pipes = NULL;
}

void PipeDraw(PipeConfig *pipes,SDL_Renderer* renderer,SDL_Texture* texture){

  static SDL_Rect toppipe ,bottompipe;
  for(int i=0;i<PIPEPAIR_COUNT ; i++){

    toppipe  = (SDL_Rect){ .x = pipes[i].xpos , .y = pipes[i].top_ypos,.w = PIPE_W,.h = PIPE_H};
    bottompipe = (SDL_Rect){ .x = pipes[i].xpos , .y = pipes[i].bottom_ypos,.w = PIPE_W,.h = PIPE_H};

    SDL_RenderCopyEx(renderer, texture,NULL,&toppipe, 0 ,NULL,SDL_FLIP_VERTICAL); 
    SDL_RenderCopy(renderer,texture ,NULL, &bottompipe);
  }  
}

static void PipeRespawn(PipeConfig* pipes , uint16_t pos){
  *pipes = (PipeConfig){.xpos = pos + PIPE_HSEP , .top_ypos = -100 + (rand()%104) };
  pipes->bottom_ypos = (pipes->top_ypos + PIPE_H + PIPE_VSEP ); 
}

void PipeMoveAndRespawn(PipeConfig* pipes ){

  for(int i = 0;i<PIPEPAIR_COUNT ; i++){
    if(pipes[i].xpos < -PIPE_W){
      uint8_t backpipe = (i + PIPEPAIR_COUNT - 1)% PIPEPAIR_COUNT ;
      uint16_t backpipe_pos = pipes[backpipe].xpos;
      PipeRespawn(&pipes[i] ,backpipe_pos );

    }
    else
      pipes[i].xpos -= SCROLLING_VELOCITY;
  }
}

