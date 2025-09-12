#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include "../include/game.h"
#include "../include/utils.h"
#include "../include/texloaders.h"
#include "../include/pipe.h"

Game *Game_Create(SDL_Renderer *renderer,SDL_Texture** fb_assets)
{
  Game *game = (Game *)malloc(sizeof(Game));
  game->renderer = renderer;
  game->fb_assets = fb_assets;
  return game;
}

void Game_Destroy(Game *game)
{
    free(game);
}


void Game_Update(Game *game)
{
  game->counter+=2;
  printf("frame:%d\n", game->counter);
  SDL_RenderClear(game->renderer);
  //background
  static SDL_Rect rect = {.x =0, .y = 0, .w = WINDOW_W, .h = WINDOW_H};
  SDL_RenderCopy(game->renderer, game->fb_assets[TextureBackgroundDay], NULL, &rect);
  
  /* SpawnPipe()
   * DrawPipe()
   * MovePipe()
   * */ 
  static SDL_Rect piperecttop = { .x = 0, .y = 0 , .w = PIPE_W , .h = PIPE_H};  
  static SDL_Rect piperectbottom = { .x = 0, .y = PIPE_H + 10 , .w = PIPE_W , .h = PIPE_H};  
  if(piperecttop.x > (WINDOW_W + PIPE_W))
      piperecttop.x = -PIPE_W ;
  else
      piperecttop.x += 2 ;

  piperectbottom.x = piperecttop.x;

  SDL_RenderCopyEx(game->renderer,game->fb_assets[TexturePipeGreen],NULL,&piperecttop,0,NULL,SDL_FLIP_VERTICAL);
  SDL_RenderCopy(game->renderer, game->fb_assets[TexturePipeGreen], NULL,&piperectbottom );
  SDL_RenderPresent(game->renderer);
  SDL_Delay(20);
}



