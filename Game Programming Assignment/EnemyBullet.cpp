#include "EnemyBullet.h"
#include "EBulletContainer.h"

EnemyBullet::EnemyBullet()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy Bullet constructed with Param(%p)", this);
}

EnemyBullet::~EnemyBullet()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy Bullet destroyed with Param(%p)", this);
	SDL_DestroyTexture(bulletTexture);
}

void EnemyBullet::Init(int eX, int eY, SDL_Renderer* renderer)
{
	bulletRect.x = eX;
	bulletRect.y = eY;
	bulletRect.w = 32;
	bulletRect.h = 32;

	renderRect.x = 0;
	renderRect.y = 0;
	renderRect.w = 32;
	renderRect.h = 32;

	posRect.x = eX;
	posRect.y = eY;
	posRect.w = 32;
	posRect.h = 32;

	bulletTexture = IMG_LoadTexture(renderer, "content/Fish 0031.png");

	velocity.X = -10;
	velocity.Y = 0;

	frames = 0;

	shot = false;
	hit = false;
}

void EnemyBullet::Update(int posX, int posY, int screenX, int screenY)
{
	frames++;
	if (frames == 30)
	{
		shot = true;
		frames = 0;
	}
	if (shot == true)
	{
		if (bulletRect.x > screenX || bulletRect.x < 0 || bulletRect.y > screenY || bulletRect.y < 0 || hit == true)
		{
			shot = false;
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

void EnemyBullet::Render(SDL_Renderer* aRenderer)
{
	if (shot == true)
	{
		SDL_SetRenderDrawColor(aRenderer, 0, 255, 0, 0);
		SDL_RenderCopy(aRenderer, bulletTexture, &renderRect, &posRect);
	}
}