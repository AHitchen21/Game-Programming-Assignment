#include "Gameworld.h"
#include "BulletContainer.h"

bool Gameworld::getTime(char* buffer, int  buffersize)
    {
        time_t currentTime = std::time(0);
        struct tm info;
        localtime_s(&info, &currentTime);
        size_t written = strftime(buffer, buffersize, "%d/%m/%y %T", &info);
        return written != 0;
    }

void Gameworld::startWorld()
{
    AH_Square square1;
    square1.parent = this;
    BulletContainer bulletContainer;
    bulletContainer.parent = &square1;
    Timer time;
    SDL_Event event;
    const int DELTA_TIME = 16.66666;
    bool quit = false;
    bool left = true;
    bool move = true;

    window = SDL_CreateWindow("Alexander Hitchen, 26988001", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    square1.Init(30, 30, 50, 50);
    bulletContainer.Init(4);


 
    while (!quit)
    {
        //input
        time.resetTicksTimer();
        while (SDL_PollEvent(&event))
        {
            SDL_Keycode keyPressed = event.key.keysym.sym;
            char timestr[32];
            getTime(timestr, 32);
            if (event.type == SDL_KEYDOWN && event.key.repeat == NULL)
            {
                SDL_Log("[%s] [KEYDOWN] time %d; code %d; char %s;", timestr, event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    square1.Input(SDLK_w);
                    break;
                case SDLK_a:
                    square1.Input(SDLK_a);
                    break;
                case SDLK_s:
                    square1.Input(SDLK_s);
                    break;
                case SDLK_d:
                    square1.Input(SDLK_d);
                    break;
                case SDLK_SPACE:
                    bulletContainer.Input();
                }
                
            }
            if (event.type == SDL_KEYUP && event.key.repeat == NULL)
            {
                SDL_Log("[%s] [KEYUP] time %d; code %d; char %s;", timestr, event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    square1.Input(SDLK_w);
                    break;
                case SDLK_a:
                    square1.Input(SDLK_a);
                    break;
                case SDLK_s:
                    square1.Input(SDLK_s);
                    break;
                case SDLK_d:
                    square1.Input(SDLK_d);
                    break;
                }
            }
            if (event.type == SDL_QUIT)
            {
                quit = true;
                SDL_Quit;
            }
        }

        //update
        square1.Update();
        bulletContainer.Update();
        //Render
        square1.Render(renderer);
        bulletContainer.Render(renderer);
        SDL_RenderPresent(renderer);

        if (time.getTicks() < DELTA_TIME)
        {
            SDL_Delay(DELTA_TIME - time.getTicks());
        }
    }
 }

