#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(250, 128, 114);
	vid.load("video.mp4");
	vid.play();

	first_fbo.allocate(1920, 1080);
	second_fbo.allocate(1920, 1080);
	third_fbo.allocate(1920, 1080);
	fourth_fbo.allocate(1920, 1080);

	bezManager.setup(10);
	bezManager.addFbo(&first_fbo);
	bezManager.addFbo(&second_fbo);
	bezManager.addFbo(&third_fbo);
	bezManager.addFbo(&fourth_fbo);

	bezManager.loadSettings();
	change = false;
	back = true;

}

//--------------------------------------------------------------
void ofApp::update() {
	a = 1920 + 1920*cos(ofGetElapsedTimef());
	b = 1080 + 1080*cos(ofGetElapsedTimef());
	vid.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofClear(250, 128, 114);
	if (change == false&&back == true) {
		first_fbo.begin();
		ofSetColor(0, 0, 255);
		vid.draw(0, 0, a, b);
		first_fbo.end();

		second_fbo.begin();
		ofSetColor(255, 0, 0);
		vid.draw(0, 0, a, b);
		second_fbo.end();

		third_fbo.begin();
		ofSetColor(0, 255, 0);
		vid.draw(0, 0, a, b);
		third_fbo.end();

		fourth_fbo.begin();
		ofSetColor(255, 255, 0);
		vid.draw(0, 0, a, b);
		fourth_fbo.end();

		bezManager.draw();
	}
	if (change == true&&back == false) {
		vid.draw(0, 0, 1920, 1080);
	}


	string _help = "[ENTER] key : Toggle guide visible.\n";
	_help += "[s] key : Save settings.\n";
	_help += "[l] key : Load settings.\n";
	_help += "Left drag the control point : Move Corners/Anchors.\n";
	_help += "Right click the control point : Toggle bezier/homoglaphy mode.\n";
	_help += "Arrow key : Move Corners/Anchors. (selected control point)\n";
	_help += "[b] key : watch transformed video\n";
	_help += "[c] key : watch full screen video\n";
	ofDrawBitmapString(_help, 10, 20);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	bezManager.keyPressed(key);
	if (key == OF_KEY_RETURN) {
		bezManager.toggleGuideVisible();
	}
	if (key == 's') {
		bezManager.saveSettings();
	}
	if (key == 'l') {
		bezManager.loadSettings();
	}
	if (key == 'c') {
		change = true;
		back = false;
	}
	if (key == 'b') {
		change = false;
		back = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	bezManager.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	bezManager.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

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
