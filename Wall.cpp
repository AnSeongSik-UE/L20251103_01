#include "Wall.h"
#include "SDL3/SDL.h"
#include "PaperFlipBookComponent.h"
#include "CollisionComponent.h"

AWall::AWall()
{
	//ZOrder = 1000;
	//bIsCollision = true;
	//bIsOverlap = false;
	//Color = { 128,128,128,0 };

	UPaperFlipBookComponent* Paper = new UPaperFlipBookComponent();
	Paper->SetShape('*');
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	SetupAttachment(Paper);

	UCollisionComponent* Collision = new UCollisionComponent();
	Collision->bIsCollision = true;
	Collision->bIsOverlap = false;
	SetupAttachment(Collision);
}
AWall::~AWall()
{
}