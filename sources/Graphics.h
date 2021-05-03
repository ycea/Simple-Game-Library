#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <unordered_map>
#include "Colors.h"

class Graphics
{
private:
    // position x and y are undefined
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    typedef std::unordered_map<std::string, SDL_Texture*> map_of_textures;
    map_of_textures table_of_textures;
    typedef std::unordered_map<std::string, TTF_Font*> map_of_ttf_fonts;
    map_of_ttf_fonts table_of_ttf_fonts;


public:
    Graphics(char title[], uint16_t window_width, uint16_t window_height);
    SDL_Window* getWindowAddres();
    SDL_Rect createRect(uint16_t width, uint16_t height, uint32_t pos_x, uint32_t pos_y);
    void drawRect(SDL_Rect *Rect, SDL_ColorA color);
    void renderSprite(std::string file, SDL_Rect *size_and_pos);
    void renderText(std::string filepath, char text[], uint8_t size_of_font, SDL_Color Color, SDL_Rect *pos_and_size);
    bool closeFont(std::string file);
    bool deleteSprite(std::string file);
    void updateWindow(uint8_t FPS);
    void clearWindow();
    void destroyGraphicAndQuit();
};

#endif // GRAPHICS_H_INCLUDED
