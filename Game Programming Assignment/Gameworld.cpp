#include "Gameworld.h"
#include "EnemiesContainer.h"
#include "Enemies.h"
#include "ShootyEnemyContainer.h"
#include "EBulletContainer.h"
#include "SDL_ttf.h"

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
    bg = { 0 , 0, 1024, 768 };
    renderRect = { 0 , 0, 3000, 1500 };
    timer = 5;

    string = "Timer: " + std::to_string(timer) + "s";
    const char* newString = string.c_str();

    lastTime, currentTime = 0;

    AH_Square square1;
    square1.parent = this;
    bulletContainer.parent = &square1;
    enemyContainer.parent = this;
    SECont.parent = this;
    Timer time;
    SDL_Event event;
    const int DELTA_TIME = 16.66666;
    bool quit = false;
    bool left = true;
    bool move = true;
    beginOnslaught = false;
    fs = false;

    window = SDL_CreateWindow("Alexander Hitchen, 26988001", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    background = IMG_LoadTexture(renderer, "content/2589522.png");
    
    square1.Init(30, 30, 64, 64, renderer);
    bulletContainer.Init(6, renderer);
    enemyContainer.Init();
    SECont.Init();


 
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
                    square1.up = true;
                    break;
                case SDLK_a:
                    square1.Input(SDLK_a);
                    square1.left = true;
                    break;
                case SDLK_s:
                    square1.Input(SDLK_s);
                    square1.down = true;
                    break;
                case SDLK_d:
                    square1.Input(SDLK_d);
                    square1.right = true;
                    break;
                case SDLK_SPACE:
                    bulletContainer.Input();
                    break;
                case SDLK_f:
                    if (fs)
                    {
                        SDL_SetWindowFullscreen(window, 0);
                        SDL_SetWindowSize(window, 1024, 768);
                        fs = false;
                    }
                    else 
                    {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                        fs = true;
                    }
                }
                
            }
            if (event.type == SDL_KEYUP && event.key.repeat == NULL)
            {
                SDL_Log("[%s] [KEYUP] time %d; code %d; char %s;", timestr, event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    square1.Input(SDLK_w);
                    square1.up = false;
                    break;
                case SDLK_a:
                    square1.Input(SDLK_a);
                    square1.left = false;
                    break;
                case SDLK_s:
                    square1.Input(SDLK_s);
                    square1.down = false;
                    break;
                case SDLK_d:
                    square1.Input(SDLK_d);
                    square1.right = false;
                    break;
                }
            }
            if (event.type == SDL_QUIT)
            {
                quit = true;
                SDL_DestroyTexture(background);
                TTF_Quit;
                IMG_Quit;
                SDL_Quit;
            }
        }

        //update
        square1.Update();
        bulletContainer.Update();
        enemyContainer.Update(renderer);
        SECont.Update(renderer);
        if (SECont.bulletContainer != nullptr) 
        {
            SECont.bulletContainer->Update();
        }
        //Render
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, &renderRect, &bg);
        square1.Render(renderer);
        bulletContainer.Render(renderer);
        enemyContainer.Render(renderer);
        SECont.Render(renderer);
        if (SECont.bulletContainer != nullptr) 
        {
            SECont.bulletContainer->Render(renderer);
        }
        int textW = 0;
        int textH = 0;
        SDL_Color colour = { 255, 255, 255 };
        string = "Timer: " + std::to_string(timer) + "s";
        const char* newString = string.c_str();
        SDL_Surface* surface1 = TTF_RenderText_Solid(bulletContainer.font, newString, colour);
        SDL_DestroyTexture(texture);
        texture = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_FreeSurface(surface1);
        SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
        SDL_Rect textPosRect = { 430 , 0, textW, textH };
        SDL_RenderCopy(renderer, texture, NULL, &textPosRect);
        SDL_RenderPresent(renderer);

        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1000)
        {
            //change timer
            timer--;
            lastTime = currentTime;
        }
        if (timer == 0 && bulletContainer.score >= 150000 && beginOnslaught == false)
        {
            beginOnslaught = true;
            timer = 15;
            enemyContainer.spawnTimer = 10;
            //onslaught
        }

        if (timer == 0 && bulletContainer.score < 150000 || beginOnslaught == true)
        {
            string = "GAME OVER!!!";
            std::string string2 = "Your score: " + std::to_string(bulletContainer.score);
            const char* newString = string.c_str();
            const char* newString2 = string2.c_str();
            SDL_Surface* surface1 = TTF_RenderText_Solid(bulletContainer.font, newString, colour);
            SDL_Surface* surface2 = TTF_RenderText_Solid(bulletContainer.font, newString2, colour);
            SDL_DestroyTexture(texture);
            texture = SDL_CreateTextureFromSurface(renderer, surface1);
            SDL_FreeSurface(surface1);
            SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
            SDL_Rect textPosRect = { 430 , 230, textW, textH };
            SDL_Rect textPosRect2 = { 430 , 350, textW, textH };
            SDL_RenderCopy(renderer, texture, NULL, &textPosRect);
            SDL_DestroyTexture(texture);
            texture = SDL_CreateTextureFromSurface(renderer, surface2);
            SDL_FreeSurface(surface2);
            SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
            SDL_RenderCopy(renderer, texture, NULL, &textPosRect2);
            SDL_RenderPresent(renderer);
            SDL_Delay(3000);
            SDL_Event events;
            events.type = SDL_QUIT;
            SDL_PushEvent(&events);
        }

        SDL_Log("Frame ran in %i ms", time.getTicks());

        if (time.getTicks() < DELTA_TIME)
        {
            SDL_Delay(DELTA_TIME - time.getTicks());
        }

    }
 }


