#include "Bat.h"

// constructor
Bat::Bat() {
	bat1.load("BAT1.png");
	bat2.load("BAT2.png");
	pos = glm::vec2(0, 0);
}

Bat::Bat(glm::vec2 _pos) : Bat() {
	pos = move(_pos);
}
// update position, etc.
void Bat::setup() {
	var = ofRandom(1, 10);
}
void Bat::update() {
	time = ofGetSystemTimeMillis() % 1000;
	//angle = ofRandom(0,10);
}

void Bat::draw() {
	if (time >= 0 and time < 500) {
		bat1.draw(pos.x,pos.y, 100, 100);
	}
	if (time >= 500 and time <= 1000) {
		bat2.draw(pos.x, pos.y, 100, 100);
	}
}