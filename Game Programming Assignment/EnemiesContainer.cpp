#include "EnemiesContainer.h"
#include "Gameworld.h"

EnemiesContainer::EnemiesContainer()
{
	char timestring[32];
	parent->getTime(timestring, 32);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[%s]Enemies Container created with Param(%p)", timestring, this);
}

EnemiesContainer::~EnemiesContainer()
{
	for (auto& item : enemyList)
	{
		delete item;
	}
	char timestring[32];
	parent->getTime(timestring, 32);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[%s]Enemies Container destroyed with Param(%p)", timestring, this);
}

void EnemiesContainer::Add(SDL_Renderer* renderer)
{
	Enemies* anEnemy = new Enemies();
	anEnemy->parent = this;
	bulletCont = &(parent->bulletContainer);
	int offset = h - 70;
	int randomY = 70 + (rand() % offset);
	printf("randomY: %i", randomY);
	anEnemy->Init(w, randomY, renderer);
	this->enemyList.push_back(anEnemy);
}

void EnemiesContainer::Init()
{
	frames = 0;
	spawnTimer = 60;
}

void EnemiesContainer::Update(SDL_Renderer* renderer)
{
	SDL_GetWindowSize(parent->window, &w, &h);
	frames++;
	if (frames >= spawnTimer)
	{
		Add(renderer);
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

