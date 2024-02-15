// Game Programming Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Event event;
    int quit = 0;
    int fs = 1;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Alexander Hitchen, 26988001", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    /*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    int x = 310;
    int y = 210;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) 
        {
            SDL_Rect r;
            r.x = x;
            r.y = y;
            r.w = 20;
            r.h = 20;
            SDL_RenderDrawRect(renderer, &r);
            x = x + 20;
        }
        y = y + 20;
        x = 310;
    }*/

    for (int i = 0; i < 1000; i++)
    {
        int scaleX = rand() % 100;
        int scaleY = rand() % 100;
        int startX = rand() % 800;
        int startY = rand() % 600;
        int endX = rand() % 800;
        int endY = rand() % 600;
        int colorR = rand() % 255;
        int colorG = rand() % 255;
        int colorB = rand() % 255;
        SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
        SDL_RenderDrawLine(renderer, startX, startY, endX, endY);

    }
    SDL_RenderPresent(renderer);
    while (!quit) 
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                if (fs == 1) {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    fs = 0;
                }
                else 
                {
                    SDL_SetWindowFullscreen(window, 0);
                    SDL_SetWindowSize(window, 800, 600);
                    fs = 1;
                }
                break;
            case SDL_QUIT:
                quit = 1;
                break;
            default:
                break;
            }

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
