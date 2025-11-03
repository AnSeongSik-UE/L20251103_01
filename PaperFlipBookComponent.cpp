#include <Windows.h>

#include "PaperFlipBookComponent.h"
#include "Vector.h"
#include "Actor.h"

UPaperFlipBookComponent::UPaperFlipBookComponent()
{
}
UPaperFlipBookComponent::~UPaperFlipBookComponent()
{
	if (BitmapImage)
	{
		SDL_DestroySurface(BitmapImage);
		BitmapImage = nullptr;
	}
	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
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

	float SizeX = 30.f;
	float SizeY = 30.f;
	if ( !BitmapImage && !Texture )
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
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
	else
	{
		SDL_FRect SourceRect = { 0, 0, (float)BitmapImage->w, (float)BitmapImage-> h};
		SDL_FRect DestinationRect =
		{
			GetOwner()->GetActorLocation().X * SizeX,
			GetOwner()->GetActorLocation().Y * SizeY,
			SizeX,
			SizeY
		};
		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, &DestinationRect);
	}
}

void UPaperFlipBookComponent::LoadBMP(std::string Filename)
{
	BitmapImage = SDL_LoadBMP(Filename.c_str());

	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, BitmapImage);
}
