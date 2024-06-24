#pragma once
struct Vector2
{
	Vector2(float xPos, float yPos) :x(xPos), y(yPos) {}

	Vector2 operator+(const Vector2& nVector) const
	{
		return Vector2(x + nVector.x, y + nVector.y);
	}

	Vector2 operator-(const Vector2& nVector) const
	{
		return Vector2(x - nVector.x, y - nVector.y);
	}

	static const Vector2 ZERO;
	static const Vector2 ONE;

private:
	float x;
	float y;

};

const Vector2 Vector2::ZERO = Vector2(0, 0);
const Vector2 Vector2::ONE = Vector2(1, 1);
