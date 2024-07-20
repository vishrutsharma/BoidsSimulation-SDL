#pragma once
#include "Boid.h"
#include <vector>

class Behaviour
{
public:
	virtual void Process(Boid&, std::vector<Boid>&,float range,float factor)=0;
};