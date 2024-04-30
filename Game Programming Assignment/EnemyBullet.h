#ifndef EnemyBulletFILE
#define EnemyBulletFILE

#include "SDL.h"
#include "Vector.h"

class EBulletContainer;

class EnemyBullet
{
public:
	EnemyBullet();
	~EnemyBullet();
	void Init(int pX, int pY);
	void Update(int posX, int posY, int screenX, int screenY);
	void Render(SDL_Renderer* aRenderer);

	SDL_Rect bulletRect;

	int frames;

	bool shot;
	bool hit;

	EBulletContainer* parent;

	Vector velocity;
};
#endif