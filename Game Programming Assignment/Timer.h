#ifndef TimerFILE
#define TimerFILE

#include "SDL.h"

class Timer
{
private:
	int startTicks;
public:
	Timer();
	void resetTicksTimer();
	int getTicks();
};
#endif
