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
	anEnemy->Init(0);

}
