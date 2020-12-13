#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
	ofSetVerticalSync(true);
	
	video.setup(320, 240);
	finder.setup("haarcascade_frontalface_default.xml");
	eyes.setup("haarcascade_eye.xml");
	usePreview = false;
	
	//
	eyes.setPreset(ObjectFinder::Preset::Fast);
	eyes.getTracker().setPersistence(30);
	//

	previewCamera.setDistance(3.0f);
	previewCamera.setNearClip(0.01f);
	previewCamera.setFarClip(500.0f);
	previewCamera.setPosition(0.4f, 0.2f, 0.8f);
	previewCamera.lookAt(ofVec3f(0.0f, 0.0f, 0.0f));
	
	headTrackedCamera.setNearClip(0.01f);
	headTrackedCamera.setFarClip(1000.0f);

	windowWidth = 0.3f;
	windowHeight = 0.2f;
	
	windowTopLeft = ofVec3f(-windowWidth / 2.0f,
							+windowHeight / 2.0f,
							0.0f);
	windowBottomLeft = ofVec3f(-windowWidth / 2.0f,
							   - windowHeight / 2.0f,
							   0.0f);
	windowBottomRight = ofVec3f(+windowWidth / 2.0f,
								-windowHeight / 2.0f,
								0.0f);
	

	viewerDistance = 0.4f;

	//model
	ofSetVerticalSync(true);

	bUsingMesh = false;
	model.loadModel("Engel_C.obj");
	light.setPosition(600, 0, 500);
	cam.setDistance(700);
	curFileInfo = ".obj";
	cameraOrbit = 0;
	cam.setDistance(700);
	model.setRotation(0, 90, 1, 0, 0);

	time_x, time_y = 0;
	bHelpText = true;
	object = false;
	font3d.load("JosefinSans-BoldItalic.ttf", 50);
	font2d.load("JosefinSans-BoldItalic.ttf", 50);
	title.load("JosefinSans-BoldItalic.ttf", 100);
	music.load("music.mp3");
	music.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	finder.findHaarObjects(video.getPixels());
	
	ofVec3f headPosition(0,0,viewerDistance);
	//eyes
	if (video.isFrameNew()) {  // process new frames

		eyes.update(video);     // update the face tracker
	}
	//
	if (finder.blobs.size() > 0) {
		//get the head position in camera pixel coordinates
		const ofxCvBlob & blob = finder.blobs.front();
		float cameraHeadX = blob.centroid.x;
		float cameraHeadY = blob.centroid.y;
		
		//do a really hacky interpretation of this, really you should be using something better to find the head (e.g. kinect skeleton tracking)
		
		//since camera isn't mirrored, high x in camera means -ve x in world
		float worldHeadX = ofMap(cameraHeadX, 0, video.getWidth(), windowBottomRight.x, windowBottomLeft.x);
		
		//low y in camera is +ve y in world
		float worldHeadY = ofMap(cameraHeadY, 0, video.getHeight(), windowTopLeft.y, windowBottomLeft.y);
		
		//set position in a pretty arbitrary way
		headPosition = ofVec3f(worldHeadX, worldHeadY, viewerDistance);
	} else {
		if (!video.isInitialized()) {
			headPosition = ofVec3f(0.5f * windowWidth * sin(ofGetElapsedTimef()), 0.5f * windowHeight * cos(ofGetElapsedTimef()), viewerDistance);
		}
	}
	
	headPositionHistory.push_back(headPosition);
	while (headPositionHistory.size() > 50.0f){
		headPositionHistory.pop_front();
	}

	headTrackedCamera.setPosition(headPosition);
	headTrackedCamera.setupOffAxisViewPortal(windowTopLeft, windowBottomLeft, windowBottomRight);
	if (view_3d == true) {
		model.setScale(0.3, 0.3, 0.3);
		model.setPosition(0, -600, 0);
		if (headPosition.x > 0) {
			//cameraOrbit += ofGetLastFrameTime() * 20.;
			time_x = ofMap(headPosition.x, 0, 0.1, 90, -90);
			cam.orbitDeg(time_x, 0., cam.getDistance(), { 0., 0., 0. });
		}
		if (headPosition.x <= 0) {
			time_x = ofMap(headPosition.x, 0, -0.1, 90, 270);
			//cameraOrbit -= ofGetLastFrameTime() * 20.;
			cam.orbitDeg(time_x, 0., cam.getDistance(), { 0., 0., 0. });
		}
	}
	if (view_2d == true) {
		cam.orbitDeg(90, 0., cam.getDistance(), { 0., 0., 0. });
		model.setScale(0.3, 0.3, 0.3);
		if (headPosition.x > 0) {
			//time = time + 30;
			time_x = ofMap(headPosition.x, 0, 0.1, 0, 3.14);
			time_y = ofMap(headPosition.x, 0, 0.1, 0, 3.14 / 2);
			//pos.y = ofMap(headPosition.y, -0.1, 0.1, 0, 100);
			pos.x = cos(time_x) * 100;
			pos.y = sin(time_y) * 100;
		}
		if (headPosition.x <= 0) { 
			//time = time - 30;
			time_x = ofMap(headPosition.x, -0.1, 0, -3.14, 0);
			time_y = ofMap(headPosition.x, -0.1, 0, -3.14 / 2, 0);
			pos.x = cos(time_x) * 60;
			pos.y = sin(time_y) * 60;
		}
		model.setPosition(pos.x, -600, pos.y);
		//cout << "pos" << pos.x << endl;
	}

}

