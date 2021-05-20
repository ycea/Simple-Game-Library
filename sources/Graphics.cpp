#include "Graphics.h"
#include <iostream>

 Graphics::Graphics(char title[], uint16_t window_width, uint16_t window_height)
{
    Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width,
                                          window_height, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    // position of x and y is 0

    if(!(IMG_Init(IMG_INIT_JPG) && IMG_INIT_PNG))
    {
        exit(2);
    }
    if(TTF_Init() != 0)
    {
        exit(13);
    }
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

void Graphics::drawRect(SDL_Rect *Rect, SDL_ColorA color)
{
    SDL_SetRenderDrawColor(Renderer, color.red, color.green, color.blue, color.alpha);
    SDL_RenderFillRect(Renderer, Rect);
    SDL_RenderDrawRect(Renderer, Rect);

}

void Graphics::renderSprite(std::string file, SDL_Rect *size_and_pos)
{
   if(table_of_textures.find(file) != table_of_textures.end())
   {
        SDL_RenderCopy(Renderer, table_of_textures.at(file), NULL, size_and_pos);
   }
   else
   {
        SDL_Texture *texture = IMG_LoadTexture(Renderer, file.c_str());
        if(texture == nullptr)
        {
            exit(9);
        }
        SDL_RenderCopy(Renderer, texture, NULL, size_and_pos);
        table_of_textures.insert(std::pair(file, texture));

   }

}

void Graphics::updateWindow(uint8_t FPS)
{
    SDL_RenderPresent(Renderer);
    SDL_Delay(1000/FPS);
}

void Graphics::clearWindow()
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
    SDL_RenderClear(Renderer);
}


void Graphics::renderText(std::string filepath, char text[], uint8_t size_of_font, SDL_Color Color, SDL_Rect *pos_and_size)
{
    SDL_Surface* raw_message;
    SDL_Texture* message;
    if(table_of_ttf_fonts.find(filepath) != table_of_ttf_fonts.end())
    {
        raw_message = TTF_RenderText_Solid(table_of_ttf_fonts.at(filepath), text, Color);
        message = SDL_CreateTextureFromSurface(Renderer, raw_message);
        SDL_RenderCopy(Renderer, message, NULL, pos_and_size);
        SDL_FreeSurface(raw_message);
        SDL_DestroyTexture(message);
    }
    else
    {
        TTF_Font *font = TTF_OpenFont(filepath.c_str(), size_of_font);
        if(font == nullptr)
        {
            exit(6);
        }
        else
        {
            raw_message = TTF_RenderText_Solid(font, text, Color);
            message = SDL_CreateTextureFromSurface(Renderer, raw_message);
            SDL_RenderCopy(Renderer, message, NULL, pos_and_size);
            SDL_FreeSurface(raw_message);
            SDL_DestroyTexture(message);
            table_of_ttf_fonts.insert(std::pair(filepath, font));
        }

    }

}


bool Graphics::deleteSprite(std::string file)
{
    if(table_of_textures.find(file) != table_of_textures.end())
    {
        SDL_DestroyTexture(table_of_textures.at(file));
        table_of_textures.erase(table_of_textures.find(file));
        if(table_of_textures.find(file) == table_of_textures.end())
        {
            return true;
        }
    }
    return false;

}

bool Graphics::closeFont(std::string file)
{
    if(table_of_ttf_fonts.find(file) != table_of_ttf_fonts.end())
    {
        TTF_CloseFont(table_of_ttf_fonts.at(file));
        table_of_ttf_fonts.erase(table_of_ttf_fonts.find(file));
        if(table_of_ttf_fonts.find(file) == table_of_ttf_fonts.end())
        {
            return true;
        }
    }
    return false;
}
void Graphics::destroyGraphicAndQuit()
{
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}


