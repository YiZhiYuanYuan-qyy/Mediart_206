
#pragma once		
#include "ofMain.h"		

class Bat {

public:

	Bat();
	Bat(glm::vec2 _pos);

	void update();
	void draw();
	void setup();
	float rangex, rangey;
	float x, y;
	float var, judge;
	//ofVec2f loc, vel, acc;
	ofImage bat1, bat2;
	float time, angle;
	ofVec2f pos;
};