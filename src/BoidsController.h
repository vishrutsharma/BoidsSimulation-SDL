#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "Boid.h"
#include "Utils.h"
#include "BoidsBehaviour.h"

const int BOIDS_LENGTH = 500;

class BoidsController
{

public:
	BoidsController();
	void Initialise();
	void Update(SDL_Renderer*);
	void SetTarget(int xScreenPos,int yScreenPos);

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
		std::vector<Boid> boids;	
		BoidsBehaviour boidsBehaviour;
};