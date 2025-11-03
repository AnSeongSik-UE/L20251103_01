#include "GameMode.h"


AGameMode::AGameMode()
{
}
AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	AActor* Player = nullptr;

	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);
	for (auto Actor : AllActors)
	{
		if (dynamic_cast<APlayer*>(Actor))
		{
			Player = dynamic_cast<APlayer*>(Actor);
			break;
		}
	}

	for (auto Actor : AllActors)
	{
		if (dynamic_cast<AMonster*>(Actor))
		{
			if (Player->GetActorLocation() == Actor->GetActorLocation())
			{
				//Game Over
				//exit(-1);
				break;
			}
		}
	}

	for (auto Actor : AllActors)
	{
		if (dynamic_cast<AGoal*>(Actor))
		{
			if (Player->GetActorLocation() == Actor->GetActorLocation())
			{
				//Complete
				//exit(-1);
				break;
			}
		}
	}
	//SDL_Log("DeltaSeconds : %f\n", GEngine->GetWorldDeltaSeconds());
}