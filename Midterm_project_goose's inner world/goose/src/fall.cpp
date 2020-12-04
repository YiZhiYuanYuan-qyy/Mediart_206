#include "Fall.h"
Fall::Fall() {

	
	radius = ofRandom(100, 250);
	

	
	x = ofGetMouseX();
	y = ofGetMouseY();
	crash.load("crash.mp3");
	crash.setVolume(0.1);
	dirY = 0;
	g = 2;
}


void Fall::update() {
	dirY = dirY + g;
	y += dirY;	

	if (y <= radius) {
		dirX = g * dirX;
		/*y = radius;*/
		dirY = -dirY;
	}
	else if (y >= ofGetHeight() - radius) {
		y = ofGetHeight() - radius;
		dirY = -dirY * 0.5;
	}
	if ((y == ofGetHeight() - radius)&&(dirY <-2)) {
		crash.play();
	}
}



void Fall::draw(ofImage img) {
	img.draw(x, y, radius-10,radius);	
}