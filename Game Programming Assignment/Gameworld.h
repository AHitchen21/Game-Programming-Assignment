#ifndef GameFILE
#define GameFILE

#include <iostream>
#include <ctime>
#include <vector>
#include "SDL.h"
#include "Timer.h"
#include "AH_Square.h"
#include "BulletContainer.h"

class Gameworld
{
public:
    bool getTime(char* buffer, int  buffersize);
    void startWorld();
    int W = 800;
    int H = 600;
    SDL_Window* window;
    SDL_Renderer* renderer;
    BulletContainer bulletContainer;
private:
    
};

#endif