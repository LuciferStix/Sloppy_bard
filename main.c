#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "include/game.h"
#include "include/macro.h"
#include "include/utils.h"
#include "include/texloaders.h"
#include "include/window.h"
int main(int, char **){

  SDL_Window* win = NULL;
  SDL_Renderer* renderer = NULL;
  TTF_Font* font = NULL;
 
  int ret = FB_CreateWindow(&win,&renderer,&font);
  if(ret < 0){
    LogError("some error occured \n");
    exit(1);
  }

  
  // game variable
  int quit = 0;
  // loading textures
  SDL_Texture** fb_assets = FB_LoadAllTextures(renderer);

  // [game state]
  Game *game = Game_Create(renderer);

  int pipe_w = 52 , pipe_h =320;
  SDL_Rect piperect = {.x = 0 , .y = WINDOW_H - pipe_h+20 , .w = pipe_w , .h=pipe_h};
  // [event loop]
  SDL_Event e;
  while (!quit){
    // event handling
    while (SDL_PollEvent(&e)){
      if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
        goto cleanup;
    }
    Game_Update(game);
    uint32_t width = 0, height = 0;
    SDL_Rect rect = {.x = 0, .y = 0, .w = WINDOW_W, .h = WINDOW_H};

    SDL_RenderClear(game->renderer);
    SDL_RenderCopy(game->renderer, fb_assets[TextureBackgroundDay], NULL, &rect);
    piperect.y = WINDOW_H - pipe_h +20 ;
    SDL_RenderCopy(game->renderer, fb_assets[TexturePipeGreen], NULL, &piperect);
    piperect.y =  -50;
    SDL_RenderCopyEx(game->renderer,fb_assets[TexturePipeGreen],NULL,&piperect,0,NULL,SDL_FLIP_VERTICAL );
    SDL_RenderPresent(game->renderer);
  }

  Game_Destroy(game);

cleanup:
  if (game)
  {
    Game_Destroy(game);
    game = NULL;
    LogAction("Freed Game State\n");
  }
  if (renderer)
  {
    SDL_DestroyRenderer(renderer);
    LogAction("Destroying Renderer \n");
  }
  if (font)
  {
    TTF_CloseFont(font);
    LogAction("Closing Font \n");
  }
  if (win)
  {
    SDL_DestroyWindow(win);
    LogAction("Destroyed window \n");
  }
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
  return 0;
}
