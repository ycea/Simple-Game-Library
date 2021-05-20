#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED
#include <SDL2/SDL.h>
class Physics
{
private:
    float grav_accel = 9.832;
public:
    bool checkCollide(SDL_Rect Rect1, SDL_Rect Rect2);
    void calculateFalling(int speed0, int sec_time, SDL_Rect *falling_object);
};

#endif // PHYSICS_H_INCLUDED
