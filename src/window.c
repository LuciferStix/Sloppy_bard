#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>

#include "../include/constants.h"
#include"../include/macro.h"


int FB_CreateWindow(SDL_Window** win,SDL_Renderer** renderer , TTF_Font** font){

  int ret = 0;
  // SDL struct inits
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

  *font = TTF_OpenFont("assets/ttf/Tiny5-Regular.ttf", 20);
  if (!*font)
  {
    LogError("Failed to open TTF :%s", SDL_GetError());
    return -1;
  }

  *win = SDL_CreateWindow(
    "Flappy Bird",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WINDOW_W,
    WINDOW_H + BASE_HEIGHT,
    SDL_WINDOW_RESIZABLE);

  if (!*win)
  {
    LogError("Failed to create Window :%s", SDL_GetError());
    return -1;
  }

  *renderer = SDL_CreateRenderer(
    *win,
    -1,
    SDL_RENDERER_ACCELERATED);

  if (!*renderer)
  {
    LogError("Failed to create Renderer :%s", SDL_GetError());
    return -1;
  }

  return 0;
}

