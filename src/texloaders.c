#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/utils.h"
#include "../include/game.h"
#include"../include/macro.h"
#include "../include/texloaders.h"
static const char* pngFiles[_TextureCount_] = {
    "0.png",
    "1.png",
    "2.png",
    "3.png",
    "4.png",
    "5.png",
    "6.png",
    "7.png",
    "8.png",
    "9.png",
    "background-day.png",
    "background-night.png",
    "base.png",
    "bluebird-downflap.png",
    "bluebird-midflap.png",
    "bluebird-upflap.png",
    "gameover.png",
    "message.png",
    "pipe-green.png",
    "pipe-red.png",
    "redbird-downflap.png",
    "redbird-midflap.png",
    "redbird-upflap.png",
    "yellowbird-downflap.png",
    "yellowbird-midflap.png",
    "yellowbird-upflap.png",
  };
const char* mysprintf(const char* asset){
    static char buffer[128]={};

    sprintf(buffer,"./assets/images/%s",asset);
    return buffer;
}



// return type problem (double pointer or single pointer)
SDL_Texture** FB_LoadAllTextures(SDL_Renderer* renderer){
    //considering there are not more than 255 assets to be loaded 
    uint8_t i = 0;
    static SDL_Texture* fb_assets[_TextureCount_]={};
    SDL_Surface* surf = NULL;
    SDL_Texture* texture = NULL;
    for(;i<_TextureCount_;i++){
        surf = IMG_Load(mysprintf(pngFiles[i]));
        texture = SDL_CreateTextureFromSurface(renderer,surf);
        SDL_FreeSurface(surf);
        fb_assets[i] = texture;
    }
    return fb_assets;
}



