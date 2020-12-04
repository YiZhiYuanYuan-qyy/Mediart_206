#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetCircleResolution(100); // prettier circles
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec2f mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    //first tri
    float pct = .05; 
    ofVec2f p1;
    ofVec2f p2;
    p1.set(mouse.x - 80, mouse.y - 120);
    //p2.set(mouse.x - 195, mouse.y - 80);
    a =  a* (1. - 0.02) + p1 * 0.02;
    //b = p2 * (1. - 0.06) + mouse * 0.06;
    //c = c * (1. - pct) + mouse * pct;

    //secon tri
    ofPoint p3, p4, p5;
    p5.set(mouse.x - 10, mouse.y - 10);
    p3.set(mouse.x - 40, mouse.y + 60);
    p4.set(mouse.x + 20, mouse.y + 40);
    d = d * (1. - 0.02) + p5 * 0.02;
    e = e * (1. - 0.06) + p3 * 0.06;
    f = f * (1. - pct) + p4 * pct;
    //3 tri
    ofPoint p6, p7, p8;
    p6.set(mouse.x - 5, mouse.y - 5);
    p7.set(mouse.x - 3, mouse.y + 200);
    p8.set(mouse.x + 110, mouse.y + 65);
    g = g * (1. - 0.02) + p6 * 0.02;
    h = h * (1. - 0.04) + p7 * 0.04;
    i = i * (1. - pct) + p8 * pct;
    //4 tri
    ofPoint p9, p10, p11;
    p9.set(mouse.x + 30, mouse.y + 100);
    p10.set(mouse.x - 400, mouse.y + 440);
    p11.set(mouse.x + 20, mouse.y + 490);
    j = j * (1. - 0.02) + p9 * 0.02;
    k = k * (1. - 0.06) + p10 * 0.06;
    l = l * (1. - pct) + p11 * pct;
    //5 tri
    ofPoint p12, p13, p14;
    p12.set(mouse.x + 40, mouse.y + 80);
    p13.set(mouse.x - 350, mouse.y + 550);
    p14.set(mouse.x + 220, mouse.y + 520);
    m = m * (1. - 0.02) + p12 * 0.02;
    n = n * (1. - 0.06) + p13 * 0.06;
    o = o * (1. - pct) + p14 * pct;
    //6 tri
    ofPoint p15, p16, p17;
    p15.set(mouse.x, mouse.y);
    p16.set(mouse.x + 320, mouse.y - 30);
    p17.set(mouse.x + 130, mouse.y - 20);
    p = p * (1. - 0.02) + p15 * 0.02;
    q = q * (1. - 0.06) + p16 * 0.06;
    r = r * (1. - pct) + p17 * pct;
    //7 tri
    ofPoint p18, p19, p20;
    p18.set(mouse.x - 5, mouse.y - 5);
    p19.set(mouse.x - 250, mouse.y + 250);
    p20.set(mouse.x - 100, mouse.y + 80);
    s = s * (1. - 0.02) + p18 * 0.02;
    t = t * (1. - 0.06) + p19 * 0.06;
    u = u * (1. - pct) + p20 * pct;
    //8 tri
    ofPoint p21, p22, p23;
    p21.set(mouse.x - 100, mouse.y + 400);
    p22.set(mouse.x - 300, mouse.y + 700);
    p23.set(mouse.x - 90, mouse.y + 420);
    v = v * (1. - 0.02) + p21 * 0.02;
    w = w * (1. - 0.06) + p22 * 0.06;
    x = x * (1. - pct) + p23 * pct;
    //9 tri
    ofPoint p24, p25, p26;
    p24.set(mouse.x + 30, mouse.y + 410);
    p25.set(mouse.x + 10, mouse.y + 420);
    p26.set(mouse.x, mouse.y + 720);
    a1 = a1 * (1. - 0.02) + p24 * 0.02;
    a2 = a2 * (1. - 0.06) + p25 * 0.06;
    a3 = a3 * (1. - pct) + p26 * pct;
    color = 255, 250, 250;
    if (a.x-70 <= 0 ) {
        a.x = 70;
        color = 100;
    }
    if (a.x >= ofGetWidth() - 70) {
        a.x = ofGetWidth() - 70;
        color = 100;
    }
    if (a.y >= ofGetHeight() - 70) {
        a.y = ofGetHeight() - 70;
        color = 100;
    }
    if (a.y - 70 <= 0) {
        a.y = 70;
        color = 100;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(color);
    ofDrawCircle(a,70);
    ofDrawTriangle(d, e, f);
    ofSetColor(178, 34, 34);
    ofDrawTriangle(g, h, i);
    ofSetColor(255, 250, 250);
    ofDrawTriangle(j, k, l);
    ofDrawTriangle(m, n, o);
    ofDrawTriangle(p, q, r);
    ofDrawTriangle(s, t, u);
    ofDrawTriangle(v, w, x);
    ofDrawTriangle(a1, a2, a3);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
