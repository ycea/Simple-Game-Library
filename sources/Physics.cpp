#include "Physics.h"

bool Physics::checkCollide(SDL_Rect Rect1, SDL_Rect Rect2)
{

    // checking horizontal collide
    if( ( (Rect1.x+Rect1.w > Rect2.x) && (Rect1.x < Rect2.x) )  && ( (Rect1.y == Rect2.y) ) )
    {
        return true;
    }

    if( (Rect1.y + Rect1.h >= Rect2.y) && (Rect1.y < Rect2.y + Rect2.h))
    {
        return true;
    }
    return false;
}
