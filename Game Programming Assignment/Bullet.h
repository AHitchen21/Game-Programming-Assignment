#ifndef BulletFILE
#define BulletFILE


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Vector.h"
#include <iostream>

class BulletContainer;

class Bullet
{
public:
	Bullet();
	~Bullet();
	void Init(int pX, int pY, SDL_Renderer* renderer);
	void Input();
	void Update(int posX, int posY, int screenX, int screenY);
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect posRect;
	SDL_Rect renderRect;
	SDL_Rect bulletRect;

	std::string string;

	int score;

	bool shot;
	bool input;
	bool hit;

	TTF_Font* font;

	SDL_Texture* bulletSprite;
	SDL_Texture* text;

	BulletContainer* parent;

	Vector velocity;
};
#endif
