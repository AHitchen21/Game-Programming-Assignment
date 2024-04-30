#ifndef BulletContainerFILE
#define BulletContainerFILE

#include"SDL.h"
#include<vector>
#include "Bullet.h"

class AH_Square;

class BulletContainer
{
public:
	BulletContainer();
	~BulletContainer();
	void Init(int eNum);
	void Add();
	void Input();
	void Render(SDL_Renderer* aRenderer);
	void Update();

	std::vector<Bullet*> bulletList;
	int Num;

	AH_Square* parent;
};
#endif
