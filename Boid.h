#pragma once
#include "Vector2.h"

class Boid
{
public:
	Boid(Vector2& initialPos);
	void Update();
	void Render();
	const Vector2& GetPos();
	
private:
		Vector2 pos;
		Vector2 velocity;		
};
