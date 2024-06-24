#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "Boid.h"

class Boid;
const int BOIDS_LENGTH = 2;

class FlockController
{

public:
	FlockController();
	void Initialise();
	void Update(const SDL_Renderer*);
	void Render(const SDL_Renderer*);
	~FlockController();

private:		
		float turnFactor;
		float visualRange;
		float protectedRange;
		float centeringFactor;
		float avoidFactor;
		float matchingFactor;
		float maxSpeed;
		float minSpeed;
		float maxBias;
		float biasIncrement;
		std::vector<Boid*> boids;	
};