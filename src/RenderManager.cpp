#include "RenderManager.hpp"
#include <iostream>
RenderManager::RenderManager()
{
    //ctor
}

RenderManager::~RenderManager()
{
    //dtor
}

void RenderManager::addObject(RenderObject* renderObjectIn){
    this->renderedGameObjects.push_back(renderObjectIn);
}



void RenderManager::render(sf::RenderWindow &window){

    for(RenderObject *object : renderedGameObjects){
        object->draw(window);

    }


}
