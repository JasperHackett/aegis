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

    this->mousePos = mousePos;
    for(Clickable* object : visibleObjects){
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
    //Case where nothing is hovered and an object is still in hovered state
    if(somethingHovered == false && hoveredObject != nullptr){
        hoveredObject->setHovered(false);
        hoveredObject = nullptr;
    }
    somethingHovered = false;

}

//Adds object to vector of objects that interact with the mouse (hovering & clicking)
void ClickManager::addObject(Clickable* objectIn){
    visibleObjects.push_back(objectIn);
}


//Called on left mouse event. mouseDown = true for pressed. mouseDown = false for released
void ClickManager::leftMouseClick(bool mouseDown){

    if(hoveredObject != nullptr){


        //Case where mouse pressed
        if(mouseDown){
            mousePressedObject = hoveredObject;

            if(clickedObject != nullptr){
                //Case where clicked object is not moused down object
                if(clickedObject != mousePressedObject){
                    clickedObject.isClicked(false);
                    clickedObject = nullptr;
                }
            }


        //Case where mouse released
        }else{
           //When mouse is released and something was pressed on
            if(mousePressedObject != nullptr){
                //Case where mouse is released while hovering over object that was moused down on (SUCCESSFUL CLICK)
                if(mousePressedObject == hoveredObject){
                    clickedObject = mousePressedObject;
                    clickedObject->isClicked(true);
                //Case where its not mouse downed on
                }else{
//                    if(clickedObject != nullptr && mousePressedObject != clickedObject){
//                            if(clickedObject->reserveSpace.contains(mousePos)){
//                                std::cout << "click within reserve space" << std::endl;
//
//                            }else{
//                                clickedObject->isClicked(false);
//                                clickedObject = nullptr;
//                            }
//                    }else{
//
//                    }
                }
            //Nothing clicked on
            }else{
                if(clickedObject != nullptr){
                    clickedObject->isClicked(false);
                    clickedObject = nullptr;
                }

            }
        }


    //Case where nothing is hovered on press or release
    }else{
        if(clickedObject != nullptr){
            clickedObject->isClicked(false);
            clickedObject = nullptr;
        }
        if(mousePressedObject != nullptr){
            mousePressedObject = nullptr;
        }
    }

}



