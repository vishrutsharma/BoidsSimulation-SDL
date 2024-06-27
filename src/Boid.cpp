#include "Boid.h"


Boid::Boid(Vector2& initalPos,Uint32 id)
{
	this->id = id;
	this->pos = initalPos;
	this->velocity = Vector2(0,0);
	this->color = Random::GetRandomColor();
}

const Vector2& Boid::GetPos()
{
	return pos;
}

void Boid::Update()
{
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
	SDL_Point vertices[3] = {
		{pos.x,pos.y - BOID_SIZE / 2},
		{pos.x - BOID_SIZE / 2,pos.y + BOID_SIZE / 2},
		{pos.x + BOID_SIZE / 2,pos.y + BOID_SIZE / 2}
	};


	SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
	SDL_RenderDrawLine(renderer, vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y);
	SDL_RenderDrawLine(renderer, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y);
	SDL_RenderDrawLine(renderer, vertices[2].x, vertices[2].y, vertices[0].x, vertices[0].y);
}

bool Boid::operator==(const Boid& b) const
{
	return b.id == this->id;
}