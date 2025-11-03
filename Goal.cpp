#include "Goal.h"
#include "SDL3/SDL.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

AGoal::AGoal()
{
	//ZOrder = 1000;
	//bIsCollision = false;
	//bIsOverlap = true;
	//Color = { 255,255,0,0 };

	UPaperFlipBookComponent* Paper = new UPaperFlipBookComponent();
	Paper->SetShape('G');
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 255, 255, 0, 0 };
	SetupAttachment(Paper);

	UCollisionComponent* Collision = new UCollisionComponent();
	Collision->bIsCollision = false;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);
}
AGoal::~AGoal()
{
}