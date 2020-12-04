#pragma once

#define WEBCAM
#include "ofMain.h"
#include "first.h"
#include"Bat.h"
#include "goosecircle.h"
#include"drum.h"
#include"ofxFontStash.h"
#include"pallbearers.h"
#include"ear.h"
#include"fall.h"
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
		Goose goose[40];
		vector<Goose> geese;
		vector<Bat> bats;
		ofImage box, drumleft, drumright, clock, heavens, surround, alone;
		float time, posx, posy;
		ofVec2f orin;
		ofSoundPlayer sound1, sound2, sounddrum, sound3, sound4, sound5, sound6, pace, clocksound, background;
		ofTrueTypeFont font, title, page1, page2, page3;
		bool MousePressed;
		Bat bat0, bat1, bat2, bat3, bat4, bat5, bat6, bat7, bat8;
		bool zeroscene, firstscene,secondscene,thirdscene,forthscene,fifthscene,sixthscene,end;
		vector<Goosecircle> Goosecircles;
		bool repulsionOn, attractionOn, elasticOn;
		Goosecircle goosee;
		Drum drum;
		ofxFontStash Chinese;
		Pall pall;
		Ear ear;
		vector<Fall> falls;
		ofImage fall, srcImg, brushImg, dstImg;
		ofFbo       maskFbo;
		ofFbo       fbo;

		ofShader    shader;

		bool        bBrushDown;
		float subx, suby, subposx, subposy;
};
