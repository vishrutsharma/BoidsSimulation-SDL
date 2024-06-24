#include "FlockController.h"
#include "Utils.h"

FlockController::FlockController() :
	turnFactor(0.2),
	visualRange(40),
	protectedRange(8),
	centeringFactor(0.0005),
	avoidFactor(0.05),
	matchingFactor(0.05),
	maxSpeed(6),
	minSpeed(3),
	maxBias(3),
	biasIncrement(0.0004){}

void FlockController::Initialise()
{
	for (int i = 0; i < BOIDS_LENGTH; i++)
	{ 
		float rndX = static_cast<float>(Random::GetRandom(0, 1080));
		float rndY = static_cast<float>(Random::GetRandom(0, 900));
		Vector2 rndPos(rndX, rndY);
		Boid* boid = new Boid(rndPos);
		boids.push_back(boid);
	}
}

void FlockController::Update(SDL_Renderer* mRenderer)
{
	if (boids.size() < 0)
	{
		std::cerr << "No Boids Exist" << std::endl;
		return;
	}

	for (Boid* boid : boids)
	{
		boid->Update();
		boid->Render(mRenderer);
	}
}

