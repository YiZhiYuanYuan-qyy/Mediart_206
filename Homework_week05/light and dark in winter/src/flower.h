#pragma once
#include "ofMain.h"

class Flower {

public:

    Flower();
    void animate();
    void draw();
    void update();
    void dark();
    float radius;
    int total;
    ofMesh world;

    float rot;
    float animateZPos;
    bool animation;
    float xoff, yoff;
    ofVec3f add;
};
