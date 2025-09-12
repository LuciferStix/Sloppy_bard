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
  Game *game = Game_Create(renderer,fb_assets);

  SDL_Event e;
  while (!quit){
   // [event loop]
    while (SDL_PollEvent(&e)){
      if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
        goto cleanup;
    }
    Game_Update(game);
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
