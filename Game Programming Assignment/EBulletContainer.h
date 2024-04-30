#ifndef EBulletContainerFILE
#define EBulletContainerFILE

#include "SDL.h"
#include "vector"
#include "EnemyBullet.h"

class ShootyEnemy;

class EBulletContainer
{
public:
	EBulletContainer();
	~EBulletContainer();
	void Init(int eNum);
	void Add();
	void Render(SDL_Renderer* aRenderer);
	void Update();

	std::vector<EnemyBullet*> bulletList;
	int Num;

	ShootyEnemy* parent;
};

#endif