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
		float rndX = RandomNumberGenerator::GetRandom(0, 1080);
		float rndY = RandomNumberGenerator::GetRandom(0, 900);
		Vector2 rndPos(rndX, rndY);
		Boid* boid = new Boid(rndPos);
		boids.push_back(boid);
	}
}

void FlockController::Update(const SDL_Renderer* mRenderer)
{
	
}

void FlockController::Render(const SDL_Renderer* mRenderer)
{
	for (Boid* boid : boids)
	{

	}
}

