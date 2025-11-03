#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"
class UPaperFlipBookComponent : public USceneComponent
{
public:
	UPaperFlipBookComponent();
	virtual ~UPaperFlipBookComponent();

	virtual void Tick() override;

	virtual void Render() override;

	__forceinline char GetShape()
	{
		return Shape;
	}
	void SetShape(char Value)
	{
		Shape = Value;
	}
	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}

protected:
	char Shape;
	
public:
	SDL_Color Color = { 255, 255, 255, 255 };
	int ZOrder;
};

