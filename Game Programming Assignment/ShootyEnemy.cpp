#include "ShootyEnemy.h"

ShootyEnemy::ShootyEnemy() : Enemies()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Shooty Enemy constructed with Param(% p)", this);
}

ShootyEnemy::~ShootyEnemy()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Shooty Enemy destroyed with Param(%p)", this);
}


void ShootyEnemy::Update(int screenX, int screenY)
{
	velocity.X = -4;
	velocity.Y = 0;
	rect.x = rect.x + velocity.X;
	rect.y = rect.y + velocity.Y;
}
