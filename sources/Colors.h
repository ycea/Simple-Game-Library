#ifndef COLOURS_H_INCLUDED
#define COLOURS_H_INCLUDED
#include <SDL2/SDL.h>
struct SDL_ColorA
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    // value of transparency
    uint8_t alpha;
};
const SDL_Color WHITE = {255, 255, 255};
const SDL_Color BLACK = {0, 0, 0};
const SDL_Color RED = {255, 0, 0};
const SDL_Color GREEN = {0, 255, 0};
const SDL_Color BLUE = {0, 0, 255};

const SDL_ColorA WHITE_A0 = {255, 255, 255, 0};
const SDL_ColorA BLACK_A0 = {0, 0, 0, 0};
const SDL_ColorA RED_A0 = {255, 0, 0, 0};
const SDL_ColorA GREEN_A0 = {0, 255, 0, 0};
const SDL_ColorA BLUE_A0 = {0, 0, 255, 0};
#endif // COLOURS_H_INCLUDED
