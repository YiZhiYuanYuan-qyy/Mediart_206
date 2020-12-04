#pragma once
#include "ofMain.h"

class Firework {
public:
    Firework();
    Firework(glm::vec3 _pos);
    void setup(glm::vec3 _vel, glm::vec3 _pos);
    void update(glm::vec3 _vel);
    void draw();
    void time();

    glm::vec3 pos, vel, acc;
    ofPoint frc;
    float bornTime;
    float x, y;

};