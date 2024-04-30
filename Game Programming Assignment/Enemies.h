#ifndef EnemiesFILE
#define EnemiesFILE

#include"SDL.h"
#include"Vector.h"
#include "Bullet.h"

class EnemiesContainer;

class Enemies
{
public:
	Enemies();
	~Enemies();

	void Init(int px, int py);
	void Update(int screenX, int screenY);
	void Render(SDL_Renderer* renderer);
	bool collidedWithBullet(Bullet* aBullet);
	bool Destroyed();
	SDL_Rect rect;
	int R, G, B, w, h;

	EnemiesContainer* parent;

private:
	SDL_Event event;
	Vector velocity;
	int speed;
};
#endif
