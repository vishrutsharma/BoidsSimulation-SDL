#include "Behaviour.h"
#include "Allignment.h"

Allignment::Allignment() {}

void Allignment::Process(Boid& boid,std::vector<Boid>& boids,float range,float factor)
{
    float xvel_avg = 0, yvel_avg = 0;
    int neighboring_boids = 0;
    for (Boid& otherboid : boids) {
        float dx = boid.GetPos().x - otherboid.GetPos().x;
        float dy = boid.GetPos().y - otherboid.GetPos().y;
        if (std::abs(dx) < range && std::abs(dy) < range) {  
            float squared_distance = dx * dx + dy * dy;
            if (squared_distance < range*range && squared_distance > 0) {  
                xvel_avg += otherboid.GetVelocity().x;
                yvel_avg += otherboid.GetVelocity().y;
                neighboring_boids++;
            }
        }
    }
    if (neighboring_boids > 0) {
        xvel_avg /= neighboring_boids;
        yvel_avg /= neighboring_boids;
        boid.AddVelocity(Vector2(xvel_avg - boid.GetVelocity().x * factor, yvel_avg - boid.GetVelocity().y * factor));
    }
}