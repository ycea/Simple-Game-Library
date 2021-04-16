#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED
#include <SDL2/SDL.h>
class Physics
{
public:
    bool checkCollide(SDL_Rect Rect1, SDL_Rect Rect2);
};

#endif // PHYSICS_H_INCLUDED
