#include "ShootyEnemyContainer.h"
#include "Gameworld.h"
#include "EBulletContainer.h"

ShootyEnemyContainer::ShootyEnemyContainer()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Shooty Enemy Container constructed with Param(%p)", this);
}

ShootyEnemyContainer::~ShootyEnemyContainer()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Shooty Enemy Container destroyed with Param(%p)", this);
}

void ShootyEnemyContainer::Add()
{
	ShootyEnemy* anEnemy = new ShootyEnemy();
	anEnemy->parent = this;
	bulletContainer = new EBulletContainer();
	bulletContainer->parent = anEnemy;
	bulletContainer->Init(2);
	bulletCont = &(parent->bulletContainer);
	int offset = h - 120;
	int randomY = 70 + (rand() % offset);
	printf("randomY: %i", randomY);
	anEnemy->Init(w, randomY);
	this->enemyList.push_back(anEnemy);
}

void ShootyEnemyContainer::Update()
{
	SDL_GetWindowSize(parent->window, &w, &h);
	frames++;
	if (frames == 180)
	{
		Add();
		frames = 0;
	}

	auto it = enemyList.begin();
	while (it != enemyList.end())
	{
		Enemies* enemy = *it;
		ShootyEnemy* shootyEnemy = static_cast<ShootyEnemy*>(enemy);
		shootyEnemy->Update(w, h);
		if (shootyEnemy->Destroyed())
		{
			delete shootyEnemy;
			it = enemyList.erase(it);

		}
		else
		{
			++it;
		}
	}
}