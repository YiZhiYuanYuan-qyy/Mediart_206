#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(155);
	ofEnableDepthTest();
	winter.load("winter.jpg");
	winter.resize(ofGetWidth(), ofGetHeight());
	dark.load("dark.jpg");
	dark.resize(ofGetWidth(), ofGetHeight());
	white.load("white.mp3");
	black.load("dark.mp3");
	white.play();
	this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
	for (int i = 0; i < 50; i++) {
		Flower flower;
		flowers.push_back(flower);
	}
	change = false;
	color = 239;
}

//--------------------------------------------------------------
void ofApp::update(){
	this->face.clear();
	this->frame.clear();

	ofSeedRandom(39);

	for (int n = 0; n < 4; n++) {

		glm::vec3 noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
		for (int i = 0; i < 50; i++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, i * 0.01 + ofGetFrameNum() * 0.005), 0, 1, -500, 500),
				ofMap(ofNoise(noise_seed.y, i * 0.01 + ofGetFrameNum() * 0.005), 0, 1, -500, 500),
				ofMap(ofNoise(noise_seed.z, i * 0.01 + ofGetFrameNum() * 0.005), 0, 1, -500, 500));

			for (int k = 0; k < i * 0.5; k++) {

				auto tmp_location = glm::vec3(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
				tmp_location = glm::normalize(tmp_location) * ofRandom(10, 45);
				auto rotate_deg = glm::vec3(ofRandom(360), ofRandom(360), ofRandom(360));
				this->setBoxToMesh(this->face, this->frame, location + tmp_location, 15, 15, 15, rotate_deg);
				a = location + tmp_location;
			}
		}
	}

	for (int i = 0; i < 50; i++) {
		flowers[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawBitmapString("press 'c' and 'r' to change light", 50, 50, 20);
	this->cam.begin();

	ofDrawAxis(100);
	if (change == true) {
		dark.draw(-ofGetWidth() / 2, -ofGetHeight() / 2, -50);
		
		ofSetColor(39);
		this->face.draw();
		for (int i = 0; i < 50; i++) {
			flowers[i].dark();
		}
	}
	winter.draw(-ofGetWidth() / 2, -ofGetHeight() / 2, -50);
	color = 239;
	ofSetColor(color);
	this->frame.drawWireframe();

	for (int i = 0; i < 50; i++) {
		flowers[i].draw();
	}
	this->cam.end();
}

void ofApp::setBoxToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float height, float width, float depth, glm::vec3 rotate_deg) {

	int index = face_target.getVertices().size();

	auto rotation_x = glm::rotate(glm::mat4(), rotate_deg.x * (float)DEG_TO_RAD, glm::vec3(1, 0, 0));
	auto rotation_y = glm::rotate(glm::mat4(), rotate_deg.y * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
	auto rotation_z = glm::rotate(glm::mat4(), rotate_deg.z * (float)DEG_TO_RAD, glm::vec3(0, 0, 1));

	vector<glm::vec3> vertices;

	vertices.push_back(glm::vec3(width * -0.5, 0, 0));
	vertices.push_back(glm::vec3(width * 0.5, 0, 0));
	vertices.push_back(glm::vec3(0, height * 0.5, 0));
	vertices.push_back(glm::vec3(0, -height * 0.5, 0));

	vertices.push_back(glm::vec3(0, 0, depth * -0.5));
	vertices.push_back(glm::vec3(0, 0, depth * 0.5));
	vertices.push_back(glm::vec3(width * 0.5 / 1.414, height * 0.5 / 1.414, 0));
	vertices.push_back(glm::vec3(width * -0.5 / 1.414, height * -0.5 / 1.414, 0));

	vertices.push_back(glm::vec3(-width * 0.5 / 1.414, height * 0.5 / 1.414, 0));
	vertices.push_back(glm::vec3(width * 0.5 / 1.414, -height * 0.5 / 1.414, 0));

	vertices.push_back(glm::vec3(0, height * -0.5 / 1.414, depth * -0.5 / 1.414));
	vertices.push_back(glm::vec3(0, height * 0.5 / 1.414, depth * 0.5 / 1.414));

	vertices.push_back(glm::vec3(0, height * 0.5 / 1.414, depth * -0.5 / 1.414));
	vertices.push_back(glm::vec3(0, height * -0.5 / 1.414, depth * 0.5 / 1.414));

	for (auto& vertex : vertices) {

		vertex = location + glm::vec4(vertex, 0) * rotation_z * rotation_y * rotation_x;
	}

	face_target.addVertices(vertices);
	frame_target.addVertices(vertices);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		black.play();
		white.stop();
		change = true;
	}
	if (key == 'r') {
		white.play();
		black.stop();
		change = false;
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
