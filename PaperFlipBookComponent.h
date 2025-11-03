#pragma once
#include <string>

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
	float ElapseTime = 0.f;
	
public:
	SDL_Color Color = { 255,255,255,255 };
	int ZOrder;
	SDL_Surface* BitmapImage = nullptr;	// 메모리에 저장
	SDL_Texture* Texture = nullptr;		// GPU메모리에 저장
	SDL_Color ColorKey = { 255,0,255,255 };
	bool bAnimation = false;
	float SpriteCountX = 5.f;
	float SpriteCountY = 5.f;
	float XIndex = 0.f;
	float YIndex = 3.f;

	float AnimationTime = 0.5f;

	int SizeX = 60;
	int SizeY = 60;

	void LoadBMP(std::string Filename);
};

