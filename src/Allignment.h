#pragma once
#include "Behaviour.h"

class Allignment : public Behaviour
{
public:
	Allignment();
	void Process(Boid&, std::vector<Boid>&, float range, float factor) override;
};