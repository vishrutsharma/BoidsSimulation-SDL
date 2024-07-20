#pragma once
#include <SDL.h>

class Singleton
{
public:

	static Singleton& GetInstance();
	static void Update();
	static float GetDeltaTime();
	
private:
	Singleton();
	static Singleton instance;
	float deltaTime;
	Uint32 previousTime;
	Uint32 currentTime;
};