#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    ofImage img;
    ofVideoGrabber cam;
    ofxCv::ContourFinder contourFinder;
    ofColor targetColor;
    ofxPanel gui;
    ofParameter<float> threshold;
    ofParameter<bool> trackHs;
    float x, y;
    ofSoundPlayer music;
};
