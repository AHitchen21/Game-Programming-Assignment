#include "EBulletContainer.h"
#include "ShootyEnemy.h"

EBulletContainer::EBulletContainer()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy Bullet Container constructed with Param(%p)", this);
}

void EBulletContainer::Init(int eNum, SDL_Renderer* renderer)
{
	Num = eNum;

	for (int i = 0; i < Num; i++)
	{
		Add(renderer);
	}
}

EBulletContainer::~EBulletContainer()
{
	for (auto& item : bulletList)
	{
		delete item;
	}
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemy Bullet Container destroyed with Param(%p)", this);
}

void EBulletContainer::Add(SDL_Renderer* renderer)
{
	EnemyBullet* aBullet = new EnemyBullet();
	aBullet->parent = this;
	aBullet->Init(parent->rect.x, parent->rect.y - 25, renderer);
	this->bulletList.push_back(aBullet);
}

void EBulletContainer::Update()
{
	for (auto& item : bulletList)
	{
		item->Update(parent->rect.x, parent->rect.y, parent->w, parent->h);
	}
}

void EBulletContainer::Render(SDL_Renderer* aRenderer)
{
	for (auto& item : bulletList)
	{
		item->Render(aRenderer);
	}
}