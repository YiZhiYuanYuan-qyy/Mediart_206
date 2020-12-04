#pragma once

#include "ofMain.h"
#include"Badboy.h"
#include "Mover.h"
#include "Moth.h"
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

		glm::vec2 posBoy, velBoy, accBoy, up, down, left, right, dis;
		vector<Mover> movers;
		Particle particle;
		bool repulsionOn, attractionOn, elasticOn;
		float x, y;
		float distance;
		//Moth moth;
};
