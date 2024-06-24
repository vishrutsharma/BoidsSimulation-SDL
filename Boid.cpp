#include "Boid.h"

Boid::Boid(Vector2& initalPos)
{
	this->pos = initalPos;
	this->velocity = Vector2::ZERO;
}