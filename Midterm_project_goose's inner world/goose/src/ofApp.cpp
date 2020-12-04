#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSetFrameRate(60);
	box.load("BOX.png");
	clock.load("CLOCK.png");
	heavens.load("HEAVENS.png");
	surround.load("surround.png");
	fall.load("alone.png");
	srcImg.load("TEAR.png");
	dstImg.load("B.png");
	brushImg.load("brush.png");
	alone.load("alone.png");
	ofBackground(255);
	ofEnableSmoothing();
	int numgoose = 40;
	int numbat = 10;
	//text
	font.load("Sofia-Regular.otf", 30);
	page1.load("Amatic-Bold.ttf", 50);
	page2.load("Amatic-Bold.ttf", 50);
	page3.load("Amatic-Bold.ttf", 50);
	title.load("ShangShouChuanQiShuFaTi-2.ttf", 80);
	Chinese.load("ShangShouChuanQiShuFaTi-2.ttf", 80);
	//sound
	sound1.load("1.mp3");
	sound2.load("2.mp3");
	sound3.load("3.mp3");
	sound4.load("4.mp3");
	sound5.load("5.mp3");
	sound6.load("6.mp3");
	sounddrum.load("drum.mp3");
	pace.load("pace.mp3");
	clocksound.load("clocksound.wav");
	background.load("Adam Hurst - Lament.mp3");

	//geese
	for (int i = 0; i < numgoose; i++) {
		Goose tempGoose;
		geese.push_back(tempGoose);
	}
	for (int i = 0; i < numgoose; i++) {
		goose[i].setup(ofRandom(0, ofGetWidth()), ofRandom(750, ofGetHeight()));
	}
	//bat
	ofVec2f pos = ofVec2f(0,0);
	Bat bat = Bat(pos);
	bat0 = Bat(ofVec2f(ofGetWidth() / 2 - 700, ofGetHeight() / 2 - 150));
	bat1 = Bat(ofVec2f(200,900));
	bat2 = Bat(ofVec2f(230, 500));
	bat3 = Bat(ofVec2f(1000, 700));
	bat4 = Bat(ofVec2f(100, 330));
	bat5 = Bat(ofVec2f(1800, 200));
	bat6 = Bat(ofVec2f(230, 900));
	bat7 = Bat(ofVec2f(400, 700));
	bat8 = Bat(ofVec2f(1800, 1130));
	bats.push_back(bat);
	MousePressed = false;
	firstscene = false;
	zeroscene = true;
	secondscene = false;
	thirdscene = false;
	forthscene = false;
	fifthscene = false;
	sixthscene = false;
	end = false;
	//goosecircle
	for (int y = 0; y < 10; y++) {          // 10 columns
		for (int x = 0; x < 10; x++) {      // 10 rows

			float posX = ofRandom(0, ofGetWidth());
			float posY = ofRandom(0, ofGetHeight());
			Goosecircle goosecircle(glm::vec2(posX, posY));       // create the mover / set its position
			goosecircle.mass = ofMap(x * y, 0, 30, 2, 50);     // new! assign a mass based on grid order
			Goosecircles.push_back(goosecircle);
		}
	}

	attractionOn = true;
	repulsionOn = true;
	elasticOn = true;

	srcImg.resize(1000, 1000);
	dstImg.resize(1000, 1000);
	brushImg.resize(200, 200);
	int width = srcImg.getWidth();
	int height = srcImg.getHeight();

	maskFbo.allocate(width, height);
	fbo.allocate(width, height);

	//color
	#ifdef TARGET_OPENGLES
	shader.load("shaders_gles/alphamask.vert", "shaders_gles/alphamask.frag");
	#else
	if (ofIsGLProgrammableRenderer()) {
		string vertex = "#version 150\n\
    	\n\
		uniform mat4 projectionMatrix;\n\
		uniform mat4 modelViewMatrix;\n\
    	uniform mat4 modelViewProjectionMatrix;\n\
    	\n\
    	\n\
    	in vec4  position;\n\
    	in vec2  texcoord;\n\
    	\n\
    	out vec2 texCoordVarying;\n\
    	\n\
    	void main()\n\
    	{\n\
	        texCoordVarying = texcoord;\
    		gl_Position = modelViewProjectionMatrix * position;\n\
    	}";
		string fragment = "#version 150\n\
		\n\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
        in vec2 texCoordVarying;\n\
		\
        out vec4 fragColor;\n\
		void main (void){\
		vec2 pos = texCoordVarying;\
		\
		vec3 src = texture(tex0, pos).rgb;\
		float mask = texture(maskTex, pos).r;\
		\
		fragColor = vec4( src , mask);\
		}";
		shader.setupShaderFromSource(GL_VERTEX_SHADER, vertex);
		shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment);
		shader.bindDefaults();
		shader.linkProgram();
	}
	else {
		string shaderProgram = "#version 120\n \
		#extension GL_ARB_texture_rectangle : enable\n \
		\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
		\
		void main (void){\
		vec2 pos = gl_TexCoord[0].st;\
		\
		vec3 src = texture2DRect(tex0, pos).rgb;\
		float mask = texture2DRect(maskTex, pos).r;\
		\
		gl_FragColor = vec4( src , mask);\
		}";
		shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
		shader.linkProgram();
	}
	#endif


	maskFbo.begin();
	ofClear(0, 0, 0, 255);
	maskFbo.end();

	fbo.begin();
	ofClear(0, 0, 0, 255);
	fbo.end();

	bBrushDown = false;

	subx = 500;
	suby = 800;
	subposx = 750;
	subposy = 200;

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < geese.size(); i++) {
		geese[i].update();
		goose[i].update();
	}
	orin.set(ofGetMouseX(), ofGetMouseY());
	//bat
	if (firstscene == true) {
		for (int i = 0; i < bats.size(); i++) {
			bats[i].update();
		}

	}

	
	//goosecircle
	if (secondscene == true) {
		glm::vec2 mousePos = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
		for (int i = 0; i < Goosecircles.size(); i++) {
			glm::vec2 target = mousePos - Goosecircles[i].pos;     // vector mover --to--> mouse
			float distance = glm::length(target);          // distance = length of vector
			if (repulsionOn && distance != 0 && distance < 600) {
				cout << true << endl;
				glm::vec2 direction = target / distance;         // normalize vector (divide by length -> length = 1)
				Goosecircles[i].applyForce(-direction * 2);                // repulse - invert direction ( * -1 )
			}
			else if (attractionOn && distance != 0 && distance < 10000) {

				glm::vec2 direction = target / distance;         // normalize
				Goosecircles[i].applyForce(direction * 2);                 // attract, push in direction
			}

			if (elasticOn) {
				Goosecircles[i].applyElasticForce(0.3);       // push mover back to its original point over time
			}
			Goosecircles[i].applyDampingForce(0.3);       // add some "drag" to the Mover (slow it down)
			Goosecircles[i].update();
		}
	}
	
	drum.update();
	bat0.update();
	bat1.update();
	bat2.update();
	bat3.update();
	bat4.update();
	bat5.update();
	bat6.update();
	bat7.update();
	bat8.update();
	pall.update();

	if (fifthscene == true) {
		if (subx > 0) {
			subx--;

		}
		if (suby > 0) {
			suby = suby - 2;

		}
	}
	//fall
	if (sixthscene == true) {
		for (int i = 0; i < falls.size(); i++) {

			falls[i].update();

		}

		maskFbo.begin();
		if (bBrushDown) {
			brushImg.draw(mouseX - 950, mouseY - 130, 250, 250);
		}
		maskFbo.end();

		fbo.begin();
		ofClear(0, 0, 0, 0);

		shader.begin();
		shader.setUniformTexture("maskTex", maskFbo.getTexture(), 1);

		srcImg.draw(0, 0);

		shader.end();
		fbo.end();
	}

	

}

