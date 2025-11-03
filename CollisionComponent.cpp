#include "CollisionComponent.h"
#include "Actor.h"

UCollisionComponent::UCollisionComponent()
{
}
UCollisionComponent::~UCollisionComponent()
{
}

void UCollisionComponent::Tick()
{
}

bool UCollisionComponent::CheckCollision(const UCollisionComponent* Other)
{
	if (Other->bIsOverlap)
	{
		return false;
	}
	if (this != Other && Other->bIsCollision && bIsCollision &&
		this->GetOwner()->GetActorLocation() == Other->GetOwner()->GetActorLocation())//영역 계산
	{
		return true;
	}
	return false;
}

//bool UCollisionComponent::CheckCollision(const AActor* InActor, const AActor* OtherActor)
//{
//	UCollisionComponent* Collision1 = nullptr;
//	for (auto Component : InActor->Components)
//	{
//		Collision1 = dynamic_cast<UCollisionComponent*>(Component);
//		if (!Collision1)
//		{
//			return false;
//		}
//		for (auto Component : OtherActor->Components)
//		{
//			UCollisionComponent* Collision2 = dynamic_cast<UCollisionComponent*>(Component);
//			if (Collision2)
//			{
//				if (Collision2->bIsOverlap)
//				{
//					return false;
//				}
//				if (InActor != OtherActor && Collision1->bIsCollision && Collision2->bIsCollision &&
//					InActor->GetActorLocation() == OtherActor->GetActorLocation()) //영역 계산
//				{
//					return true;
//				}
//			}
//		}
//	}
//
//	return false;
//}