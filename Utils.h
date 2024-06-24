#pragma once
#include <random>

class RandomNumberGenerator
{
public:
	static double GetRandom(float min, float max)
	{
		float rndNumber = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        double random_value = dis(gen);
		return random_value;
	}
};