//--------------------------------------------------------------
void ofApp::draw() {
	if (zeroscene == true) {
		ofPushStyle();
		ofSetColor(0);
		bat0.draw();
		Chinese.drawString("Goose's inner world", ofGetWidth() / 2 - 600, ofGetHeight() / 2 - 50);
		font.drawString("Tap 'abcdef' to change scene ", ofGetWidth() / 2 - 500, ofGetHeight() / 2 + 80);
	}

	if (firstscene == true) {
		ofSetColor(255);
		for (int i = 0; i < geese.size(); i++) {
			goose[i].draw();
		}
		box.draw(1200, 400, 500, 350);
		for (auto& a : bats) a.draw();
		ofSetColor(0);
		page1.drawString(R"(I  felt  a  Funeral in my Brain, 
and Mourners to and fro kept treading -- treading -- 
till it seemed that Sense was breaking through)", 200, 400);


	}
	//goosecircle
	if (secondscene == true) {
		ofSetColor(255);
		for (int i = 0; i < Goosecircles.size(); i++)
		{
			Goosecircles[i].draw();
		}
		bat1.draw();
		bat2.draw();
		bat3.draw();
		bat4.draw();
		box.draw(720, 458, 770, 550);
		drum.draw(ofVec2f(100, 100));
		ofSetColor(0);
		page2.drawString(R"(And when they all were seated, 
a Service, like a Drum -- kept beating -- beating -- 
till I thought my Mind was going numb)", 800, 50);

	}
	if (thirdscene == true) {
		ofSetColor(255);
		for (int i = 0; i < geese.size(); i++) {
			goose[i].draw();
		}
		pall.draw();
		bat5.draw();
		bat6.draw();
		bat7.draw();
		bat8.draw();
		ofSetColor(0);
		page3.drawString(R"(And then I heard them lift a Box 
and creak across my Soul with those same Boots of Lead)", 200, 300);



	}
	if (forthscene == true) {
		ofSetColor(255);
		clock.draw(0, 0);
		heavens.draw(ofGetWidth() / 2 - 225, 0, 450, 300);
		ear.draw(posx, posy);
		ofSetColor(0);
		page3.drawString(R"(again, then Space -- began to toll, 
As all the Heavens were a Bell, and Being, but an Ear,)", ofGetWidth() / 2 - 430, 1250);

	}
	if (fifthscene == true) {
		ofSetColor(255);
		surround.draw(0, 0);
		alone.drawSubsection(subposx, subposy, subx, suby, ofGetMouseX() - ofGetWidth() / 2, ofGetMouseY() - ofGetHeight() / 2, 1000, 1500);
		bat1.draw();
		bat3.draw();
		bat5.draw();
		ofSetColor(0);
		page3.drawString(R"(and I, and Silence, some strange Race, wrecked, solitary, here)", ofGetWidth() / 2 - 500, 80);


	}
	if (sixthscene == true) {
		ofSetColor(0);
		page3.drawString(R"(-- And then a Plank in Reason, broke, 
and I fell down and down -- 
and hit a World, at every plunge, 
and Finished knowing -- then --" )",50, 50);
		ofSetColor(255);
		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT) && (ofGetMouseX() < 814 || ofGetMouseX() > 1814 || ofGetMouseY() > 1000)) {
			int numBalls = 1;
			for (int i = 0; i < numBalls; i++) {
				Fall tempBall;
				falls.push_back(tempBall);
			}
		}
		for (int i = 0; i < falls.size(); i++) {

			falls[i].draw(fall);
		}
		ofSetColor(255, 255);

		dstImg.draw(814, 0);

		fbo.draw(814, 0);
		bat7.draw();
		bat6.draw();
		bat2.draw();
	}

	if (end == true) {
		ofSetColor(0);
		Chinese.drawString("The End", ofGetWidth() / 2 - 200, ofGetHeight() / 2 - 50);
	}
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//pall direction
	if (thirdscene == true) {
		if (key == OF_KEY_RIGHT) {
			pace.play();
			pall.applyForce(ofVec2f(2, 0));
		}
		if (key == OF_KEY_LEFT) {
			pace.play();
			pall.applyForce(ofVec2f(-2, 0));
		}
		if (key == OF_KEY_UP) {
			pace.play();
			pall.applyForce(ofVec2f(0, -2));
		}
		if (key == OF_KEY_DOWN) {
			pace.play();
			pall.applyForce(ofVec2f(0, 2));
		}
		if (pall.pos.x + 1000 < 0 || pall.pos.x > ofGetWidth() || pall.pos.y + 700 < 0 || pall.pos.y > ofGetHeight()) {
			pace.stop();
		}
	}

	//background sound
	if (key == ' ') {
		if (zeroscene == true) {
			background.setVolume(0.03);
			background.play();
			background.setLoop(true);
		}
		if (firstscene == true) {
			sound1.play();
		}
		if (secondscene == true) {
			sound2.play();
		}
		if (thirdscene == true) {
			sound3.play();
		}
		if (forthscene == true) {
			clocksound.play();
			sound4.play();
		}
		if (fifthscene == true) {
			sound5.play();
		}
		if (sixthscene == true) {
			sound6.play();
		}


	}
	//scene changing
	if (key == 'a') {
		zeroscene = false;
		firstscene = true;
		secondscene = false;
		thirdscene = false;
		forthscene = false;
		fifthscene = false;
		sixthscene = false;
		end = false;
		background.setVolume(0.03);
		cout << "firstscene shown" << firstscene << endl;
	}
	if (key == 'b' and bats.size() >= 8) {
		firstscene = false;
		secondscene = true;
		zeroscene = false;
		thirdscene = false;
		forthscene = false;
		fifthscene = false;
		sixthscene = false;
		end = false;
		background.setVolume(0.03);
		cout << "secondscene shown" << secondscene << endl;
	}
	if (key == 'c') {
		firstscene = false;
		secondscene = false;
		zeroscene = false;
		thirdscene = true;
		forthscene = false;
		fifthscene = false;
		sixthscene = false;
		end = false;
		background.setVolume(0.03);
		cout << "thirdscene shown" << thirdscene << endl;
	}
	if (key == 'd' and (pall.pos.x +1000 < 0 || pall.pos.x > ofGetWidth() || pall.pos.y + 700 < 0 || pall.pos.y > ofGetHeight())) {
		firstscene = false;
		secondscene = false;
		zeroscene = false;
		thirdscene = false;
		forthscene = true;
		fifthscene = false;
		sixthscene = false;
		end = false;
		cout << "forthscene shown" << forthscene << endl;
	}
	if (key == 'e') {
		firstscene = false;
		secondscene = false;
		zeroscene = false;
		thirdscene = false;
		forthscene = false;
		fifthscene = true;
		sixthscene = false;
		end = false;
		background.setVolume(0.03);
		cout << "fifthscene shown" << fifthscene << endl;
	}
	if (key == 'f') {
		firstscene = false;
		secondscene = false;
		zeroscene = false;
		thirdscene = false;
		forthscene = false;
		fifthscene = false;
		sixthscene = true;
		end = false;
		background.setVolume(0.03);
		cout << "sixthscene shown" << sixthscene << endl;
	}
	if (key == 'g') {
		firstscene = false;
		secondscene = false;
		zeroscene = false;
		thirdscene = false;
		forthscene = false;
		fifthscene = false;
		sixthscene = false;
		end = true;
		background.setVolume(0.03);
		cout << "end shown" << end << endl;
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
	if (forthscene == true) {
		posx = x - 200;
		posy = y - 150;
		ofVec2f center(ofGetWidth() / 2, ofGetHeight() / 2);
		float dis = (orin - center).length();
		float sem = ofMap(dis, 0, center.length(), 0.1, 1.6);
		clocksound.setVolume(sem);
		float sem_ = ofMap(dis, 0, center.length(), 0.02, 0.1);
		background.setVolume(sem_);
	}

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (secondscene == true) {
		if (y >= 40 && y <= 160 && x >= 40 && x <= 190) {
			sounddrum.play();
		}
		if (x < ofGetWidth() + 200 && x >= ofGetWidth() - 600 && y > ofGetHeight() - 900 && y <= ofGetHeight() - 100) {
			sounddrum.play();
		}
	}

	bBrushDown = true;
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (firstscene == true) {
		bats.emplace_back(glm::vec2(x, y));
	}
	bBrushDown = false;
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
