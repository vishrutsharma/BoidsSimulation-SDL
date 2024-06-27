#pragma once
struct Vector2
{
	Vector2() :x(0), y(0) {}
	Vector2(float xPos, float yPos) :x(xPos), y(yPos) {}

	Vector2 operator+(const Vector2& nVector) const
	{
		return Vector2(x + nVector.x, y + nVector.y);
	}

	Vector2 operator-(const Vector2& nVector) const
	{
		return Vector2(x - nVector.x, y - nVector.y);
	}

	float x;
	float y;
};
