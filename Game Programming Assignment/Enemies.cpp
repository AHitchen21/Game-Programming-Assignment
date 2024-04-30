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

void Enemies::Init(int pX, int pY)
{
	rect.x = pX + 50;
	rect.y = pY / 2;
	rect.w = 50;
	rect.h = 50;

	R = 0;
	G = 0;
	B = 255;

	velocity.X = -10;
	velocity.Y = 0;
}

void Enemies::Update(int screenX, int screenY)
{
	rect.x = rect.x + velocity.X;
	rect.y = rect.y + velocity.Y;
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
		return true;
	}
}

void Enemies::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderDrawRect(aRenderer, &rect);
}