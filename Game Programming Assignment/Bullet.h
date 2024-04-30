#ifndef BulletFILE
#define BulletFILE


#include "SDL.h"
#include "Vector.h"

class BulletContainer;

class Bullet
{
public:
	Bullet();
	~Bullet();
	void Init(int pX, int pY);
	void Input();
	void Update(int posX, int posY, int screenX, int screenY);
	void Render(SDL_Renderer* aRenderer);

	SDL_Rect bulletRect;

	bool shot;
	bool input;
	bool hit;

	BulletContainer* parent;

	Vector velocity;
};
#endif
