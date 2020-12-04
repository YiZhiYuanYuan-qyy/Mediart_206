
#include "Planet.hpp"

Planet::Planet()
{
    
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
    bornTime = ofGetElapsedTimef();
}

Planet::Planet(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    pos = _pos;
    vel = _vel;
    mass = _mass;
    
    bornTime = ofGetElapsedTimef();
}

void Planet::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Planet::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
    
}

void Planet::draw()
{
    ofPushStyle();
    float hue = ofMap(mass,230,235,250,250);
    float sat = ofMap(mass, 235, 240, 250, 255);
    float brt = 205;
    
    float aliveTime = ofGetElapsedTimef() - bornTime;
    float alpha = ofMap(aliveTime, 0, 2, 255, 0, true);
    
    ofColor color = ofColor::fromHsb(hue,sat,brt,alpha);
    ofSetColor(color);
    
    ofDrawCircle(pos, mass * 2.0);
    ofPopStyle();
}

