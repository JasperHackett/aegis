#include "ClickManager.hpp"
#include <iostream>

ClickManager::ClickManager()
{
    //ctor
}

ClickManager::~ClickManager()
{
    //dtor
}

void ClickManager::checkHover(sf::Vector2i mousePos){

    for(RenderObject* object : visibleObjects){
        if(object->getPos().contains(mousePos)){
            somethingHovered = true;
            if(!(hoveredObject == object)){
                if(hoveredObject != nullptr){
                    hoveredObject->setHovered(false);
                }
                hoveredObject = object;
                hoveredObject->setHovered(true);
            }
        }
    }
    if(somethingHovered == false && hoveredObject != nullptr){
        hoveredObject->setHovered(false);
        hoveredObject = nullptr;
    }
    somethingHovered = false;

}


void ClickManager::addObject(RenderObject* objectIn){
    visibleObjects.push_back(objectIn);
}
