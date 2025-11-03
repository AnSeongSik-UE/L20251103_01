#include "Timer.h"

UTimer::UTimer()
{
	CurrentTime = 0;
	LastTime = 0;
	DeltaSeconds = 0.f;
}
UTimer::~UTimer()
{
}

void UTimer::Tick()
{
	CurrentTime = SDL_GetTicksNS();

	DeltaSeconds = (double)(CurrentTime - LastTime) / 1000000000.0;
	
	LastTime = CurrentTime;
}
