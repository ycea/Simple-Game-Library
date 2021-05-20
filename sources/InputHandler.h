#ifndef INPUT_HANDLER_H_INCLUDED
#define INPUT_HANDLER_H_INCLUDED
#include <SDL2/SDL.h>
#include <iostream>
class InputHandler
{
private:
    SDL_Event *prepareEvent;
public:
    InputHandler(SDL_Event *raw_event);

    bool keyDown(int scan_code);
    bool mouseButtonDown(uint8_t button);
    char getPressedKey();
    bool gameEnded();

};

#endif // EVENTS_H_INCLUDED
