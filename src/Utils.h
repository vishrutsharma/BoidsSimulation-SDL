#pragma once
#include <random>
#include <SDL.h>
#include <cstdlib>

namespace Random
{
	double GetRandom(float min, float max);
	SDL_Color GetRandomColor();
};