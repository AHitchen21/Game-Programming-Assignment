#include "Enemies.h"
#include "EnemiesContainer.h"
#include "BulletContainer.h"

Enemies::Enemies()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy constructed with Param(%p)", this);
}

Enemies::~Enemies()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy destroyed with Param(%p)", this);
}

void Enemies::Init(int pX, int pY, SDL_Renderer* renderer)
{
	rect.x = pX + 50;
	rect.y = pY;
	rect.w = 64;
	rect.h = 64;
	
	posRect.x = pX;
	posRect.y = pY;
	posRect.w = 50 * 2;
	posRect.h = 50 * 2;

	renderRect.x = 0;
	renderRect.y = 32;
	renderRect.w = 32;
	renderRect.h = 32;

	w = 0;
	h = 0;

	renderFrames = 0;

	walkSprite = IMG_LoadTexture(renderer, "content/WhiteCat.png");

	R = 0;
	G = 0;
	B = 255;

	int random = rand() % 2;
	int randomSpeed = 2 + rand() % 8;
	ySpeed = 5 + rand() % 10;

	if (random == 1)
	{
		velocity.Y = ySpeed;
	}
	else 
	{
		velocity.Y = -ySpeed;
	}

	velocity.X = -randomSpeed;
	
}

void Enemies::Update(int screenX, int screenY)
{

	if (rect.y > screenY - 70 && velocity.Y > -ySpeed)
	{
		velocity.Y = velocity.Y - 1;
	}
	if (rect.y < 10 && velocity.Y < ySpeed)
	{
		velocity.Y = velocity.Y + 1;
	}
	rect.x = rect.x + velocity.X;
	rect.y = rect.y + velocity.Y;
	posRect.x = rect.x - 16;
	posRect.y = rect.y - 32;
}

bool Enemies::Destroyed()
{
	for (auto& item : parent->bulletCont->bulletList)
	{
		if (collidedWithBullet(item) && item->shot)
		{
			return true;
		}
	}
	if (rect.x < -60)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Enemies::collidedWithBullet(Bullet* aBullet)
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

void Enemies::Render(SDL_Renderer* aRenderer)
{
	renderFrames++;
	if (renderFrames < 15)
	{
		renderRect.x = 0;
	}
	else if (renderFrames >= 15 && renderFrames < 30)
	{
		renderRect.x = 32;
	}
	else 
	{
		renderFrames = 0;
	}
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderCopy(aRenderer, walkSprite, &renderRect, &posRect);
}