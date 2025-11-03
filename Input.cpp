#include "Input.h"
#include "Engine.h"
#include "SDL3/SDL.h"

int UInput::KeyCode = 0;

UInput::UInput()
{
}
UInput::~UInput()
{
}

void UInput::Tick()
{
	if(GEngine->MyEvent.key.down)
	{
		KeyCode = GEngine->MyEvent.key.key;
	}
	else
	{
		KeyCode = 0;
	}
}