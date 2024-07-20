#include "Behaviour.h"
#include "Seperation.h"

Seperation::Seperation() {}

void Seperation::Process(Boid& boid, std::vector<Boid>& boids, float range, float factor)
{
    float close_dx = 0, close_dy = 0;
    for ( Boid& otherboid : boids) {
        if (otherboid == boid) 
            continue;

        float dx = boid.GetPos().x - otherboid.GetPos().x;
        float dy = boid.GetPos().y - otherboid.GetPos().y;
        float squared_distance = dx * dx + dy * dy;
        if (squared_distance < range*range && squared_distance > 0) {
            close_dx += dx;
            close_dy += dy;
        }
    }
    boid.AddVelocity(Vector2(close_dx*factor, close_dy*factor)); 
}