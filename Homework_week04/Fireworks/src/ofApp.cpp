#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);

    for (int i = 0; i < firework.size(); i++) {
        firework[i].setup(vel,pos);


    }
    gravity = glm::vec3(0,-0.15,0);
    sky.load("sky.jpg");
    ofColor planeColor(255, 255, 255, 220);
    plane.addVertex(ofVec3f(0, 0, 0));
    plane.addTexCoord(ofVec2f(0, 0));
    plane.addColor(planeColor);
    plane.addVertex(ofVec3f(0, 0, 0));
    plane.addTexCoord(ofVec2f(640, 0));
    plane.addColor(planeColor);
    plane.addVertex(ofVec3f(0, 0, 0));
    plane.addTexCoord(ofVec2f(640, 350));
    plane.addColor(planeColor);
    plane.addVertex(ofVec3f(0, 0, 0));
    plane.addTexCoord(ofVec2f(0, 350));
    plane.addColor(planeColor);
    //
    music.load("music.mp3");
    music.play();
    sky2.load("sky2.jpg");
    sky.load("sky.jpg");
}

//--------------------------------------------------------------
void ofApp::update() {

    // v1
    ofVec3f v1(-ofGetWidth()/2, ofGetHeight()/2, 0);
    plane.setVertex(0, v1);
    ofVec3f vn1 = v1;
    vn1.normalize();
    plane.addNormal(vn1);
    // v2  
    ofVec3f v2(-ofGetWidth() / 2, ofGetHeight() / 2, 5000);
    plane.setVertex(1, v2);
    ofVec3f vn2 = v2;
    vn2.normalize();
    plane.addNormal(vn2);
    // v3  
    ofVec3f v3(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    plane.setVertex(2, v3);
    ofVec3f vn3 = v3;
    vn3.normalize();
    plane.addNormal(vn3);
    // v4  
    ofVec3f v4(ofGetWidth() / 2, ofGetHeight() / 2, 5000);
    plane.setVertex(3, v4);
    ofVec3f vn4 = v4;
    vn4.normalize();
    plane.addNormal(vn4);
   
    plane.addTriangle(1, 0, 2);
    plane.addTriangle(2, 3, 1);

    //
    for (int i = 0; i < particleSystems.size(); i++) {
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();

        if (particleSystems[i].systemFade < 0) {
            particleSystems.erase(particleSystems.begin() + i);
        }
    }
    for (int i = 0; i < firework.size(); i++) {
        firework[i].update(glm::vec3(ofRandom(-2, 2), ofRandom(-0.5, 1), ofRandom(-2, 2)));
    }
}


//--------------------------------------------------------------
void ofApp::draw() {
    camera.begin();
    ofDisableDepthTest();
    ofEnableAlphaBlending();
    sky.getTextureReference().bind();
    plane.draw();
    sky.getTextureReference().unbind();
    ofDisableAlphaBlending();
    sky2.draw(-ofGetWidth()/2, -ofGetHeight()/2);
    sky2.resize(ofGetWidth(), ofGetHeight());
    ofDrawAxis(100);
    for (int i = 0; i < particleSystems.size(); i++) {
        particleSystems[i].draw();


    }
    for (int i = 0; i < firework.size(); i++) {
        firework[i].draw();

        if (firework[i].pos.y >= 400) {
            particleSystems.push_back(ParticleSystem(glm::vec3(firework[i].pos.x, firework[i].pos.y ,firework[i].pos.z)));

            firework.erase(firework.begin() + i);
        }
    }

    ofDisableDepthTest();
    camera.end();

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

    firework.push_back(Firework(glm::vec3(0, 0,0)));




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