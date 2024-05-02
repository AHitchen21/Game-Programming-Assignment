#include "BulletContainer.h"
#include "AH_Square.h"

BulletContainer::BulletContainer()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet Container constructed with Param(%p)", this);
}

void BulletContainer::Init(int eNum, SDL_Renderer* renderer)
{
	Num = eNum;
	multiplier = 1;
	hitCount = 0;

	font = TTF_OpenFont("content/arial.ttf", 25);

	string = "Score: " + std::to_string(score) + " x" + std::to_string(multiplier);
	const char* newString = string.c_str();
	reset = false;

	for (int i = 0; i < Num; i++)
	{
		Add(renderer);
	}
}

BulletContainer::~BulletContainer()
{
	SDL_DestroyTexture(text);
	TTF_CloseFont(font);
	for (auto& item : bulletList)
	{
		delete item;
	}
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet Container destroyed with Param(%p)", this);
}

void BulletContainer::Add(SDL_Renderer* renderer)
{
	Bullet* aBullet = new Bullet();
	aBullet->parent = this;
	aBullet->Init(parent->rect.x, parent->rect.y - 25, renderer);
	this->bulletList.push_back(aBullet);
}

void BulletContainer::Input()
{
	for (auto& item : bulletList) 
	{
		if (!item->shot)
		{
			SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet Shot");
			item->Input();
			break;
		}
	}
}

void BulletContainer::Update()
{
	for (auto& item : bulletList)
	{
		if (item->hit)
		{
			score += 100 * multiplier;
			hitCount++;
			if (hitCount % 5 == 0)
			{
				multiplier++;
			}
		}
		if (parent->invulnerable && !reset)
		{
			multiplier = 1;
			reset = true;
		}
		else if (!parent->invulnerable && reset)
		{
			reset = false;
		}
		item->Update(parent->rect.x, parent->rect.y, parent->w, parent->h);
	}
}

void BulletContainer::Render(SDL_Renderer* aRenderer)
{
	int textW = 0;
	int textH = 0;
	SDL_Color colour = { 255, 255, 255 };
	string = "Score: " + std::to_string(score) + " x" + std::to_string(multiplier);
	const char* newString = string.c_str();
	SDL_Surface* surface = TTF_RenderText_Solid(font, newString, colour);
	SDL_DestroyTexture(text);
	text = SDL_CreateTextureFromSurface(aRenderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(text, NULL, NULL, &textW, &textH);
	SDL_Rect textPosRect = { 0 , 0, textW, textH };
	SDL_RenderCopy(aRenderer, text, NULL, &textPosRect);
	for (auto& item : bulletList)
	{
		item->Render(aRenderer);
	}
}