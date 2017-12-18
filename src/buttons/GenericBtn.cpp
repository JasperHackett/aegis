
#include <buttons/GenericBtn.hpp>


    GenericBtn::GenericBtn(){}
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
            this->setTextureRect("button",hoverValue);
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


    void GenericBtn::setHoverValue(sf::IntRect hoverValIn){
        this->hoverValue = hoverValIn;
    }

    void GenericBtn::setDefaultPos(sf::IntRect defaultValIn){
        this->defaultPos = defaultValIn;
    }

