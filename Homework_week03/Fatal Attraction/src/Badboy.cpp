#include "Badboy.h"

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
    vel += acc*0.5;
    pos += vel;
    acc *= 0;
    if (pos.x <= 20) {
        pos.x = 20;
        acc = -acc;
        vel = -vel * 0.5;
    }
    if (pos.x >= ofGetWidth() - 20) {
        pos.x = ofGetWidth() - 20;
        acc = -acc;
        vel = -vel * 0.5;
    }
    if (pos.y >= ofGetHeight() - 20) {
        pos.y = ofGetHeight() - 20;
        acc = -acc;
        vel = -vel * 0.5;
    }
    if (pos.y <= 20) {
        pos.y = 20;
        acc = -acc;
        vel = -vel * 0.5;
    }
}

void Particle::draw()
{
    ofPushStyle();
    ofSetColor(180, 82, 205);
    ofDrawCircle(pos, mass * 2.);
    ofPopStyle();
}
void Particle::disapear() {
    mass = 10;

}

