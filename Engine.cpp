#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>

#include "World.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "GameMode.h"
#include "Timer.h"
#include "Input.h"

//FEngine* GEngine = nullptr;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine() : World(nullptr), MyEvent(SDL_Event())
{
	MyWindow = nullptr;
	MyRenderer = nullptr;
	Timer = new UTimer();
	InputDevice = new UInput();
}
FEngine::~FEngine()
{
	if (InputDevice)
	{
		delete InputDevice;
	}
	if (Timer)
	{
		delete Timer;
	}
	if (World)
	{
		delete World;
	}
}

void FEngine::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	MyWindow = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
}
void FEngine::OpenLevel()
{
	srand((unsigned int)time(nullptr));
	World = new UWorld;

	std::ifstream MapFile("Level01.map");

	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 80))
		{
			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}

				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}
	}
	//1.
	//std::sort(World->GetAllActors().begin(),
	//	World->GetAllActors().end(),
	//	[](const AActor* A, const AActor* B) {
	//		return A->GetZOrder() > B->GetZOrder();
	//	});
	//2. 정렬 로직 구현
	//selection sort
	World->SortActor();

	MapFile.close();

	//UE Gameplay Framework
	World->SpawnActor(new AGameMode());
}
void FEngine::Run()
{
	while (bIsRunning)
	{
		Timer->Tick();

		if (SDL_PollEvent(&MyEvent))
		{
			switch (MyEvent.type)
			{
			case SDL_QUIT:
				bIsRunning = false;
				break;
			}
		}
		Input();
		Tick();
		Render();
	}
}
void FEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
}
void FEngine::Input()
{
	InputDevice->Tick();
	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
}
void FEngine::Tick()
{
	GetWorld()->Tick();
}
inline void FEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
	SDL_RenderClear(MyRenderer);

	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}
double FEngine::GetWorldDeltaSeconds() const
{
	return Timer->DeltaSeconds;
}