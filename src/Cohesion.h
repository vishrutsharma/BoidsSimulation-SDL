#pragma once
#include "Behaviour.h"

class Cohesion : public Behaviour
{
public:
	Cohesion();
	void Process(Boid&, std::vector<Boid>&, float range, float factor) override;
};