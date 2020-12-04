#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    ofPoint a, b, c, p, q, r, s, t, u, v, w, x, a1, a2, a3;
    ofPoint d, e, f, g, h, i, j, k, l, m, n, o;
    int brightness;
    ofColor color;
};
