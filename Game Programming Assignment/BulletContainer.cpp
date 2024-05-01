#include "BulletContainer.h"
#include "AH_Square.h"

BulletContainer::BulletContainer()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Bullet Container constructed with Param(%p)", this);
}

void BulletContainer::Init(int eNum, SDL_Renderer* renderer)
{
	Num = eNum;

	for (int i = 0; i < Num; i++)
	{
		Add(renderer);
	}
}

BulletContainer::~BulletContainer()
{
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
		item->Update(parent->rect.x, parent->rect.y, parent->w, parent->h);
	}
}

void BulletContainer::Render(SDL_Renderer* aRenderer)
{
	for (auto& item : bulletList)
	{
		item->Render(aRenderer);
	}
}