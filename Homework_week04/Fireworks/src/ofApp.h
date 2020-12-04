#pragma once

#include "ofMain.h"
#include "ParticleSystem.h"
#include "Firework.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	vector<ParticleSystem> particleSystems;
	glm::vec3 gravity;

	vector<Firework> firework;

	glm::vec3 pos, vel;

	float lifespan = 1000;
	float systemFade = 1;
	ofEasyCam camera;
	ofImage sky, sky2;
	ofSoundPlayer music;
	ofMesh plane;
};