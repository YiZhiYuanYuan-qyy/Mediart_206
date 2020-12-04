#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(255, 160, 122);
	attractionOn = true;
	repulsionOn = true;
	elasticOn = true;
	posBoy = glm::vec2(ofGetWidth() * 0.5, 0.5 * ofGetHeight());
	velBoy = glm::vec2(0, 0);
	accBoy = glm::vec2(0, 0);
	particle.mass = 10.0;
	particle.pos = glm::vec2(10, 10);
	ofSetColor(255, 160, 122);
	ofDrawCircle(ofGetMouseX() * 0.5, 0.5 * ofGetMouseY(), 90);
	for (int y = 0; y < 10; y++) {          
		for (int x = 0; x < 10; x++) {
			Mover mover(glm::vec2(ofGetWidth()*0.5,0.5*ofGetHeight()));      
			mover.mass = ofMap(x * y, 0, 100, 2, 20);     
			movers.push_back(mover);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	ofDrawCircle(ofGetMouseX() * 0.5, 0.5 * ofGetMouseY(), 20);
	accBoy = glm::vec2(ofRandom(-0.2,0.2), ofRandom(-0.2, 0.2));
	velBoy += accBoy;
	posBoy += velBoy;
	accBoy *= 0;
	if (posBoy.x <= 50) {
		posBoy.x = 50;
		accBoy = -accBoy;
		velBoy = -velBoy*0.7;
	}
	if (posBoy.x >= ofGetWidth() - 50) {
		posBoy.x = ofGetWidth() - 50;
		accBoy = -accBoy;
		velBoy = -velBoy * 0.7;
	}
	if (posBoy.y >= ofGetHeight() - 50) {
		posBoy.y = ofGetHeight() - 50;
		accBoy = -accBoy;
		velBoy = -velBoy*0.7;
	}
	if (posBoy.y <= 50) {
		posBoy.y = 50;
		accBoy = -accBoy;
		velBoy = -velBoy * 0.7;
	}

	glm::vec2 follow = glm::vec2(posBoy);
	glm::vec2 diff = follow - particle.pos;
	particle.addForce(diff * 0.01);
	particle.addDampingForce(0.2);
	particle.update();
	dis = glm::vec2(posBoy - particle.pos);
	distance = glm::length(dis);
	if (distance <= 70) {
		particle.disapear();
		x = particle.pos.x;
		y = particle.pos.y;
		//moth.pos = glm::vec2(x, y);
		//弹出很多小球
		glm::vec2 mouse(ofGetMouseX(), ofGetMouseY());
		particle.pos = particle.pos*0.8+0.2* mouse;
		posBoy = particle.pos;
		for (int i = 0; i < movers.size(); i++) {
			glm::vec2 target = mouse - movers[i].pos;   
			float distance = glm::length(target);        
			if (repulsionOn && distance != 0 && distance < 100) {

				glm::vec2 direction = target / distance; 
				movers[i].applyForce(-direction);           
			}
			else if (attractionOn && distance != 0 && distance < 200) {

				glm::vec2 direction = target / distance;        
				movers[i].applyForce(direction);              
			}

			if (elasticOn) {
				movers[i].applyElasticForce(0.5);    
			}
			movers[i].applyDampingForce(0.2);   
			movers[i].update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetCircleResolution(80);
	particle.draw();
	ofSetColor(92, 172, 238);
	ofDrawCircle(posBoy, 50);
	dis = glm::vec2(posBoy - particle.pos);
	distance = glm::length(dis);
	if (distance <= 70) {
		for (int i = 0; i < movers.size(); i++)
		{
			movers[i].draw();
		}
	}
	// reset draw color

	//for (int i = 0; i < movers.size(); i++)
	//{
	//	movers[i].draw();
	//}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	glm::vec2 follow = glm::vec2(posBoy);
	glm::vec2 diff = follow - particle.pos;
	if (key == OF_KEY_UP) {
		up = glm::vec2(0, -10);
		particle.addForce(up);
	}
	if (key == OF_KEY_DOWN) {
		down = glm::vec2(0, 10);
		particle.addForce(down);
	}
	if (key == OF_KEY_RIGHT) {
		right = glm::vec2(10, 0);
		particle.addForce(right);
	}
	if (key == OF_KEY_LEFT) {
		left = glm::vec2(-10, 0);
		particle.addForce(left);
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
