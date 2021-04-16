#include "InputHandler.h"



InputHandler::InputHandler(SDL_Event *raw_event)
{
    prepareEvent = raw_event;
}



bool InputHandler::keyDown(char key[1])
{
    return ((prepareEvent->type == SDL_KEYDOWN) && (prepareEvent->key.keysym.sym == key[0]));
}


bool InputHandler::mouseButtonDown(uint8_t button)
{
    return ((prepareEvent->type == SDL_MOUSEBUTTONDOWN) && (prepareEvent->button.button == button));
}


char InputHandler::getPressedKey()
{
    return prepareEvent->key.keysym.sym;
}



bool InputHandler::gameEnded()
{
    return (prepareEvent->type == SDL_QUIT);
}



