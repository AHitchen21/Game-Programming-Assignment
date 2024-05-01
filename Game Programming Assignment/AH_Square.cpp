#include "AH_Square.h"
#include "BulletContainer.h"
#include "Gameworld.h"
#include "SDL_image.h"
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

void AH_Square::Init(int px, int py, int pw, int ph, SDL_Renderer* aRenderer)
{
	rect.x = px;
	rect.y = py;
	rect.w = pw;
	rect.h = ph;
	R = 255;
	G = 0;
	B = 0;

    posRect.x = px;
    posRect.y = py;
    posRect.w = pw * 2;
    posRect.h = ph * 2;

    renderRect.x = 16;
    renderRect.y = 144;
    renderRect.w = 32;
    renderRect.h = 32;

    SDL_Surface* surfaceIdle = IMG_Load("content/Root_Idle.png");
    textureIdle = SDL_CreateTextureFromSurface(aRenderer, surfaceIdle);
    SDL_FreeSurface(surfaceIdle);

    SDL_Surface* surfaceWalk = IMG_Load("content/Root_Walk.png");
    textureWalk = SDL_CreateTextureFromSurface(aRenderer, surfaceWalk);
    SDL_FreeSurface(surfaceIdle);

    invulnerable = false;

    up = false;
    down = false;
    right = false;
    left = false;

    health = 100;
    frames = 0;

    velocity.X = 0;
    velocity.Y = 0;

}

void AH_Square::Input(int whichKey)
{
    gKeys[whichKey] = !gKeys[whichKey];
}


bool AH_Square::collidedWithBullet(EnemyBullet* aBullet)
{
    if ((rect.x + rect.w) < aBullet->bulletRect.x)
    {
        return false;
    }
    else if (rect.x > (aBullet->bulletRect.x + aBullet->bulletRect.w))
    {
        return false;
    }
    else if ((rect.y + rect.h) < aBullet->bulletRect.y)
    {
        return false;
    }
    else if (rect.y > (aBullet->bulletRect.y + aBullet->bulletRect.h))
    {
        return false;
    }
    else
    {
        aBullet->hit = true;
        return true;
    }
}

bool AH_Square::collidedWithEnemy(Enemies* anEnemy)
{
    if ((rect.x + rect.w) < anEnemy->rect.x)
    {
        return false;
    }
    else if (rect.x > (anEnemy->rect.x + anEnemy->rect.w))
    {
        return false;
    }
    else if ((rect.y + rect.h) < anEnemy->rect.y)
    {
        return false;
    }
    else if (rect.y > (anEnemy->rect.y + anEnemy->rect.h))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void AH_Square::Update()
{
    if (invulnerable)
    {
        frames++;
    }
    if (frames == 60)
    {
        invulnerable = false;
        frames = 0;
    }
    char timestring[32];
    parent->getTime(timestring, 32);
    if (!invulnerable) 
    {
        if (parent->SECont.bulletContainer != nullptr)
        {
            for (auto& item : parent->SECont.bulletContainer->bulletList)
            {
                if (collidedWithBullet(item) && item->shot)
                {
                    health -= 20;
                    invulnerable = true;
                    SDL_Log("Health: %i", health);
                    if (health == 0)
                    {
                        R = 0;
                        B = 255;
                    }
                }
            }
            for (auto& item : parent->SECont.enemyList)
            {
                if (collidedWithEnemy(item) && !invulnerable)
                {
                    health -= 20;
                    invulnerable = true;
                    SDL_Log("Health: %i", health);
                    if (health == 0)
                    {
                        R = 0;
                        B = 255;
                    }
                }
            }
        }
    }
    for (auto& item : parent->enemyContainer.enemyList)
    {
        if (collidedWithEnemy(item) && !invulnerable)
        {
            health -= 20;
            invulnerable = true;
            SDL_Log("Health: %i", health);
            if (health == 0)
            {
                R = 0;
                B = 255;
            }
        }
    }
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
    posRect.x = rect.x - 32;
    posRect.y = rect.y - 64;
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
    rendFrames++;
    if (right)
    {
        renderRect.y = 144;
    }
    else if (left)
    {
        renderRect.y = 144;
    }
    else if (up)
    {
        renderRect.y = 16;
    }
    else if (down)
    {
        renderRect.y = 208;
    }
    if (rendFrames < 20)
    {
        renderRect.x = 16;
    }
    else if (rendFrames >= 20 && rendFrames < 40)
    {
        renderRect.x = 80;
    }
    else if (rendFrames >= 40 && rendFrames < 60)
    {
        renderRect.x = 144;
    }
    else if (rendFrames >= 60 && rendFrames < 80)
    {
        renderRect.x = 208;
    }
    else 
    {
        rendFrames = 0;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    if (invulnerable && frames % 10 == 0)
    {
        //do nothing
    }
    else 
    {
        if (left || right || up || down)
        {
            SDL_RenderCopy(renderer, textureWalk, &renderRect, &posRect);
        }
        else
        {
            SDL_RenderCopy(renderer, textureIdle, &renderRect, &posRect);
        }
    }
    SDL_RenderDrawRect(renderer, &rect);
}

