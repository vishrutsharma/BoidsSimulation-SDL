#pragma once

#include <vector>
#include "Behaviour.h"

class BoidsBehaviour
{

public:
	BoidsBehaviour();

private:
	std::vector<Behaviour*> behaviours;
};