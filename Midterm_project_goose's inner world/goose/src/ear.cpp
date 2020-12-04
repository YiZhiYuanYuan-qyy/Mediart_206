#include "ear.h"


Ear::Ear()
{
    pos = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
    vel = glm::vec2(0, 0);
    acc = glm::vec2(0, 0);
    ear.load("EAR.png");
}

Ear::Ear(glm::vec2 _pos) :Ear()
{
    pos = glm::vec2(ofGetWidth() - 500, ofGetHeight() - 200);
    acc = glm::vec2(0, 0);
}

void Ear::applyForce(glm::vec2 force)
{
    acc = force;
}
void Ear::update(glm::vec2 pos_)
{
    pos = pos_;
}

void Ear::draw(float x, float y)
{
    ear.draw(x, y, 400, 300);
}
