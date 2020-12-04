#pragma once
#pragma once
#include "ofMain.h"


class Particle {
public:

    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);

    void applyForce(glm::vec2 force);
    void update();
    void draw();
    glm::vec2 pos, vel, acc, frc, posOfForce;
    float mass;
    float fade;
    float time;
    float fadeScale;

};