#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include <SDL2/SDL.h>

class Graphics
{
private:
    // position x and y are undefined
    SDL_Window *Window;
    SDL_Renderer *Renderer;

public:
    Graphics(char title[], int window_width, int window_height);
    SDL_Window* getWindowAddres();
    SDL_Rect createRect(uint16_t width, uint16_t height, uint32_t pos_x, uint32_t pos_y);
    void drawRect(SDL_Rect *Rect, uint8_t RGBA[4]);
    void renderSprite(char file[], SDL_Rect *size_and_pos);
    void updateWindow(uint16_t FPS);
    void destroyGraphicAndQuit();
};

#endif // GRAPHICS_H_INCLUDED
