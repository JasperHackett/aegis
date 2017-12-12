
#include <Clickable.hpp>




class ExitBtn : public Clickable{

public:

    using Clickable::Clickable;

    ClickManager* clickMgrPtr;

    ExitBtn(){}
    ExitBtn(ClickManager* clickMgrPtr){
        this->clickMgrPtr = clickMgrPtr;
    }
    ~ExitBtn(){}


    void isClicked(bool toggleClick){

        if(toggleClick){
            mainTextLog->addText("Exiting");
            clickMgrPtr->exitGame();
            this->clicked = true;

        }else{
            this->clicked =  false;
            //Disable clicked properties
        }
}

    void setHovered(bool setHovered){
        if(setHovered){
            hovered = true;
            this->setTextureRect("button",sf::IntRect(120,0,120,40));
        }else{
            hovered = false;
            this->setTextureRect("button",sf::IntRect(0,0,120,40));

        }

    }

};
