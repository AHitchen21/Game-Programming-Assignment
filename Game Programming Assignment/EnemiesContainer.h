#ifndef EnemiesContFILE
#define EnemiesContFILE

#include"SDL.h"
#include "Enemies.h"
#include "BulletContainer.h"
#include<vector>

class Gameworld;

class EnemiesContainer
{
public:
	EnemiesContainer();
	virtual ~EnemiesContainer();
	void Init();
	virtual void Add();
	void Render(SDL_Renderer* aRenderer);
	virtual void Update();

	std::vector<Enemies*> enemyList;
	int Num, w, h, frames;

	BulletContainer* bulletCont;

	Gameworld* parent;
};
#endif
