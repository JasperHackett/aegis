#include <buttons/AbilityButton.hpp>

AbilityButton::AbilityButton()
{
    //ctor
}

AbilityButton::~AbilityButton()
{
    //dtor
}

//Constructer with set actionID defined
AbilityButton::AbilityButton(std::string actionID, ObjectManager* objectMgrPtr, std::string labelText){
    this->objectMgrPtr = objectMgrPtr;

    this->addText(objectMgrPtr->getFont("trebuc"),"labelText",labelText,sf::Color::Black,16);

    this->actionID = actionID;

}

void AbilityButton::setHovered(bool setHovered){
    if(setHovered){
        hovered = true;
        setTextureRect("abilityBtn",sf::IntRect(122,0,122,32));
    }else{
        hovered = false;
        setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));
    }

}

//Called when the button is clicked
std::string AbilityButton::returnID(){
    return this->actionID;
}


//True when object is clicked. False when mouse clicks outside bounds of object
void AbilityButton::isClicked(bool toggleClick){

        if(toggleClick){
            this->clicked = true;
        }else{
            this->clicked =  false;
            //Disable clicked properties
        }
}
