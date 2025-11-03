#pragma once

#include "SDL3/SDL.h"
#include "Input.h"

#pragma comment(lib, "SDL3")

class UWorld;
class UTimer;
class UInput;

class FEngine
{
protected:
	FEngine();

public:
	virtual ~FEngine();

	virtual void Init();
	virtual void Run();
	virtual void Term();

	void OpenLevel();

	__forceinline UWorld* GetWorld() const
	{
		return World;
	}
	__forceinline int GetKeyCode() const
	{
		return UInput::KeyCode;
	}

protected:
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool bIsRunning = true;

	//int KeyCode = 0;

//ΩÃ±€≈Ê
public:
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine;
		}
		return Instance;
	}

	double GetWorldDeltaSeconds() const;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

protected:
	static FEngine* Instance;

	class UInput* InputDevice = nullptr;
	class UTimer* Timer = nullptr;
};

//extern FEngine* GEngine;

#define GEngine FEngine::GetInstance()