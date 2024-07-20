#include "Behaviour.h"
#include "Cohesion.h"

Cohesion::Cohesion() {}

void Cohesion::Process(Boid& boid, std::vector<Boid>& boids, float range, float factor)
{
    float xpos_avg = 0, ypos_avg = 0;
    int neighboring_boids = 0;
    for (Boid& otherboid : boids) {
        float dx = boid.GetPos().x - otherboid.GetPos().x;
        float dy = boid.GetPos().y - otherboid.GetPos().y;
        if (std::abs(dx) < range && std::abs(dy) < range) {  
            float squared_distance = dx * dx + dy * dy;
            if (squared_distance < range && squared_distance > 0) {  
                xpos_avg += otherboid.GetPos().x;
                ypos_avg += otherboid.GetPos().y;
                neighboring_boids++;
            }
        }
    }
    if (neighboring_boids > 0) {
        xpos_avg /= neighboring_boids;
        ypos_avg /= neighboring_boids;
        boid.AddVelocity(Vector2(xpos_avg - boid.GetPos().x, ypos_avg - boid.GetPos().y));
    }
   
}
