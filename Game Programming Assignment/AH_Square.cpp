#include "AH_Square.h"
#include "SDL.h"

#define MAX_KEYS (256)
bool gKeys[MAX_KEYS];

AH_Square::AH_Square()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square constructed with Param(%p)", this);
}

AH_Square::~AH_Square()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square destroyed with Param(%p)", this);
}

void AH_Square::Init(int px, int py, int pw, int ph)
{
	rect.x = px;
	rect.y = py;
	rect.w = pw;
	rect.h = ph;
	R = 255;
	G = 0;
	B = 0;

}

void AH_Square::Input(int whichKey)
{
    gKeys[whichKey] = !gKeys[whichKey];
}

void AH_Square::Update()
{
    char timestring[32];
    getTime(timestring, 32);
    if (rect.y > 0) 
    {
        if (gKeys[SDLK_w])
        {
            rect.y--;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    if (rect.y < (600 - rect.h)) 
    {
        if (gKeys[SDLK_s])
        {
            rect.y++;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    if (rect.x > 0) 
    {
        if (gKeys[SDLK_a])
        {
            rect.x--;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    if (rect.x < (800 - rect.w)) 
    {
        if (gKeys[SDLK_d])
        {
            rect.x++;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    
}

void AH_Square::Render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

bool AH_Square::getTime(char * buffer, int buffersize)
{
    time_t currentTime = std::time(0);
    struct tm info;
    localtime_s(&info, &currentTime);
    size_t written = strftime(buffer, buffersize, "%d/%m/%y %T", &info);
    return written != 0;
}
