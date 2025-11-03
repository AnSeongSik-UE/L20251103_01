#pragma once
#include "Component.h"

class UActorComponent : public UComponent
{
public:
	UActorComponent();
	virtual ~UActorComponent();

	virtual void Tick() override;
};