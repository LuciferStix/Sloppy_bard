#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/game.h"
#include "../include/utils.h"
#include "../include/macro.h"
#include "../include/texloaders.h"

Game *Game_Create(SDL_Renderer *renderer)
{
    Game *game = (Game *)malloc(sizeof(Game));
    game->renderer = renderer;
    return game;
}

void Game_Destroy(Game *game)
{
    free(game);
}


void Game_Update(Game *game)
{
    game->frame++;
     printf("frame:%d\n", game->frame);

    // SDL_Texture* texbg = FL_CreateTextureFromImg(pngFiles[TextureBackgroundDay],game);
    

    //pipes


    
}
