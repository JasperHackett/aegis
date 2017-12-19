
#include <buttons/GenericBtn.hpp>


    GenericBtn::GenericBtn(){}


    //Constructer for giving a text label to the object. Useful for buttons
    GenericBtn::GenericBtn(ObjectManager* objectMgrPtr, std::string labelText){
        this->objectMgrPtr = objectMgrPtr;
        this->addText(objectMgrPtr->getFont("trebuc"),"labelText",labelText,sf::Color::Black,16);
    }

    GenericBtn::GenericBtn(ClickManager* clickMgrPtr){
        this->clickMgrPtr = clickMgrPtr;
    }
    GenericBtn::GenericBtn(ClickManager* clickMgrPtr,std::string actionIDIn){
        this->clickMgrPtr = clickMgrPtr;
        this->setActionID(actionIDIn);
    }

    GenericBtn::~GenericBtn(){}




    void GenericBtn::isClicked(bool toggleClick){

        if(toggleClick){
            clickMgrPtr->sendMove(actionID);
            this->clicked = true;

        }else{
            this->clicked =  false;
            //Disable clicked properties
        }
}

    void GenericBtn::setHovered(bool setHovered){
        if(setHovered){
            hovered = true;
            this->setTextureRect("button",hoverPos);
        }else{
            hovered = false;
            this->setTextureRect("button",defaultPos);

        }

    }


    void GenericBtn::setActionID(std::string actionIDIn){
        this->actionID = actionIDIn;
    }
    std::string GenericBtn::getActionID(){
        return this->actionID;
    }





