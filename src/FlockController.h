#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "Boid.h"

const int BOIDS_LENGTH = 500;

class FlockController
{

public:
	FlockController();
	void Initialise();
	void Update(SDL_Renderer*);

private:		
		const float turnFactor;
		const float visualRange;
		const float protectedRange;
		const float centeringFactor;
		const float avoidFactor;
		const float matchingFactor;
		const float maxSpeed;
		const float minSpeed;
		const float maxBias;
		const float biasIncrement;
		std::vector<Boid*> boids;	
};