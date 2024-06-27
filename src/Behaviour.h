#pragma once
#include "Boid.h"
#include <vector>

class Behaviour
{
public:
	virtual void Process(Boid& boid, std::vector<Boid>& boids,)=0;
};