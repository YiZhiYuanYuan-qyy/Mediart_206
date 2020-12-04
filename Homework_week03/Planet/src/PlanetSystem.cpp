
#include "PlanetSystem.hpp"

PlanetSystem::PlanetSystem()
{
    pos = glm::vec2(0,0);     
}

PlanetSystem::PlanetSystem(glm::vec2 _pos)
{
    pos = _pos;          
}

void PlanetSystem::applyForce(glm::vec2 force)
{
    for (int i=0; i< Planets.size(); i++)
    {
        Planets[i].applyForce(force);
    }
}

void PlanetSystem::update(int numNewParticles, int maxParticles)
{
    for (int i=0; i<numNewParticles; i++)
    {
        float time = ofGetSystemTime();
        glm::vec2 vel   = glm::vec2(ofRandom(-2*cos(time),2*cos(time)), ofRandom(-2*sin(time),2*sin(time)));   
        float mass      = ofRandom(3, 5);
        Planet planet = Planet(pos,vel,mass);   
        Planets.push_back(planet);
    }
    for (int i=0; i< Planets.size(); i++)
    {
        Planets[i].update();
    }
    while (Planets.size() > maxParticles)  
    {
        Planets.erase(Planets.begin()); 
    }
    
}

void PlanetSystem::draw()
{
    for (int i=0; i< Planets.size(); i++)
    {
        Planets[i].draw();
    }
}

