
#include "mover.h"

void mover::setup(float m, float x, float y){
    mass = m;
    location.set(x,y);
    velocity.set(0,0);
    acceleration.set(0,0);

    int alpha = 150;
    ofColor aqua(0, 252, 255, alpha);
    ofColor purple(198, 0, 205, alpha);
    inbetween = aqua.getLerped(purple, ofRandom(1.0));
}

void mover::applyForce(ofPoint force){
    ofPoint f;
    f = force/mass;
    acceleration += f;
}

void mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void mover::display(){
    
    ofSetColor(inbetween);
    ofDrawCircle(location.x, location.y, mass*8);

}
void mover::noConflict() {
    float r = mass * 8;
}
void mover::checkEdges(){
    if (location.x > ofGetWidth()) {
        location.x = ofGetWidth();
        velocity.x *= -0.5;
        int alpha = 150;
        ofColor aqua(99, 134, 258, alpha);
        ofColor purple(198, 128, 205, alpha);
        inbetween = aqua.getLerped(purple, ofRandom(1.0));
    }
    else if (location.x < 0){
        velocity.x *= -0.5;
        location.x = 0;
        int alpha = 150;
        ofColor aqua(30, 134, 58, alpha);
        ofColor purple(98, 158, 35, alpha);
        inbetween = aqua.getLerped(purple, ofRandom(1.0));
    }
    
    if (location.y < mass*8) {
        velocity.y *= -0.8;
        location.y = mass * 8;
        int alpha = 150;
        ofColor aqua(130, 34, 238, alpha);
        ofColor purple(133, 254, 15, alpha);
        inbetween = aqua.getLerped(purple, ofRandom(1.0));
    }
    else if (location.y >=ofGetHeight()- mass*8) {
        velocity.y *= -0.8;
        location.y = ofGetHeight() - mass * 8;
        int alpha = 150;
        ofColor aqua(111, 155, 211, alpha);
        ofColor purple(87, 122, 170, alpha);
        inbetween = aqua.getLerped(purple, ofRandom(1.0));
    }

}