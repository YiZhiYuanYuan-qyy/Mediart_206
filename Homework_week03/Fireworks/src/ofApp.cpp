#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    for (int i = 0; i < firework.size(); i++) {
        firework[i].setup(vel);


    }
    gravity = glm::vec2(0, .15);
}

//--------------------------------------------------------------
void ofApp::update() {

    for (int i = 0; i < particleSystems.size(); i++) {
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();

        if (particleSystems[i].systemFade < 0) {
            particleSystems.erase(particleSystems.begin() + i);
        }
    }
    for (int i = 0; i < firework.size(); i++) {
        firework[i].update();
    }
}


//--------------------------------------------------------------
void ofApp::draw() {

    for (int i = 0; i < particleSystems.size(); i++) {
        particleSystems[i].draw();


    }
    for (int i = 0; i < firework.size(); i++) {
        firework[i].draw();

        if (firework[i].pos.y <= 400) {
            particleSystems.push_back(ParticleSystem(glm::vec2(firework[i].pos.x, firework[i].pos.y)));

            firework.erase(firework.begin() + i);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

    if (key == 'f') {
        ofToggleFullscreen();
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

    firework.push_back(Firework(glm::vec2(x, y)));




}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}