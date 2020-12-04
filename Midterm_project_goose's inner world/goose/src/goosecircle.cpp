#include "goosecircle.h"


Goosecircle::Goosecircle()
{

    origPos = glm::vec2(0, 0);
    pos = glm::vec2(0, 0);
    vel = glm::vec2(0, 0);
    acc = glm::vec2(0, 0);
    goose1.load("GOOSE.png");
    goose2.load("GOOSE_.png");

    mass = 2;
}

Goosecircle::Goosecircle(glm::vec2 _pos):Goosecircle()
{

    origPos = move(_pos);
    pos = origPos;
    vel = glm::vec2(0, 0);
    acc = glm::vec2(0, 0);
    mass = 2;

}

void Goosecircle::applyForce(glm::vec2 force)
{
    acc += 1.5 * force / mass;
}

void Goosecircle::applyDampingForce(float strength)
{
    float speed = glm::length(vel);
    if (speed != 0) {
        glm::vec2 dir = vel / speed;
        applyForce(-dir * strength);
    }
}

void Goosecircle::applyElasticForce(float strength)
{
    glm::vec2 diff = origPos - pos;
    float length = glm::length(diff);
    if (length != 0) {
        glm::vec2 dir = diff / length;
        elasticForce = dir * strength;
        applyForce(elasticForce);
    }
}

void Goosecircle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;

}

void Goosecircle::draw()
{
    if (pos.x < ofGetWidth() / 2) {
        if (acc.x < 0) {
            goose1.draw(pos, mass * 2, mass * 2);
        }


        if (acc.x >= 0) {
            goose2.draw(pos, mass * 2, mass * 2);
        }
}
    if (pos.x >= ofGetWidth() / 2) {
        if (acc.x <= 0) {
            goose1.draw(pos, mass * 2, mass * 2);
        }
        if (acc.x > 0) {
            goose2.draw(pos, mass * 2, mass * 2);
        }
    }

    /*cout << mass << endl;*/
    //ofDrawCircle(pos, mass * 2.0);
}
