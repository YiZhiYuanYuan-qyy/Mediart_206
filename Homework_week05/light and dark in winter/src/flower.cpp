#include "flower.h"


Flower::Flower()
{
    radius = 80;
    total = 20;
    rot = 0;
    animateZPos = 1;

    world.setMode(OF_PRIMITIVE_TRIANGLES);

    animation = true;
    for (int i = 0; i < total; i++) {
        float lat = ofMap(i, 0, total - 1, 0.0, PI);

        for (int j = 0; j < total; j++) {
            float lon = ofMap(j, 0, total - 1, 0.0, TWO_PI);

            float x = radius * sin(lat) * cos(lon);
            float y = radius * sin(lat) * sin(lon);
            float z = radius * cos(lat);

            world.addVertex(ofVec3f(x, y, z));
        }

    }

    for (int j = 0; j < total - 1; j++) {
        for (int i = 0; i < total - 1; i++) {

            world.addIndex(i + j * total);         // 0
            world.addIndex((i + 1) + j * total);     // 1
            world.addIndex(i + (j + 1) * total);     // 6

            world.addIndex((i + 1) + j * total);     // 1
            world.addIndex((i + 1) + (j + 1) * total); // 7
            world.addIndex(i + (j + 1) * total);     // 6
        }
    }

}

void Flower::update() {
    animate();
}

void Flower::animate() {
    world.clear();
    for (int i = 0; i < total; i++) {
        float lat = ofMap(i, 0, total - 1, 0.0, PI);

        for (int j = 0; j < total; j++) {
            float lon = ofMap(j, 0, total - 1, 0.0, TWO_PI);

            if (animation)
                animateZPos = ofMap(ofNoise(i * ofGetElapsedTimef() * 0.05, j * ofGetElapsedTimef() * 0.05), 0, 1, -10,10);


            float x = (animateZPos + radius) * sin(lat) * cos(lon) - 500;
            float y = (animateZPos + radius) * sin(lat) * sin(lon) - 100;
            float z = (animateZPos + radius) * cos(lat);

            add.set(0,0,0);
            add.x += 15;
            world.addVertex(ofVec3f(x, y, z) + add);

        }

    }
    for (int j = 0; j < total - 1; j++) {
        for (int i = 0; i < total - 1; i++) {

            world.addIndex(i + j * total);         // 0
            world.addIndex((i + 1) + j * total);     // 1
            world.addIndex(i + (j + 1) * total);     // 6

            world.addIndex((i + 1) + j * total);     // 1
            world.addIndex((i + 1) + (j + 1) * total); // 7
            world.addIndex(i + (j + 1) * total);     // 6
        }
    }

    if (animation) {
        rot = rot + 0.3;
    }
}
void Flower::draw()
{
    ofPushMatrix();
    ofRotateX(rot);
    ofRotateY(rot);
    ofSetColor(255, 255, 255);
    world.drawWireframe();
    ofPopMatrix();
}
void Flower::dark() {
    for (int i = 0; i < world.getVertices().size(); i++) {
        ofSetColor(33);
        float x = world.getVertex(i).x + add.x;
        float y = world.getVertex(i).y;
        float z = world.getVertex(i).z;
        ofSetColor(255, 0, 0);
        float sanim = 1.1;
        ofDrawSphere(x * sanim + 100, y * sanim, z * sanim, 1);
    }
}
