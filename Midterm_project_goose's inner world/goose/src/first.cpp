#include "first.h"

// constructor
Goose::Goose() {
	rangex = ofRandom(300, 500);
	rangey = ofRandom(300, 500);

}

// update position, etc.
void Goose::setup(float x, float y) {
	goose.load("GOOSE.png");
	goose_.load("GOOSE_.png");
	orinx = x;
	oriny = y;
	loc.set(x, y);
	acc = ofVec2f(ofRandom(-3,3), ofRandom(-2,2));
	size = ofRandom(100, 250);
}
void Goose::update() {
	loc += acc;
	if (loc.x > orinx + rangex) {
		acc.x = -acc.x;
	}
	if (loc.x < orinx - rangex) {
		acc.x = -acc.x;
	}
	if (loc.y > oriny + rangey) {
		acc.y = -acc.y;
	}

	if (loc.y < oriny - rangey) {
		acc.y = -acc.y;
	}
}

void Goose::draw() {
	if (acc.x < 0) {
		goose.draw(loc, size, size);
	}
	

	if (acc.x >= 0) {
		goose_.draw(loc, size, size);
	}
	

}