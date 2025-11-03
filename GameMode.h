#pragma once
#include <vector>

#include "Actor.h"
#include "Engine.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"

class AGameMode : public AActor
{
public:
	AGameMode();
	virtual ~AGameMode();

	virtual void Tick() override;
};

