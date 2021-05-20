#include "Physics.h"
#include <cmath>
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

void Physics::calculateFalling(int speed0, int sec_time, SDL_Rect *falling_object)
{
    falling_object->y = round((speed0 * sec_time ) + (grav_accel * (sec_time * sec_time) / 2));
}
