
#pragma once		
#include "ofMain.h"		

class Goose {

public:		

	Goose();				
						

	void update();
	void draw();
	void setup(float x, float y);
	float rangex, rangey;		
	float x, y;			
	float mass;
	ofVec2f loc, vel, acc;
	ofImage goose, box, goose_;
	float speed, num, orinx, oriny, size;
};