#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

#include "../include/game.h"
#include "../include/utils.h"
#include "../include/pipe.h"
#include "../include/constants.h"
#include "../include/bird.h"
Game *Game_Create(SDL_Renderer *renderer,SDL_Texture** fb_assets)
{
  Game *game = (Game *)malloc(sizeof(Game));
  game->renderer = renderer;
  game->fb_assets = fb_assets;
  game->pipes = PipeSpawn();
  game->base = BaseSpawn(); 
  game->bird = BirdSpawn();
  game->cooldown = 15;
  return game;
}

void Game_Destroy(Game *game)
{
    BirdDestroy(game->bird);
    printf("%p \n ",game->base);
    BaseDestroy(game->base);
    printf("%p \n ",game->base);
    PipeDestroy(game->pipes);
    free(game);
    game = NULL;
}

void Game_Update(Game *game)
{
  SDL_RenderClear(game->renderer);
  //background
  static SDL_Rect rect = {.x =0, .y = 0, .w = WINDOW_W, .h = WINDOW_H};
  SDL_RenderCopy(game->renderer, game->fb_assets[TextureBackgroundDay], NULL, &rect);

  //pipe draw
  PipeDraw(game->pipes,game->renderer,game->fb_assets[TexturePipeGreen]);
  PipeMoveAndRespawn(game->pipes);
  
  //base draw
  BaseDraw(game->base, game->renderer , game->fb_assets[TextureBase]) ;
  BaseMoveAndRespawn(game->base);

  //bird
  
  if(game->bird->flaptime < game->cooldown ){
    game->bird->flaptime++;
  }
  else{
    printf("prev index : %d\n",game->bird->curflap + TextureYellowBirdDownFlap);
    game->bird->curflap = ((game->bird)->curflap + 2 ) % 3;
    game->bird->flaptime = 0;
    printf("cur index : %d\n",game->bird->curflap + TextureYellowBirdDownFlap);
  }
  
  BirdDraw(game->bird, game->renderer, game->fb_assets[game->bird->curflap + TextureYellowBirdDownFlap]);

  SDL_RenderPresent(game->renderer);
  SDL_Delay(20);
}



