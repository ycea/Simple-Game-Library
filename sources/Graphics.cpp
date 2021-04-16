#include "Graphics.h"
#include <iostream>

 Graphics::Graphics(char title[], int window_width, int window_height)
{
    Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width,
                                          window_height, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
}


SDL_Window* Graphics::getWindowAddres()
{
    return Window;
}

SDL_Rect Graphics::createRect(uint16_t width, uint16_t height, uint32_t pos_x, uint32_t pos_y)
{
    SDL_Rect Rect;
    Rect= {pos_x, pos_y, width, height};
    return Rect;
}

void Graphics::drawRect(SDL_Rect *Rect, uint8_t RGBA[4])
{
    SDL_SetRenderDrawColor(Renderer, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);
    SDL_RenderDrawRect(Renderer, Rect);
    SDL_RenderFillRect(Renderer, Rect);
}

void Graphics::renderSprite(char file[], SDL_Rect *size_and_pos)
{
   SDL_Surface *loadedSurface = SDL_LoadBMP(file);
   SDL_Texture *new_texture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
   SDL_RenderCopy(Renderer, new_texture, NULL, size_and_pos);
   SDL_FreeSurface(loadedSurface);
   SDL_DestroyTexture(new_texture);
}

void Graphics::updateWindow(uint16_t FPS)
{
    SDL_RenderPresent(Renderer);
    SDL_Delay(1000/FPS); // 1000 miliseconds. Result is miliseconds delay
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
    SDL_RenderClear(Renderer);

}

void Graphics::destroyGraphicAndQuit()
{
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}


