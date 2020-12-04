#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem {
public:

    ParticleSystem();
    ParticleSystem(glm::vec3 _pos);

    void applyForce(glm::vec3 force);

    void update(int numNewParticles = 50, int maxParticles = 3000);

    void draw();
    glm::vec3 pos;


    vector<Particle> particles;
    float lifespan = 70;
    float systemFade = 1;

};