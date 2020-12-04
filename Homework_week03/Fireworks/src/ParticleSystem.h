#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem {
public:

    ParticleSystem();
    ParticleSystem(glm::vec2 _pos);

    void applyForce(glm::vec2 force);

    void update(int numNewParticles = 10, int maxParticles = 1000);

    void draw();
    glm::vec2 pos;


    vector<Particle> particles;
    float lifespan = 50;
    float systemFade = 1;

};