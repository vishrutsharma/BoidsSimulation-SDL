#pragma once
#include <random>
#include <SDL.h>
#include <cstdlib>

namespace Random
{
	double GetRandom(float min, float max)
	{
		float rndNumber = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        double random_value = dis(gen);
		return random_value;
	}

	SDL_Color GetRandomColor()
	{
		SDL_Color color;
		color.r = GetRandom(0, 255);
		color.g = GetRandom(0, 255);
		color.b = GetRandom(0, 255);
		color.a = 255;
		return color;
	}
};

namespace PrimitiveShapes
{
	void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
		for (int angle = 0; angle < 360; angle++) {
			int x = static_cast<int>(centerX + radius * cos(angle * M_PI / 180.0));
			int y = static_cast<int>(centerY + radius * sin(angle * M_PI / 180.0));

			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red color
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}
