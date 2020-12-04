#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
    pos = glm::vec2(0, 0);
}

ParticleSystem::ParticleSystem(glm::vec2 _pos) {
    pos = _pos;
}

void ParticleSystem::applyForce(glm::vec2 force) {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(int numNewParticles, int maxParticles) {
    for (int i = 0; i < numNewParticles; i++) {
        glm::vec2 vel = glm::vec2(ofRandom(-3,3), ofRandom(-5, 1));
        float mass = ofRandom(.01, 7);
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
    lifespan--;
    if (lifespan < 0) {
        systemFade -= 0.03;
    }

}
void ParticleSystem::draw() {

    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}