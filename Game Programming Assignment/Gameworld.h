#ifndef GameFILE
#define GameFILE

#include <iostream>
#include <ctime>
#include <vector>
#include "SDL.h"
#include "Timer.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "AH_Square.h"
#include "BulletContainer.h"
#include "ShootyEnemyContainer.h"
#include "EnemiesContainer.h"

class Gameworld
{
public:
    bool getTime(char* buffer, int  buffersize);
    void startWorld();
    void onslaught();

    bool fs;
    bool beginOnslaught;

    SDL_Rect bg;
    SDL_Rect renderRect;

    SDL_Texture* background;
    SDL_Texture* texture;

    TTF_Font* font1;

    std::string string;

    unsigned int lastTime, currentTime;

    int timer;

    int W = 800;
    int H = 600;
    SDL_Window* window;
    SDL_Renderer* renderer;
    BulletContainer bulletContainer;
    ShootyEnemyContainer SECont;
    EnemiesContainer enemyContainer;
};

#endif