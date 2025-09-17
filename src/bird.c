#include<SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include "../include/bird.h"
#include "../include/constants.h"
Bird *BirdSpawn(){
  Bird* bird =(void*) malloc(sizeof(Bird));
  bird->xpos = 40 ;
  bird->ypos = WINDOW_H/2 -50;
  bird->flaptime = 0;
  bird->curflap = 0 ;
  printf("ran\n");
  return bird;
}

void BirdDestroy(Bird* bird){
  free(bird);
}


void BirdDraw(Bird* bird,SDL_Renderer* renderer,SDL_Texture* texture){
  SDL_Rect bird_rect = {.x = bird->xpos , .y = bird->ypos , .w =BIRD_W , .h =BIRD_H };
  
  SDL_RenderCopy(renderer,texture,NULL,&bird_rect);

}
