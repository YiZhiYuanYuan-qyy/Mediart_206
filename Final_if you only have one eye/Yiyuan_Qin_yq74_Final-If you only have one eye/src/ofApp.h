#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include "ofxAssimpModelLoader.h"
#include "ofxCv.h"  


using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void drawScene(bool isPreview);
		
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

		ofVideoGrabber video;
		ofxCvHaarFinder finder;
		ofxCv::ObjectFinder eyes;
		float eyejudge;

		ofVec3f windowTopLeft;
		ofVec3f windowBottomLeft;
		ofVec3f windowBottomRight;
		ofCamera headTrackedCamera;
		ofEasyCam previewCamera;
	
		bool usePreview;
		float windowWidth;
		float windowHeight;
		float viewerDistance;
	
		deque<ofPoint> headPositionHistory;

		ofVboMesh window;

		ofxAssimpModelLoader model;
		ofLight	light;

		string curFileInfo;

		bool bHelpText;
		
		ofVboMesh mesh;
		bool bUsingMesh, view_3d, view_2d, object;
		ofNode meshNode;
		glm::vec2 pos;
		ofEasyCam cam;
		float cameraOrbit, time_x, time_y;
		ofTrueTypeFont font3d, font2d, title;
		ofSoundPlayer music;
};
