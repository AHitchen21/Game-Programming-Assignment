#include "EnemiesContainer.h"
#include "Gameworld.h"

EnemiesContainer::EnemiesContainer()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemies Container constructed with Param(%p)", this);
}

EnemiesContainer::~EnemiesContainer()
{
	for (auto& item : enemyList)
	{
		delete item;
	}
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Enemies Container destroyed with Param(%p)", this);
}

void EnemiesContainer::Add()
{
	Enemies* anEnemy = new Enemies();
	anEnemy->parent = this;
	bulletCont = &(parent->bulletContainer);
	anEnemy->Init(w, h);
	this->enemyList.push_back(anEnemy);
}

void EnemiesContainer::Init()
{
	frames = 0;
}

void EnemiesContainer::Update()
{
	SDL_GetWindowSize(parent->window, &w, &h);
	frames++;
	if (frames == 60)
	{
		Add();
		frames = 0;
	}

	auto it = enemyList.begin();
	while (it != enemyList.end())
	{
		auto& item = *it;
		item->Update(w, h);
		if (item->Destroyed())
		{
			delete item;
			it = enemyList.erase(it);
			
		}
		else 
		{
			++it;
		}
	}
}

void EnemiesContainer::Render(SDL_Renderer* renderer)
{
	for (auto& item : enemyList)
	{
		item->Render(renderer);
	}
}
