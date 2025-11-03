#pragma once
#include <SDL3/SDL.h>

class UTimer
{
public:
	UTimer();
	virtual ~UTimer();

	void Tick();
	
	//milliseconds 10^-3
	SDL_Time CurrentTime;
	SDL_Time LastTime;

	float DeltaSeconds;
};

