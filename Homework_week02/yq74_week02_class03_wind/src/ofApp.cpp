
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(255);
    for (int i = 0; i<NUM_MOVER; i++) {
        int a = ofRandom(10, ofGetHeight());
        int b = ofRandom(10, ofGetWidth());
        movers[i].setup(ofRandom(1,4), a, b);
        oringin.set(0, 0.1 * movers[i].mass);
        movers[i].applyForce(oringin);
        movers[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetFrameNum() % 100 == 0) {
        for (int i = 0; i < NUM_MOVER; i++) {
            gravity.set(0, 0.3 * movers[i].mass);
        }
    }
    if (ofGetFrameNum() % 200 == 0) {
        for (int i = 0; i < NUM_MOVER; i++) {
            gravity.set(0, -0.3 * movers[i].mass);
        }
    }

    if (ofGetFrameNum() % 300 == 0) {
        for (int i = 0; i < NUM_MOVER; i++) {
            gravity.set(-0.3 * movers[i].mass, 0);
        }
    }
    if (ofGetFrameNum() % 400 == 0) {
        for (int i = 0; i < NUM_MOVER; i++) {
            gravity.set(0.3 * movers[i].mass, 0);
        }
    }
    for (int i = 0; i < NUM_MOVER; i++) {
        movers[i].applyForce(gravity);
        movers[i].update();
        movers[i].checkEdges();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i<NUM_MOVER; i++) {
        movers[i].display();
        oringin.set(0, 0.1 * movers[i].mass);
        movers[i].applyForce(oringin);
        movers[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ 
    if (key == 'c') {
        float red = ofRandom(0, 255);
        float green = ofRandom(0, 255);
        float blue = ofRandom(0, 255);
        c = ofColor(red, green, blue);
        ofBackground(c);
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
