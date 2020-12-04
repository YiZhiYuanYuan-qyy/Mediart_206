#pragma once
#include "ofMain.h"

class Pall {

public:

    Pall();
    Pall(glm::vec2 _pos);

    void applyForce(glm::vec2 force);
    void update();
    void draw();
    glm::vec2 pos, vel, acc;
    ofImage pallbox;


};
