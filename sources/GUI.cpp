#include "GUI.h"
#include <iostream>
RectButton::RectButton(int width, int height, int x, int y, void (*callback_function)())
{
    button = {x, y, width, height};

    callback = callback_function;

}

SDL_Rect* RectButton::getRect()
{
    return &button;
}
void RectButton::onClick()
{
    SDL_GetMouseState(&cursor_pos_x, &cursor_pos_y);
    if(input_handler.mouseButtonDown(SDL_BUTTON_LEFT))
    {
        if(((cursor_pos_x >= button.x) && (cursor_pos_x <= button.x + button.w)) && ((cursor_pos_y >= button.y) && (cursor_pos_y <= button.y + button.h)))
        {
            (*callback)();
        }
    }
}
