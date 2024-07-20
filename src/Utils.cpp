#include "Utils.h"

namespace Random
{
	double GetRandom(float min, float max)
	{
		float rndNumber = 0;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(min, max);
		double random_value = dis(gen);
		return random_value;
	}

	SDL_Color GetRandomColor()
	{
		SDL_Color color;
		color.r = GetRandom(0, 255);
		color.g = GetRandom(0, 255);
		color.b = GetRandom(0, 255);
		color.a = 255;
		return color;
	}
}


namespace Primitives
{
	namespace Circle
	{
		const int TOTAL_CIRCLE_SEGMENTS = 10;
		

		void DrawCircle(SDL_Renderer* renderer,Vector2& pos,SDL_Color& color,int boidSize)
		{

			float circumGap = M_PI * 2 / TOTAL_CIRCLE_SEGMENTS;
			float currentDegree = 0;
			Vector2 points[TOTAL_CIRCLE_SEGMENTS];

			for (int i = 0; i < TOTAL_CIRCLE_SEGMENTS; i++)
			{
				Vector2 newPos(std::cos(currentDegree) * boidSize / 2, std::sin(currentDegree) * boidSize / 2);
				currentDegree += circumGap;
				points[i] = pos + newPos;
			}

			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
			for (int i = 0; i < TOTAL_CIRCLE_SEGMENTS; i++)
			{
				if (i == 0)
				{
					SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[TOTAL_CIRCLE_SEGMENTS - 1].x, points[TOTAL_CIRCLE_SEGMENTS - 1].y);
				}
				else
				{
					SDL_RenderDrawLine(renderer, points[i].x, points[i].y, points[i - 1].x, points[i - 1].y);
				}
			}
		}
	}
}
