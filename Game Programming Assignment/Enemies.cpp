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
	rect.y = pY;
	rect.w = 50;
	rect.h = 50;

	R = 0;
	G = 0;
	B = 255;

	int random = rand() % 2;

	if (random == 1)
	{
		velocity.Y = 6;
	}
	else 
	{
		velocity.Y = -6;
	}

	velocity.X = -4;
	
}

void Enemies::Update(int screenX, int screenY)
{
	if (rect.y > screenY - 70 && velocity.Y > -10)
	{
		velocity.Y = velocity.Y - 1;
	}
	if (rect.y < 10 && velocity.Y < 10)
	{
		velocity.Y = velocity.Y + 1;
	}
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
		aBullet->hit = true;
		return true;
	}
}

void Enemies::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderDrawRect(aRenderer, &rect);
}