#ifndef PROJECT_BUILDER_H_INCLUDED
#define PROJECT_BUILDER_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "InputHandler.h"
#include "Graphics.h"
#include "Physics.h"
#include "Audio.h"
SDL_Event event;
InputHandler input_handler(&event);
Physics physics;
#endif // PROJECT_BUILDER_H_INCLUDED
