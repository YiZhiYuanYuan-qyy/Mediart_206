#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
    pos = glm::vec3(0, 0, 0);
}

ParticleSystem::ParticleSystem(glm::vec3 _pos) {
    pos = _pos;
}

void ParticleSystem::applyForce(glm::vec3 force) {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(int numNewParticles, int maxParticles) {
    for (int i = 0; i < numNewParticles; i++) {
        glm::vec3 vel = glm::vec3(ofRandom(-5,5), ofRandom(-5, 5), ofRandom(-5,5));
        float mass = ofRandom(.01, 1);
        Particle particle = Particle(pos, vel, mass);
        particles.push_back(particle);


    }

    for (int i = 0; i < particles.size(); i++) {
        particles[i].fadeScale = systemFade;
        particles[i].update();
    }

    while (particles.size() > maxParticles) {
        particles.erase(particles.begin());
    }
    lifespan = lifespan - 5;
    if (lifespan < 0) {
        systemFade -= 0.03;
    }

}
void ParticleSystem::draw() {

    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}