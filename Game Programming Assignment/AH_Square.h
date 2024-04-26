#ifndef ASquare
#define ASquare

#include "SDL.h"
#include "Vector.h"
#include <iostream>

class Gameworld;

class AH_Square
{
public:
	AH_Square();
	~AH_Square();

	void Init(int px, int py, int pw, int ph);
	void Update();
	void Input(int whichKey);
	void Render(SDL_Renderer* renderer);
	SDL_Rect rect;
	int R, G, B, w, h;

	Gameworld* parent;

private:
	SDL_Event event;
	Vector velocity;
	int speed;
};
#endif

