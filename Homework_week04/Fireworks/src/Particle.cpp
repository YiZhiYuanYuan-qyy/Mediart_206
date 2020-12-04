#include "Particle.h"
#include "Firework.h"


Particle::Particle() {

    pos = glm::vec3(0, 0,0);
    vel = glm::vec3(0, 0,0);
    acc = glm::vec3(0, 0,0);

}

Particle::Particle(glm::vec3 _pos, glm::vec3 _vel, float _mass) {
    pos = _pos;
    vel = _vel;
    mass = _mass;
    fade = 255;
}

void Particle::applyForce(glm::vec3 force) {
    acc += force/ mass ;
    float time = ofGetElapsedTimef();
    glm::vec3 level(0, -0.01, 0);
    acc = level + acc;
}

void Particle::update() {

    pos += vel;
    vel += acc;
    acc *= 0;
}
void Particle::draw() {
    ofPushStyle();
    ofEnableAlphaBlending();
    ofSetColor(ofRandom(100, 255), ofRandom(100, 255), ofRandom(100, 255), fadeScale * fade);
    ofDrawSphere(pos, mass);
    //ofDisableAlphaBlending();
    ofPopStyle();

}
