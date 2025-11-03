#include "Actor.h"
#include "Component.h"

AActor::AActor() : Location(0, 0)
{
}
AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
}

void AActor::Tick()
{
}
void AActor::ActorBeginOverlap()
{
}
void AActor::Hit()
{
}
void AActor::SetupAttachment(UComponent* InComponent)
{
	InComponent->SetOwner(this);
	Components.push_back(InComponent);
}