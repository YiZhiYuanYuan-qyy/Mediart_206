#pragma once	
#include "ofMain.h"		

class Fall {

public:		

	Fall();				
						

	void update();
	void draw(ofImage img);

	float radius;		
	float x, y;			
	float dirX, dirY;	
	int g;
	ofSoundPlayer crash;

};