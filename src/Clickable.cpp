#include "Clickable.hpp"
#include <iostream>

Clickable::Clickable()
{
    //ctor
}

Clickable::~Clickable()
{
    //dtor
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
        std::cout << "Generic object hovered" << std::endl;
    }else{
       std::cout << "Object un-hovered" << std::endl;
    }

}

