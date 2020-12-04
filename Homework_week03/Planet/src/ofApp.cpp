#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);

    glm::vec2 pos = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);    
    PlanetSystem planetSystem = PlanetSystem(pos);
    
    planetSystems.push_back(planetSystem);
    angle = 0;

    particle.mass = 10.0;
    particle.pos = pos;
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());

    for (int i=0; i< planetSystems.size(); i++){
        float time = ofGetSystemTime();
        //2*sin(time),2*cos(time)
        //gravity = glm::vec2(0.025);
        planetSystems[i].applyForce(gravity);
        planetSystems[i].update();
    }
    angle += 0.01;
    center = glm::vec2(300 * cos(angle) + ofGetWidth() * 0.5, ofGetHeight() * 0.5 + 300 * sin(angle));
    glm::vec2 diff1 = center - particle.pos;
    glm::vec2 diff2 = mousePos - particle.pos;
    particle.addForce(diff1 * 0.03);
    particle.addForce(diff2 * 0.01);
    particle.addDampingForce(0.1);
    particle.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i< planetSystems.size(); i++){
        planetSystems[i].draw();
    }
    ofSetColor(230, 230, 250);
    ofDrawCircle(center, 50);
    particle.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
