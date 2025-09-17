#ifndef __GAME_H__
#define __GAME_H__
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "pipe.h"
#include "base.h"
#include "bird.h"

typedef struct Game
{
    SDL_Renderer *renderer;
    SDL_Texture** fb_assets;
    PipeConfig* pipes;
    Base* base;
    Bird* bird;
    int8_t cooldown;
} Game;

Game *Game_Create(SDL_Renderer *,SDL_Texture**);
void Game_Destroy(Game *);
void Game_Update(Game *);

#endif
