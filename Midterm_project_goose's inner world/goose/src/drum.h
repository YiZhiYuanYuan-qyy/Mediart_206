#pragma once
#include "ofMain.h"

class Drum {

public:
    
    Drum();

    void update();
    void draw(ofVec2f pos);

    glm::vec2 pos;
    float time;
    ofImage drumright, drumleft,drumlist;


};
