#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>



#include "include/macro.h"
#include "include/utils.h"
#include "include/game.h"
#include "include/texloaders.h"
#include "include/constants.h"
int main(int, char **){
  // game variable
  int ret = 0;
  // int win_w = 400 , win_h = 708;
  int quit = 0;

  // SDL struct inits
  SDL_Window *win        = NULL;
  SDL_Renderer *renderer = NULL;
  TTF_Font *font         = NULL;

  ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  if (ret < 0)
  {
    LogError("Failed to initailize SDL :%s", SDL_GetError());
    return -1;
  }
  ret = TTF_Init();
  if (ret < 0)
  {
    LogError("Failed to initialize TTF :%s", SDL_GetError());
    return -1;
  }
  ret = IMG_Init(IMG_INIT_PNG);
  if (ret < 0)
  {
    LogError("Failed to Initialize IMG :%s", SDL_GetError());
    return -1;
  }

  font = TTF_OpenFont("assets/ttf/Tiny5-Regular.ttf", 20);
  if (!font)
  {
    LogError("Failed to open TTF :%s", SDL_GetError());
    return -1;
  }

  win = SDL_CreateWindow(
    "Flappy Bird",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WINDOW_W,
    WINDOW_H,
    SDL_WINDOW_RESIZABLE);

  if (!win)
  {
    LogError("Failed to create Window :%s", SDL_GetError());
    goto cleanup;
  }

  renderer = SDL_CreateRenderer(
    win,
    -1,
    SDL_RENDERER_ACCELERATED);

  if (!renderer)
  {
    LogError("Failed to create Renderer :%s", SDL_GetError());
    goto cleanup;
  }

  // loading textures
  SDL_Texture** fb_assets = FB_LoadAllTextures(renderer);

  // [game state]
  Game *game = Game_Create(renderer);

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
