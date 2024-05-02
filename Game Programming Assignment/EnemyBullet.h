#ifndef EnemyBulletFILE
#define EnemyBulletFILE

#include "SDL.h"
#include "SDL_image.h"
#include "Vector.h"

class EBulletContainer;

class EnemyBullet
{
public:
	EnemyBullet();
	~EnemyBullet();
	void Init(int pX, int pY, SDL_Renderer* renderer);
	void Update(int posX, int posY, int screenX, int screenY);
	void Render(SDL_Renderer* aRenderer);

	SDL_Rect bulletRect;
	SDL_Rect renderRect;
	SDL_Rect posRect;

	SDL_Texture* bulletTexture;

	int frames;

	bool shot;
	bool hit;

	EBulletContainer* parent;

	Vector velocity;
};
#endif