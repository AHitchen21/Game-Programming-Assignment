// Game Programming Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <vector>
#include "SDL.h"
#include "Timer.h"
#include "SDL_image.h"
#include "AH_Square.h"
#include "Gameworld.h"


int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 1;
    }

    if (IMG_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 1;
    }

    Gameworld gw;

    srand(std::time(NULL));


    gw.startWorld();

    return 0;
}