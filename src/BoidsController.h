#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "Boid.h"
#include "Utils.h"
#include "Behaviour.h"

const int BOIDS_LENGTH = 500;

class BoidsController
{

public:
	BoidsController();
	void Initialise();
	void Update(SDL_Renderer*);
	void SetTarget(int xScreenPos,int yScreenPos);

private:		
		 float turnFactor;
		 float visualRange;
		 float protectedRange;
		 float centeringFactor;
		 float avoidFactor;
		 float matchingFactor;
		 int maxSpeed;
		 int minSpeed;
		 float maxBias;
		 float biasIncrement;
		std::vector<Boid> boids;	
		Behaviour* allignment;
		Behaviour* seperation;
		Behaviour* cohesion;
};