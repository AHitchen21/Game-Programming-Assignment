#ifndef GameFILE
#define GameFILE

#include <iostream>
#include <ctime>
#include <vector>
#include "SDL.h"
#include "Timer.h"
#include "AH_Square.h"

class Gameworld
{
public:
    bool getTime(char* buffer, int  buffersize);
    void startWorld();
    std::vector<int> getWindowSize();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int W, H;
};

#endif