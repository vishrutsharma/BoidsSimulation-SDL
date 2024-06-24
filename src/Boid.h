#pragma once
#include "Vector2.h"
#include "SDL.h"
#include "Utils.h"

class Boid
{
public:
	Boid(Vector2& initialPos);
	void Update();
	void Render(SDL_Renderer*);
	const Vector2& GetPos();
	
private:
		Vector2 pos;
		Vector2 velocity;	
		SDL_Color color;
};
