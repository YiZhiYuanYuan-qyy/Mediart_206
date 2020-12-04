#include "Particle.h"
#include "Firework.h"


Particle::Particle() {

    pos = glm::vec2(0, 0);
    vel = glm::vec2(0, 0);
    acc = glm::vec2(0, 0);

}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass) {
    pos = _pos;
    vel = _vel;
    mass = _mass;
    fade = 255;
}

void Particle::applyForce(glm::vec2 force) {
    acc += force/ mass ;
    float time = ofGetElapsedTimef();
    glm::vec2 level(0,0.05);
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
    ofDrawCircle(pos, mass * 2);
    //ofDisableAlphaBlending();
    ofPopStyle();
    //ofPushStyle();
    //float hue = ofMap(mass, 0, 5, 0, 255);
    //float sat = 255;
    //float brt = 255;
    //float bornTime = ofGetElapsedTimef();
    //float aliveTime = ofGetElapsedTimef() - bornTime;
    //float alpha = ofMap(aliveTime, 0, 2, 255, 0, true);

    //ofColor color = ofColor::fromHsb(hue, sat, brt, alpha);
    //ofSetColor(color);

    //ofDrawCircle(pos, mass * 0.7);
    //ofPopStyle();

}
