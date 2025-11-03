#include <iostream>
#include <vector>

#include "Player.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

APlayer::APlayer()
{
	//ZOrder = 1003;
	//bIsCollision = true;
	//bIsOverlap = true;
	//Color = { 255,0,0,0 };

	Flipbook = new UPaperFlipBookComponent();
	Flipbook->SetShape('P');
	Flipbook->ZOrder = 1003;
	Flipbook->Color = SDL_Color{ 255, 0, 0, 255 };
	Flipbook->bAnimation = true;
	SetupAttachment(Flipbook);

	Collision = new UCollisionComponent();
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);
}
APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == SDLK_w || KeyCode == SDLK_UP)
	{
		Location.Y--;
		Flipbook->YIndex = 2.f;
	}
	if(KeyCode == SDLK_s || KeyCode == SDLK_DOWN)
	{
		Location.Y++;
		Flipbook->YIndex = 3.f;
	}
	if (KeyCode == SDLK_a || KeyCode == SDLK_LEFT)
	{
		Location.X--;
		Flipbook->YIndex = 0.f;
	}
	if (KeyCode == SDLK_d || KeyCode == SDLK_RIGHT)
	{
		Location.X++;
		Flipbook->YIndex = 1.f;
	}

	if (KeyCode == SDLK_ESCAPE)
	{
		exit(-1);
	}

	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		UCollisionComponent* OtherCollision = OtherActor->GetComponent<UCollisionComponent>();
		if(OtherCollision)
		{
			if (Collision->CheckCollision(OtherCollision))
			{
				bFlag = true;
				break;
			}
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}