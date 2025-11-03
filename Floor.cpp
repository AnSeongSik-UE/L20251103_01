#include "Floor.h"
#include "SDL3/SDL.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

AFloor::AFloor()
{
	//ZOrder = 0;
	//bIsCollision = false;
	//bIsOverlap = false;
	//Color = { 0,0,0,0 };

	UPaperFlipBookComponent* Paper = new UPaperFlipBookComponent();
	Paper->SetShape(' ');
	Paper->ZOrder = 0;
	Paper->Color = SDL_Color{ 0, 0, 0, 0 };
	SetupAttachment(Paper);

	UCollisionComponent* Collision = new UCollisionComponent();
	Collision->bIsCollision = false;
	Collision->bIsOverlap = false;
	SetupAttachment(Collision);
}
AFloor::~AFloor()
{
}