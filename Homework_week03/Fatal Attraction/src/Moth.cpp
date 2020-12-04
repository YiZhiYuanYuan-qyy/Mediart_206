//#pragma once
//#include"Moth.h"
//#include"Mover.h"
//Moth::Moth() {
//    attractionOn = true;
//    repulsionOn = true;
//    elasticOn = true;
//    pos = glm::vec2(0, 0);
//    for (int y = 0; y < 10; y++) {          // 10 columns
//        for (int x = 0; x < 10; x++) {      // 10 rows
//
//            //float posX = ofGetWidth() * 0.5;
//            //float posY = ofGetHeight() * 0.5;
//            Mover mover(glm::vec2(100,100));       // create the mover / set its position
//            mover.mass = ofMap(x * y, 0, 100, 2, 20);     // new! assign a mass based on grid order
//            movers.push_back(mover);
//        }
//    }
//}                  
//Moth::Moth(glm::vec2 _pos)
//{
//    pos = _pos;
//
//}
//
//
//void Moth::update() {
//    for (int i = 0; i < movers.size(); i++) {
//        glm::vec2 target = pos - movers[i].pos;     // vector mover --to--> mouse
//        float distance = glm::length(target);          // distance = length of vector
//        if (repulsionOn && distance != 0 && distance < 100) {
//
//            glm::vec2 direction = target / distance;         // normalize vector (divide by length -> length = 1)
//            movers[i].applyForce(-direction);                // repulse - invert direction ( * -1 )
//        }
//        else if (attractionOn && distance != 0 && distance < 200) {
//
//            glm::vec2 direction = target / distance;         // normalize
//            movers[i].applyForce(direction);                 // attract, push in direction
//        }
//
//        if (elasticOn) {
//            movers[i].applyElasticForce(0.5);       // push mover back to its original point over time
//        }
//        movers[i].applyDampingForce(0.2);       // add some "drag" to the Mover (slow it down)
//        movers[i].update();
//    }
//}
//void Moth::draw() {
//
//    for (int i = 0; i < movers.size(); i++)
//    {
//        movers[i].draw();
//    }
//}