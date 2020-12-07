#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    img.load("smile.png");
    img.resize(50, 50);
    cam.setup(640, 480);
    contourFinder.setMinAreaRadius(30);
    contourFinder.setMaxAreaRadius(230);
    gui.setup();
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(trackHs.set("Track Hue/Saturation", false));
    music.load("music.mp3");
    music.play();
}

void ofApp::update() {

    cam.update();
    if(cam.isFrameNew()) {
        contourFinder.setTargetColor(targetColor, trackHs ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
        contourFinder.setThreshold(60);
        contourFinder.findContours(cam);
    }
}

void ofApp::draw() {

    ofSetColor(255);
    cam.draw(0, 0);
    
    ofSetLineWidth(2);
    contourFinder.draw();
    contourFinder.getBoundingRects();

    
    gui.draw();
    
    ofTranslate(8, 75);
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(-3, -3, 64+6, 64+6);
    ofSetColor(targetColor);
    ofDrawRectangle(0, 0, 64, 64);
    for (int i = 0; i < contourFinder.getBoundingRects().size(); i++) {
        x = contourFinder.getCenter(i).x;
        y = contourFinder.getCenter(i).y;
        img.draw(x, y);
    }
    img.draw(-30, 0);
}

void ofApp::mousePressed(int x, int y, int button) {
    targetColor = cam.getPixels().getColor(x, y);
}
