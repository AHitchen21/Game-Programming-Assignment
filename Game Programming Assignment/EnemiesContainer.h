#ifndef EnemiesContFILE
#define EnemiesContFILE

#include"SDL.h"
#include "Enemies.h"
#include<vector>

class Gameworld;

class EnemiesContainer
{
public:
	EnemiesContainer();
	~EnemiesContainer();
	void Init(int eNum);
	void Add();
	void Render(SDL_Renderer* aRenderer);
	void Update();

	std::vector<Enemies*> enemyList;
	int Num;

	Gameworld* parent;
};
#endif
