#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>

#include "Vector.h"
#include "Engine.h"

class UComponent;

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();

	//inline은 해당 코드 자체를 불러와서 빠름
	//inline은 컴파일러가 더 좋은 방안을 생각함
	//__force로 생각없이 바로 처리하도록 강제함 / 비주얼스튜디오용
	//const는 해당 함수 내에서 값 변경을 막음
	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	template<typename T>
	T* GetComponent()
	{
		for (auto Component : Components)
		{
			if (dynamic_cast<T*>(Component))
			{
				return dynamic_cast<T*>(Component);
			}
		}
		return nullptr;
	}

	void SetActorLocation(FVector2D Value)
	{
		//Location = Value; //복사생성자 동작할수도 안할수도 있음
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	virtual void ActorBeginOverlap();
	virtual void Hit();

	void SetupAttachment(UComponent* InComponent);

	std::vector<class UComponent*> Components;

protected:
	FVector2D Location;
};