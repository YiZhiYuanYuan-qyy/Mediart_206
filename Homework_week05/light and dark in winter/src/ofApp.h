#pragma once

#include "ofMain.h"
#include"flower.h"
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
		void setBoxToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float height, float width, float depth, glm::vec3 rotate_deg);
		ofImage winter,dark;
		ofEasyCam cam;
		ofMesh face, frame;
		glm::vec3 a;
		vector<Flower>flowers;
		bool change;
		float color;
		ofSoundPlayer white, black;
};
