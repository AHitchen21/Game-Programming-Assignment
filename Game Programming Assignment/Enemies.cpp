#include "Enemies.h"
#include "EnemiesContainer.h"

Enemies::Enemies()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy constructed with Param(%p)", this);
}

Enemies::~Enemies()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy destroyed with Param(%p)", this);
}

void Enemies::Init(int pX, int pY, int pW, int pH)
{
	rect.x = pX;
	rect.y = pY;
	rect.w = pW;
	rect.h = pH;

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

void Enemies::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderDrawRect(aRenderer, &rect);
}