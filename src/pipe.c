#include<SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "../include/pipe.h"
#include "../include/constants.h"
#include <time.h>


PipeConfig* PipeSpawn(){
  
  srand(time(NULL));

  PipeConfig* pipes = (PipeConfig*) malloc(PIPEPAIR_COUNT*sizeof(PipeConfig));
  for(int i=0 ; i<PIPEPAIR_COUNT;i++){

    pipes[i] = (PipeConfig){.xpos = i*200 , .top_ypos =-100 + (rand()%110)} ;
    printf("pipe y pos : %d\n",pipes[i].top_ypos);

    pipes[i].bottom_ypos = (pipes[i].top_ypos + PIPE_H + PIPE_OFFSET);
  }
  return pipes;
} 

void PipeDestroy(PipeConfig* pipes){
  free(pipes);
}

void PipeDraw(PipeConfig *pipes,SDL_Renderer* renderer,SDL_Texture* texture){

  static SDL_Rect toppipe ,bottompipe;
  for(int i=0;i<PIPEPAIR_COUNT ; i++){

    toppipe  = (SDL_Rect){ .x = pipes[i].xpos , .y = pipes[i].top_ypos,.w=PIPE_W,.h=PIPE_H};
    bottompipe = (SDL_Rect){ .x = pipes[i].xpos , .y = pipes[i].bottom_ypos,.w=PIPE_W,.h=PIPE_H};

    SDL_RenderCopyEx(renderer, texture,NULL,&toppipe, 0 ,NULL,SDL_FLIP_VERTICAL); 
    SDL_RenderCopy(renderer,texture ,NULL, &bottompipe);
  }  
}

void PipeRespawn(PipeConfig* pipes , uint16_t pos){
  *pipes = (PipeConfig){.xpos = pos + 200 , .top_ypos = -100 + (rand()%104) };
  pipes->bottom_ypos = (pipes->top_ypos + PIPE_H + PIPE_OFFSET); 
  printf("respwaned\n");
}

#define SCROLLING_VELOCITY 3 
void PipeMove(PipeConfig* pipes ){
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

