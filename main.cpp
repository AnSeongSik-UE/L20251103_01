#include "Engine.h"
#include "SDL3/SDL_main.h"
#include "Component.h"

//C++ console entry -> iOS, Window, Linux
//int main(int argc, char* argv[])
//{
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	return 0;
}