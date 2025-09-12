#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include "../include/game.h"
#include "../include/utils.h"
#include "../include/pipe.h"
#include "../include/constants.h"

Game *Game_Create(SDL_Renderer *renderer,SDL_Texture** fb_assets)
{
  Game *game = (Game *)malloc(sizeof(Game));
  game->renderer = renderer;
  game->fb_assets = fb_assets;
  game->pipes = PipeSpawn(1);
  return game;
}

void Game_Destroy(Game *game)
{
    free(game);
}

void Game_Update(Game *game)
{
  /* game->counter+=2; */
  /* printf("frame:%d\n", game->counter); */
  SDL_RenderClear(game->renderer);
  //background
  static SDL_Rect rect = {.x =0, .y = 0, .w = WINDOW_W, .h = WINDOW_H};
  SDL_RenderCopy(game->renderer, game->fb_assets[TextureBackgroundDay], NULL, &rect);
  
  /* SpawnPipe()
   * DrawPipe()
   * MovePipe()
   * */
  PipeDraw(game->pipes,game->renderer,game->fb_assets[TexturePipeGreen]);
  PipeMove(game->pipes);
  SDL_RenderPresent(game->renderer);
  SDL_Delay(20);
}



