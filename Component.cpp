#include "Component.h"

UComponent::UComponent()
{
	Owner = nullptr;
}

UComponent::~UComponent()
{
}

AActor* UComponent::GetOwner() const
{
	return Owner;
}

void UComponent::SetOwner(AActor* InOwner)
{
	Owner = InOwner;
}
