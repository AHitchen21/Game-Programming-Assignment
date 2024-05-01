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
	virtual ~Enemies();

	virtual void Init(int px, int py, SDL_Renderer* renderer);
	virtual void Update(int screenX, int screenY);
	void Render(SDL_Renderer* renderer);
	bool collidedWithBullet(Bullet* aBullet);
	bool Destroyed();
	SDL_Rect rect;
	int R, G, B, w, h;



	EnemiesContainer* parent;

protected:
	SDL_Event event;
	Vector velocity;
	int ySpeed;

};
#endif
