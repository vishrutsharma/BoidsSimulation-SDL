#pragma once

#include <random>
#include <SDL.h>
#include "Vector2.h"

namespace Random
{
	double GetRandom(float min, float max);
	SDL_Color GetRandomColor();
};

namespace Primitives
{
	namespace Circle
	{
		extern const int TOTAL_CIRCLE_SEGMENTS;
		void DrawCircle(SDL_Renderer* renderer, Vector2& pos, SDL_Color& color, int size);

	}
};
