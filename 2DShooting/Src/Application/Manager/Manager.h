#pragma once

class Manager
{
public:
	Manager();
	~Manager();

	static bool CircleHit(Math::Vector2 a, float r1,
		Math::Vector2 b, float r2);

	void ExplosionDraw(Math::Vector2 pos);

private:

};