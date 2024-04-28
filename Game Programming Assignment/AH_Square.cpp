#include "AH_Square.h"
#include "BulletContainer.h"
#include "Gameworld.h"
#include "SDL.h"
#include <vector>

#define MAX_KEYS (256)
bool gKeys[MAX_KEYS];

AH_Square::AH_Square()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square constructed with Param(%p)", this);
    speed = 7;
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

    velocity.X = 0;
    velocity.Y = 0;

}

void AH_Square::Input(int whichKey)
{
    gKeys[whichKey] = !gKeys[whichKey];
}

void AH_Square::Update()
{
    char timestring[32];
    parent->getTime(timestring, 32);
    SDL_GetWindowSize(parent->window, &w, &h);
    if (gKeys[SDLK_w])
    {
        if (rect.y < 0)
        {
            velocity.Y = 0;
        }
        else if (velocity.Y > -speed) 
        {
            velocity.Y = velocity.Y - 2;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    if (gKeys[SDLK_s])
    {
        if (rect.y > h - rect.h)
        {
            velocity.Y = 0;
        }
        else if (velocity.Y < speed) 
        {
            velocity.Y = velocity.Y + 2;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    if (gKeys[SDLK_a])
    {
        if (rect.x < 0)
        {
            velocity.X = 0;
        }
        else if (velocity.X > -speed) 
        {
            velocity.X = velocity.X - 2;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    if (gKeys[SDLK_d])
    {
        if (rect.x > w - rect.w)
        {
            velocity.X = 0;
        }
        else if (velocity.X < speed) 
        {
            velocity.X = velocity.X + 2;
            SDL_Log("[%s] [POS] square position: (%i,%i)", timestring, rect.x, rect.y);
        }
    }
    rect.x = rect.x + velocity.X;
    rect.y = rect.y + velocity.Y;
    if (velocity.X > 0) 
    {
        velocity.X = velocity.X - 1;
    }
    if (velocity.X < 0)
    {
        velocity.X = velocity.X + 1;
    }
    if (velocity.Y > 0) 
    {
        velocity.Y = velocity.Y - 1;
    }
    if (velocity.Y < 0)
    {
        velocity.Y = velocity.Y + 1;
    }
}

void AH_Square::Render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

