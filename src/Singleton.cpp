#include "Singleton.h"
#include <iostream>

Singleton Singleton::instance;
Singleton::Singleton():currentTime(0),deltaTime(0), previousTime(SDL_GetTicks()) {};

float Singleton::GetDeltaTime()
{
	return instance.deltaTime;
}

Singleton& Singleton::GetInstance()
{
	return instance;
}

void Singleton::Update()
{
	instance.currentTime = SDL_GetTicks();
	instance.deltaTime =  (instance.currentTime - instance.previousTime)/1000.0f;
	instance.previousTime = instance.currentTime;
}