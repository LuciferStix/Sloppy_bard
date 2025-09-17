#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/base.h"
#include "../include/constants.h"

Base* BaseSpawn(){

  Base* base = (Base*)malloc(BASE_COUNT*sizeof(Base));
  for(int i = 0 ; i < BASE_COUNT ; i++ )
    base[i] = (Base){.xpos = i * BASE_WIDTH , .ypos = WINDOW_H };
  return base;

}
void BaseDestroy(Base* base){
  free(base);

  // INFO: even after freeing a pointer it holds the 
  // deallocated memory . Accessig this pointer can cause 
  // SEG FAULT , hence a good practice is to point it
  // to NULL;
  base = NULL;
}
void BaseDraw(Base* base,SDL_Renderer* renderer,SDL_Texture* texture){

  static SDL_Rect base_rect ;
  for(int i =0 ; i <BASE_COUNT ; i++){
    base_rect = (SDL_Rect){.x = base[i].xpos, .y = base[i].ypos , .w = BASE_WIDTH , .h = BASE_HEIGHT };
    SDL_RenderCopy(renderer,texture, NULL,&base_rect);
  }
}


static void BaseRespawn(Base* base,uint16_t pos){
  *base = (Base){.xpos = pos + BASE_WIDTH , .ypos = WINDOW_H};
}

void BaseMoveAndRespawn(Base * base){

  for(int i = 0 ; i < BASE_COUNT ; i++){
    if(base[i].xpos < -BASE_WIDTH){
      uint8_t lastbase_index = (i + BASE_COUNT-1) % BASE_COUNT;
      uint16_t lastbase_pos = base[lastbase_index].xpos;
      BaseRespawn(&base[i],lastbase_pos-SCROLLING_VELOCITY);
   }
    else
      base[i].xpos -= (SCROLLING_VELOCITY) ;
  }
}


