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

	//UPaperFlipBookComponent* Paper = new UPaperFlipBookComponent();
	Flipbook = new UPaperFlipBookComponent();
	Flipbook->SetShape('G');
	Flipbook->ZOrder = 1000;
	Flipbook->Color = SDL_Color{ 255, 255, 0, 0 };
	SetupAttachment(Flipbook);

	UCollisionComponent* Collision = new UCollisionComponent();
	Collision->bIsCollision = false;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);
}
AGoal::~AGoal()
{
}