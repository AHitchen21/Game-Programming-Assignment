#ifndef BulletContainerFILE
#define BulletContainerFILE

#include"SDL.h"
#include<vector>
#include "Bullet.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>

class AH_Square;

class BulletContainer
{
public:
	BulletContainer();
	~BulletContainer();
	void Init(int eNum, SDL_Renderer* renderer);
	void Add(SDL_Renderer* renderer);
	void Input();
	void Render(SDL_Renderer* aRenderer);
	void Update();

	std::vector<Bullet*> bulletList;
	int Num;

	int score, multiplier, hitCount;

	bool reset;

	std::string string;

	AH_Square* parent;

	SDL_Texture* text;

	TTF_Font* font;
};
#endif
