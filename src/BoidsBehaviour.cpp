#include "BoidsBehaviour.h"
#include "Seperation.h"
#include "Allignment.h"
#include "Cohesion.h"
#include <iostream>

BoidsBehaviour::BoidsBehaviour()
{
	std::cout << "Boids Behaviour..." << std::endl;
	behaviours.push_back(new Cohesion());
	behaviours.push_back(new Seperation());
	behaviours.push_back(new Allignment());
}