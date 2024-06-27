#pragma once
#include "Vector2.h"
#include "SDL.h"
#include "Utils.h"

const int BOID_SIZE = 10;

class Boid
{
public:
	Boid(Vector2& initialPos,Uint32);
	void Update();
	void Render(SDL_Renderer*);
	const Vector2& GetPos();
	const Vector2& GetVelocity();
	void AddVelocity(Vector2 vel);
	void EnforceSpeedLimit();
	void StayInBounds();
	bool operator==(const Boid&) const;
	
private:
		Uint32 id;
		Vector2 pos;
		Vector2 velocity;	
		SDL_Color color;
};
