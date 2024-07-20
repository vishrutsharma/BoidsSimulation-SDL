#include "Boid.h"
#include <iostream>
#include <cmath>

Boid::Boid(Vector2& initalPos,Uint32 id,Uint32 biasIndex)
{
	this->id = id;
	this->pos = initalPos;
	this->velocity = Vector2(0,0);
	this->color = Random::GetRandomColor();
	this->biasIndex = biasIndex;
	this->biasVal = 0.001;
}

const Vector2& Boid::GetPos()
{
	return pos;
}

void Boid::Update(int& minSpeed,int& maxSpeed,float& turnFactor,float& biasIncrement,float& maxBias)
{
	//CheckRegion();
	//UpdateBias();
	//UpdateSpeed();

	//Check for region
	
	if (pos.x < 0)
		velocity.x = velocity.x + turnFactor;
	if (pos.x > 1000)
		velocity.x = velocity.x - turnFactor;
	if (pos.y < 0)
		velocity.y = velocity.y + turnFactor;
	if (pos.y > 800)
		velocity.y = velocity.y - turnFactor;

	//Update Bias
	if (biasIndex == 0) {
		if (velocity.x > 0) {
			biasVal = std::min(maxBias, biasVal + biasIncrement);
		}
		else {
			biasVal = std::max(biasIncrement, biasVal - biasIncrement);
		}
	}
	else
	{
		if (velocity.x < 0) {
			biasVal = std::min(maxBias, biasVal + biasIncrement);
		}
		else {
			biasVal = std::max(biasIncrement, biasVal - biasIncrement);
		}
	}
		

	if (biasIndex == 0) {
		velocity.x = (1 - biasVal) * velocity.x + (biasVal * 1);
	}
	else
	{
		velocity.x = (1 - biasVal) * velocity.x+(biasVal * (-1));
	}
	
	//Check for Speed
	float magnitude = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
	if (magnitude < minSpeed)
	{
		velocity.x = (velocity.x / magnitude) * minSpeed ;
		velocity.y = (velocity.y / magnitude) * minSpeed ;
	}
	else if (magnitude > maxSpeed)
	{
		velocity.x = (velocity.x / magnitude) * maxSpeed ;
		velocity.y = (velocity.y / magnitude) * maxSpeed ;
	}


	pos = pos + GetVelocity();
}

const Vector2& Boid:: GetVelocity()
{
	return velocity;
}

void Boid::AddVelocity(Vector2 newVelocity)
{
	velocity = velocity + newVelocity;
}

void Boid::Render(SDL_Renderer* renderer)
{
	Primitives::Circle::DrawCircle(renderer,pos, color,BOID_SIZE);
}

bool Boid::operator==(const Boid& b) const
{
	return b.id == this->id;
}