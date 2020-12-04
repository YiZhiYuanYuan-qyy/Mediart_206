#include "Particle.h"

Particle::Particle()
{
    pos = glm::vec2(0, 0);
    vel = glm::vec2(0, 0);
    acc = glm::vec2(0, 0);
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    pos = _pos;
    vel = _vel;
    mass = _mass;
}

void Particle::addForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::addDampingForce(float strength)
{
    float length = glm::length(vel);
    if (length != 0) {                      
        acc -= vel / length * strength;   
    }
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw()
{
    ofPushStyle();
    float hue = ofMap(mass, 0, 10, 0, 255);
    ofSetColor(250, 128, 114);
    ofDrawCircle(pos, mass * 2.);
    ofPopStyle();
}
//void Particle::x() {
//
//}