//--------------------------------------------------------------
void ofApp::drawScene(bool isPreview){
	
	ofEnableDepthTest();

	if (isPreview) {
		ofPushStyle();
		ofSetColor(150, 100, 100);
		ofDrawGrid(1.0f, 5.0f, true);
		
		ofSetColor(255);
		
		//--
		//draw camera preview
		//
		headTrackedCamera.transformGL();
		
		ofPushMatrix();
		ofScale(0.002f, 0.002f, 0.002f);
		ofNode().draw();
		ofPopMatrix();
		
        ofMultMatrix(glm::inverse(headTrackedCamera.getProjectionMatrix()));

		ofNoFill();
		ofDrawBox(2.0f);
		
		headTrackedCamera.restoreTransformGL();
		//
		//--
		
		//--
		//draw window preview
		//
		window.clear();
		window.addVertex(windowTopLeft);
		window.addVertex(windowBottomLeft);
		window.addVertex(windowBottomRight);
		window.setMode(OF_PRIMITIVE_LINE_STRIP);
		window.draw();
		glPointSize(3.0f);
		window.drawVertices();
		//
		//--
        ofPopStyle();
	}
	
	ofPushStyle();
	ofNoFill();
	ofColor col(200,100,100);
	for (float z = 0.0f; z > -40.0f; z-= 0.1f){
		col.setHue(int(-z * 100.0f + ofGetElapsedTimef() * 10.0f) % 360);
		ofSetColor(col);
		ofDrawRectangle(-windowWidth / 2.0f, -windowHeight / 2.0f, z, windowWidth, windowHeight);
		//ofDrawCone(-windowWidth / 2.0f, -windowHeight / 2.0f, z, windowWidth, windowHeight);
	}
	ofPopStyle();
	
	ofPushStyle();
	ofEnableSmoothing();
	ofSetColor(255);
	ofSetLineWidth(5.0f);
	ofBeginShape();

	ofEndShape(false);
	ofPopStyle();
	
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(ofColor(50), ofColor(0));
	//------
	//draw the scene

	//eyes
	video.draw(0, 0);

	for (int i = 0; i < eyes.size(); i++) {
		//cout << eyes.getObject(i).getWidth() << endl;
		// get box around the face:
		ofRectangle face = eyes.getObjectSmoothed(i); // smoothed over time
		// or face = finder.getObject(i); <-- raw face position
		eyejudge = eyes.getObject(i).getWidth();
		object = eyes.getObject(i).isEmpty();

		ofPushStyle();
		
		// assign color by face ID
		int faceID = eyes.getLabel(i);
		float hue = (faceID * 55) % 255;  // offset hue by id
		ofSetColor(ofColor::fromHsb(hue, 255, 255));

		//face

		ofNoFill();
		ofDrawRectangle(face);

		ofPushMatrix();
		ofTranslate(face.getCenter().x - 30, face.getBottom() + 10);
		stringstream ss;
		ss << " eyes: " << eyes.getLabel(i);   // face id #
		ofDrawBitmapStringHighlight(ss.str(), 0, 0, ofColor::fromHsb(hue, 255, 255), ofColor(0));
		ofPopMatrix();

		glm::vec2 vel = toOf(eyes.getVelocity(i));
		ofPushMatrix();
		ofTranslate(face.getCenter());
		ofFill();
		ofDrawCircle(0, 0, 2);
		ofDrawLine(glm::vec2(0), vel * -3);   
		ofPopMatrix();

		ofPopStyle();

	}
	object = true;
	if (object == true) {
		if (eyejudge > 0) {
			if (eyes.size() >= 2) {
				view_3d = true;
				view_2d = false;
				cout << "3d is ok" << endl;
			}
			if (eyes.size() == 1) {
				view_3d = false;
				view_2d = true;
				cout << "single eye is ok" << endl;
			}
		}
		if (usePreview) {
			previewCamera.begin();
		}
		else {
			headTrackedCamera.begin();
		}

		drawScene(usePreview);

		if (usePreview) {
			previewCamera.end();
		}
		else {
			headTrackedCamera.end();
		}

		video.draw(0, 0);
		ofPushStyle();
		ofNoFill();
		for (unsigned int i = 0; i < finder.blobs.size(); i++) {
			ofRectangle cur = finder.blobs[i].boundingRect;
			ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
		}
		ofPopStyle();

		stringstream message;
		ofDrawBitmapString(message.str(), video.getWidth() + 10, 20);

		if (usePreview) {
			ofRectangle bottomLeft(0, ofGetHeight() - 200.0f, 300.0f, 200.0f);

			ofPushStyle();
			ofSetColor(0);
			ofDrawRectangle(bottomLeft);
			ofPopStyle();

			headTrackedCamera.begin(bottomLeft);
			drawScene(false);
			headTrackedCamera.end();
		}
		//
		//------
			//
		ofEnableDepthTest();

		light.enable();

		cam.begin();
		//ofDrawAxis(200);
		//ofColor(255, 255);
		if (bUsingMesh) {
			meshNode.transformGL();
			mesh.draw();
			meshNode.restoreTransformGL();
		}
		else {
			model.drawFaces();
		}
		cam.end();

		light.disable();

		ofDisableDepthTest();

	}
	if (view_3d == true) {
		ofSetColor(255);
		font3d.drawString("When you look with a pair of eyes, you'll see", 400, 100);
	}
	if (view_2d == true) {
		ofSetColor(255);
		font2d.drawString("When you look with one eye, you'll see", 400, 100);
	}
	if (view_2d == false && view_3d == false) {
		title.drawString("IF YOU ONLY HAVE ONE EYE", 500, 600);
	}

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
