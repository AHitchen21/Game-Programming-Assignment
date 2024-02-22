// Game Programming Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"
#include "Timer.h"

int main(int argc, char* argv[])
{


    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 1;
    }

    Timer time;
    SDL_Event event;
    const int DELTA_TIME = 16.66666;
    int quit = 0;
    bool left = true;

    SDL_Rect r1;
    r1.x = 200;
    r1.y = 300;
    r1.w = 20;
    r1.h = 20;

    SDL_Window* window = SDL_CreateWindow("Alexander Hitchen, 26988001", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);
    while (!quit) 
    {
        time.resetTicksTimer();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = 1;
                break;
            default:
                break;
            }
        }
        //update
        if (r1.x < 0)
        {
            left = false;
        }
        else if (r1.x > 790)
        {
            left = true;
        }
        if (left)
        {
            r1.x--;
        }
        else
        {
            r1.x++;
        }
        //Render
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &r1);
        SDL_RenderPresent(renderer);
        if (time.getTicks() < DELTA_TIME)
        {
            SDL_Delay(DELTA_TIME - time.getTicks());
        }
    }

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
