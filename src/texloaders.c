#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/utils.h"
#include "../include/game.h"
#include"../include/macro.h"
#include "../include/texloaders.h"

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
