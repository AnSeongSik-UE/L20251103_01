#include "Monster.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

AMonster::AMonster()
{
	//ZOrder = 1001;
	//bIsCollision = true;
	//bIsOverlap = true;
	//Color = { 0,0,255,0 };

	UPaperFlipBookComponent* Paper = new UPaperFlipBookComponent();
	Paper->SetShape('M');
	Paper->ZOrder = 1001;
	Paper->Color = SDL_Color{ 0, 0, 255, 0 };
	SetupAttachment(Paper);

	Collision = new UCollisionComponent();
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);
}
AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	TotalTime += (float)GEngine->GetWorldDeltaSeconds();
	if (TotalTime <= ExecuteTime)
	{
		return;
	}
	TotalTime = 0.f;

	int KeyCode = rand() % 4;
	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == 0)
	{
		Location.Y--;
	}
	else if (KeyCode == 1)
	{
		Location.Y++;
	}
	else if (KeyCode == 2)
	{
		Location.X--;
	}
	else if (KeyCode == 3)
	{
		Location.X++;
	}

	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		UCollisionComponent* OtherCollision = OtherActor->GetComponent<UCollisionComponent>();
		if (OtherCollision)
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
