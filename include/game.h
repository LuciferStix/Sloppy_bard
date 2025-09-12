#ifndef __GAME_H__
#define __GAME_H__
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#define WINDOW_W 400
#define WINDOW_H 600

typedef struct Game
{
    SDL_Renderer *renderer;
    SDL_Texture** fb_assets;
    uint16_t counter;
} Game;

Game *Game_Create(SDL_Renderer *,SDL_Texture**);
void Game_Destroy(Game *);
void Game_Update(Game *);

#endif
