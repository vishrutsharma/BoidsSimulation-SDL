#include "BoidsController.h"
#include "Seperation.h"
#include "Allignment.h"
#include "Cohesion.h"

BoidsController::BoidsController() :
	turnFactor(0.6),
	visualRange(70),
	protectedRange(20),
	centeringFactor(0.0005),
	avoidFactor(0.6),
	matchingFactor(0.05),
	maxSpeed(6),
	minSpeed(3),
	maxBias(0.01),
	biasIncrement(0.00004){}

void BoidsController::Initialise()
{
	cohesion = new Cohesion();
	allignment = new Allignment();
	seperation = new Seperation();

	for (int i = 0; i < BOIDS_LENGTH; i++)
	{ 
		float rndX = static_cast<float>(Random::GetRandom(0, 1000));
		float rndY = static_cast<float>(Random::GetRandom(0, 800));
		Vector2 rndPos(rndX, rndY);
		int biasIndex = i > BOIDS_LENGTH / 2 ? 1 : 0;
		Boid boid(rndPos, static_cast<Uint32>(i),static_cast<Uint32>(biasIndex));
		boids.push_back(boid);
	}
}

void BoidsController::Update(SDL_Renderer* mRenderer)
{
	if (boids.size() < 0)
	{
		std::cerr << "No Boids Exist" << std::endl;
		return;
	}
	
	for (Boid& boid : boids)
	{
		seperation->Process(boid, boids, protectedRange, avoidFactor);
		allignment->Process(boid, boids, visualRange, matchingFactor);
		cohesion->Process(boid, boids,visualRange,centeringFactor);
		boid.Update(minSpeed,maxSpeed,turnFactor,biasIncrement,maxBias);
		boid.Render(mRenderer);
	}
}

void BoidsController::SetTarget(int xScreenPos, int yScreenPos)
{
	//std::cout << "X:" << xScreenPos << " Y:" << yScreenPos << std::endl;
}

