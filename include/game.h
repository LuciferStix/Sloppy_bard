#ifndef __GAME_H__
#define __GAME_H__
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WINDOW_W 400
#define WINDOW_H 600

typedef struct GameState
{
    bool forward;
    bool backward;
    bool jump;
} GameState;

typedef struct Game
{
    SDL_Renderer *renderer;
    uint8_t frame;
    // GameState* gamestate;
} Game;

Game *Game_Create(SDL_Renderer *);
void Game_Destroy(Game *);
void Game_Update(Game *);

#endif
