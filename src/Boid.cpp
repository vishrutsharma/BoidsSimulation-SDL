#include "Boid.h"


Boid::Boid(Vector2& initalPos)
{
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

}

void Boid::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
	SDL_RenderDrawPoint(renderer, pos.x,pos.y);
}