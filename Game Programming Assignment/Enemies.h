#ifndef EnemiesFILE
#define EnemiesFILE

#include"SDL.h"
#include"Vector.h"

class EnemiesContainer;

class Enemies
{
public:
	Enemies();
	~Enemies();

	void Init(int px, int py, int pw, int ph);
	void Update(int screenX, int screenY);
	void Render(SDL_Renderer* renderer);
	SDL_Rect rect;
	int R, G, B, w, h;

	EnemiesContainer* parent;

private:
	SDL_Event event;
	Vector velocity;
	int speed;
};
#endif
