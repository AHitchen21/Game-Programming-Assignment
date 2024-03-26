#ifndef ASquare
#define ASquare

#include "SDL.h"
#include <iostream>
#include <ctime>

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
	int R, G, B;

	bool getTime(char* buffer, int buffersize);

private:
	SDL_Event event;
};
#endif

