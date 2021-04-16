#ifndef INPUT_HANDLER_H_INCLUDED
#define INPUT_HANDLER_H_INCLUDED
#include <SDL2/SDL.h>
class InputHandler
{
private:
    SDL_Event *prepareEvent;
public:
    // event_from_outside is pointer on SDL_Event object from outside InputHandler class.
    InputHandler(SDL_Event *raw_event);
    bool keyDown(char key[1]);
    bool mouseButtonDown(uint8_t button);
    char getPressedKey();
    bool gameEnded();

};

#endif // EVENTS_H_INCLUDED
