#include "Bullet.h"
#include "BulletContainer.h"

Bullet::Bullet()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet constructed with Param(%p)", this);
}

Bullet::~Bullet()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet destroyed with Param(%p)", this);
}

void Bullet::Init(int eX, int eY, SDL_Renderer* renderer)
{
	bulletRect.x = eX;
	bulletRect.y = eY;
	bulletRect.w = 60;
	bulletRect.h = 20;

	posRect.x = eX;
	posRect.y = eY;
	posRect.w = 30 * 2;
	posRect.h = 10 * 2;

	renderRect.x = 0;
	renderRect.y = 110;
	renderRect.w = 100;
	renderRect.h = 40;

	bulletSprite = IMG_LoadTexture(renderer, "content/Skull&Bones - FrodoUndead.png");

	velocity.X = 10;
	velocity.Y = 0;

	shot = false;
	input = false;
	hit = false;
}

void Bullet::Input()
{
	if (shot == false) 
	{
		input = true;
		
	}
}

void Bullet::Update(int posX, int posY, int screenX, int screenY)
{
	if (input)
	{
		shot = true;
	}
	if (shot == true) 
	{
		if (bulletRect.x > screenX ||  bulletRect.y > screenY || bulletRect.y < 0 || hit == true) 
		{
			shot = false;
			input = false;
			hit = false;
		}
		else 
		{
			bulletRect.x = velocity.X + bulletRect.x;
			posRect.x = bulletRect.x;
		}
	}
	else 
	{
		bulletRect.x = posX;
		bulletRect.y = posY + 15;
		posRect.x = bulletRect.x;
		posRect.y = bulletRect.y;
	}
}

void Bullet::Render(SDL_Renderer* aRenderer)
{
	if (shot == true)
	{
		SDL_SetRenderDrawColor(aRenderer, 0, 255, 0, 0);
		SDL_RenderCopy(aRenderer, bulletSprite, &renderRect, &posRect);
		SDL_RenderDrawRect(aRenderer, &bulletRect);
	}
}