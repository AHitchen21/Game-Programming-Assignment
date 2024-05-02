#include "ShootyEnemy.h"
#include "EnemiesContainer.h"
#include "EBulletContainer.h"

ShootyEnemy::ShootyEnemy() : Enemies()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Shooty Enemy constructed with Param(% p)", this);
}

ShootyEnemy::~ShootyEnemy()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Shooty Enemy destroyed with Param(%p)", this);
	SDL_DestroyTexture(walkSprite);
}


void ShootyEnemy::Update(int screenX, int screenY)
{
	w = parent->w;
	h = parent->h;
	velocity.X = -4;
	velocity.Y = 0;
	rect.x = rect.x + velocity.X;
	rect.y = rect.y + velocity.Y;
	posRect.x = rect.x - 16;
	posRect.y = rect.y - 32;
}
