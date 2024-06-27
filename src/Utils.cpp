#include "Utils.h"

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