#include "Firework.h"

Firework::Firework() {
    pos = glm::vec3(0, 0 ,0);
}

Firework::Firework(glm::vec3 _pos) {
    pos = _pos;

}

void Firework::setup(glm::vec3 _vel, glm::vec3 _pos) {

    vel = glm::vec3(0, 0, 0);
    acc = glm::vec3(0, 0, 0);
    vel = _vel;
    pos = _pos;
}

void Firework::update(glm::vec3 _vel) {
    vel += _vel;
    pos += vel;
    vel += acc;
    acc *= 0;

}

void Firework::draw() {
    ofPushStyle();
    ofSetColor(255);
    ofDrawEllipse(pos, 3, 6);
    ofPopStyle();


}
void Firework::time() {
    bornTime = ofGetElapsedTimef();
}