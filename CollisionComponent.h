#pragma once
#include "ActorComponent.h"

class AActor;

class UCollisionComponent : public UComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void Tick() override;

	//bool CheckCollision(const AActor* InActor, const AActor* OtherActor);

	//virtual void SimulatePhysics();
	bool CheckCollision(const UCollisionComponent* Other);

	bool bIsCollision = false;
	bool bIsOverlap = true;
};

