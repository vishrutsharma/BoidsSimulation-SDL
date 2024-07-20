#pragma once
#include "Behaviour.h"

class Seperation : public Behaviour
{
public:
	Seperation();
	void Process(Boid&, std::vector<Boid>&, float range, float factor) override;
};