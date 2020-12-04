#include "drum.h"
// constructor
Drum::Drum() {
	drumright.load("drumright.png");
	drumleft.load("drumleft.png");
	drumlist.load("fewdrum.png");
	pos = glm::vec2(0, 0);

}

// update position, etc.

void Drum::update() {
	time = ofGetSystemTimeMillis();
	pos.x = pos.x * (1 + cos(time));
	pos.y = pos.y * (1 + cos(time));
}

void Drum::draw(ofVec2f pos) {
	drumleft.draw(pos.x, pos.y, 130, 100);
	drumright.draw(pos.x-50, pos.y-50, 130, 100);
	drumlist.draw(ofGetWidth()-600, ofGetHeight()-900,800,800);
}