#include "pallbearers.h"


Pall::Pall()
{
    pos = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    vel = glm::vec2(0, 0);
    acc = glm::vec2(0, 0);
    pallbox.load("Pall.png");
}

Pall::Pall(glm::vec2 _pos) :Pall()
{
    pos = glm::vec2(ofGetWidth() - 500, ofGetHeight() - 200);
    acc = glm::vec2(0, 0);
}
void Pall::applyForce(glm::vec2 force){
    acc = force;

}
void Pall::update()
{
    pos += acc;
}

void Pall::draw()
{
    pallbox.draw(pos,600,400);
}
