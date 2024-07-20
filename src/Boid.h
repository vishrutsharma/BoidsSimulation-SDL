#pragma once
#include "Vector2.h"
#include "SDL.h"
#include "Utils.h"

const int BOID_SIZE = 5;

class Boid
{
public:
	Boid(Vector2& initialPos,Uint32,Uint32);
	void Update(int&,int&,float&,float&,float&);
	void Render(SDL_Renderer*);
	const Vector2& GetPos();
	const Vector2& GetVelocity();
	void AddVelocity(Vector2 vel);
	bool operator==(const Boid&) const;
	
private:
		Uint32 id;
		Vector2 pos;
		Vector2 velocity;	
		SDL_Color color;
		Uint32 biasIndex;
		float biasVal;
		//void CheckRegion();
		//void UpdateBias();
		//void UpdateSpeed();

};
