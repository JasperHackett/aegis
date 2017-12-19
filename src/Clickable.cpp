#include "Clickable.hpp"
#include <DropDownMenu.hpp>
#include <ClickManager.hpp>
#include <iostream>

Clickable::Clickable(){}
Clickable::~Clickable(){}

// Constructer to assign pointers to ObjectMgr and ClickMgr
Clickable::Clickable(ObjectManager* objectMgrIn, ClickManager* clickMgrIn){
            this->objectMgrPtr = objectMgrIn;
            this->clickMgrPtr = clickMgrIn;
}



//Assign main text log pointer
void Clickable::setMainTextLog(TextLog* TextLogIn){
    mainTextLog = TextLogIn;
}

//True when object is clicked. False when mouse clicks outside bounds of object
void Clickable::isClicked(bool toggleClick){

        if(toggleClick){
            std::cout << "Object clicked" << std::endl;
            this->clicked = true;
        }else{
            this->clicked =  false;
            //Disable clicked properties
        }
}


////Set true when mouse hovers over an object, false when it hovers off of the object
void Clickable::setHovered(bool setHovered){
    if(setHovered){
        hovered = true;
    }else{
        hovered = false;
       std::cout << "Object un-hovered" << std::endl;
    }

}

std::string Clickable::returnID(){
    return actionID;
}

void Clickable::setHoverValue(sf::IntRect hoverValIn){
    this->hoverPos = hoverValIn;
}

void Clickable::setDefaultPos(sf::IntRect defaultValIn){
    this->defaultPos = defaultValIn;
}
