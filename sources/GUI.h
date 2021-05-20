#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "InputHandler.h"
extern InputHandler input_handler;
class RectButton
{
private:
    SDL_Rect button;
    void (*callback)();
    int cursor_pos_x, cursor_pos_y;
public:
    RectButton(int width, int height, int x, int y, void (*callback)());
    RectButton();
    SDL_Rect* getRect();
    void onClick();
};

#endif // GUI_H_INCLUDED
