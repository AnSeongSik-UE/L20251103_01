#include <Windows.h>

#include "PaperFlipBookComponent.h"
#include "Vector.h"
#include "Actor.h"

UPaperFlipBookComponent::UPaperFlipBookComponent()
{
}
UPaperFlipBookComponent::~UPaperFlipBookComponent()
{
}

void UPaperFlipBookComponent::Tick()
{
}
void UPaperFlipBookComponent::Render()
{
	//COORD Position;
	//Position.X = GetOwner()->GetActorLocation().X;
	//Position.Y = GetOwner()->GetActorLocation().Y;

	//SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	//std::cout << Shape;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	float SizeX = 30.f;
	float SizeY = 30.f;
	SDL_FRect DrawRect =
	{
		GetOwner()->GetActorLocation().X * SizeX,
		GetOwner()->GetActorLocation().Y * SizeY,
		SizeX,
		SizeY
	};
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
}