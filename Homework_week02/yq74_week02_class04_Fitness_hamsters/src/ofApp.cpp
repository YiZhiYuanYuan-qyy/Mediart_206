#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	g = 9.8;
	ball.set(200.200);
	radius = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
	//float A = 30;
	//float time = ofGetElapsedTimef();
	//
	//float L = 80;
	//float sigma = -60 * sqrt(g / L) * sin(sqrt(g / L) * time);
	//
	//float oumiga = 10;
	//a.set(100*A*sin(100*time));

	//v.set(-100 * A * cos(100 * time));
	////abs(ball) = ball.x*A * sigma * cos(sigma * time);
	////ball.y = ball.y*A * sigma * sin(sigma * time);
	//ball = v + a*v;
	float L = 20;
	float theta = 30;
	float time = ofGetElapsedTimef();
	float sigma = theta * cos(sqrt(g / L) * time);
	//float v = -60 * sqrt(L * g) * sin(sqrt(g / L) * time);
	float a;
	float omiga =0.8;
	a = -omiga*omiga *theta * cos(omiga * time);
	ball.x = sin(sigma) * radius * sin(sigma);
	ball.y = cos(sigma) * radius * sin(sigma);

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(color);
	if (ofGetMouseY()- ball.y <= 20) {
		ofDrawCircle(ball.x + ofGetMouseX(), 20, 20);
	}
	if (ofGetMouseY()- ball.y >= ofGetHeight() - 20) {
		ofDrawCircle(ball.x + ofGetMouseX(), ofGetHeight() - 20, 20);
	}
	if (ofGetMouseX()-ball.x <= 20) {
		ofDrawCircle(20, ball.y + ofGetMouseY(), 20);
	}
	if (ball.x + ofGetMouseX() >= ofGetWidth() - 20) {
		ofDrawCircle(ofGetWidth() - 20, ball.y + ofGetMouseY(), 20);
	}
	else if(ofGetMouseY() - ball.y > 20 and ofGetMouseY() - ball.y < ofGetHeight() - 20 and ofGetMouseX() - ball.x > 20 and ball.x + ofGetMouseX() < ofGetWidth() - 20){
		ofDrawCircle(ball.x + ofGetMouseX(), ball.y + ofGetMouseY(), 20);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_UP) {
		radius = radius * 1.2;
	}
	if (key == OF_KEY_DOWN) {
		radius = radius / 1.2;
	}
	if (key == OF_KEY_BACKSPACE){
		ball.x = 0;
		ball.y = 0;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	color = (126, 22, 156);
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
