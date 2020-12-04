#pragma once

#include "ofMain.h"
#include "PlanetSystem.hpp"
#include "Particle.h"
class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void mouseReleased(int x, int y, int button);

    vector<PlanetSystem> planetSystems;
    glm::vec2 gravity;
    float angle;
    Particle particle;
    glm::vec2 center;
};
