#ifndef ASquare
#define ASquare

#include "SDL.h"
#include "Vector.h"
#include "EnemyBullet.h"
#include "Enemies.h"
#include <iostream>

class Gameworld;

class AH_Square
{
public:
	AH_Square();
	~AH_Square();

	void Init(int px, int py, int pw, int ph, SDL_Renderer* aRenderer);
	void Update();
	void Input(int whichKey);
	void Render(SDL_Renderer* renderer);
	bool collidedWithBullet(EnemyBullet* aBullet);
	bool collidedWithEnemy(Enemies* anEnemy);
	SDL_Rect rect;
	SDL_Rect renderRect;
	SDL_Rect posRect;
	int R, G, B, w, h, health, frames, rendFrames;

	SDL_Texture* textureIdle;
	SDL_Texture* textureWalk;

	bool invulnerable;
	bool up;
	bool down;
	bool left;
	bool right;

	Gameworld* parent;

private:
	SDL_Event event;
	Vector velocity;
	int speed;
};
#endif

