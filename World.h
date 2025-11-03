#pragma once

#include <vector>

#include "Actor.h"

//전방선언
class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	virtual void Tick();
	virtual void Render();

	//virtual void SimulatePhysics();

	void GetAllActors(std::vector<AActor*>& OutActors) const;
	AActor* SpawnActor(AActor* NewActor);
	void SortActor();
protected:
	std::vector<AActor*> Actors;
};