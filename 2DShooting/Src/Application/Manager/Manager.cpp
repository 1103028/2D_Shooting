#include "Manager.h"

bool Manager::CircleHit(Math::Vector2 a, float r1, Math::Vector2 b, float r2)
{
    return (a - b).Length() < (r1 + r2);
}

void Manager::ExplosionDraw(Math::Vector2 pos)
{

}
