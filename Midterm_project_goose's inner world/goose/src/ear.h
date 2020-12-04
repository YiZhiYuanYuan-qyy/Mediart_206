#pragma once
#include "ofMain.h"

class Ear {

public:

    Ear();
    Ear(glm::vec2 _pos);

    void applyForce(glm::vec2 force);
    void update(glm::vec2 pos_);
    void draw(float x,float y);
    glm::vec2 pos, vel, acc;
    ofImage ear;


};
