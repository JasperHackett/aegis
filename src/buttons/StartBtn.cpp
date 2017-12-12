
#include <Clickable.hpp>




class StartBtn : public Clickable{

public:

    using Clickable::Clickable;

    StartBtn(){}
    ~StartBtn(){}


    void isClicked(bool toggleClick){

        if(toggleClick){
            mainTextLog->addText("Game starting.");
            this->clicked = true;
        }else{
            this->clicked =  false;
            //Disable clicked properties
        }
}

    void setHovered(bool setHovered){
        if(setHovered){
            hovered = true;
            this->setTextureRect("button",sf::IntRect(156,0,156,40));
        }else{
            hovered = false;
            this->setTextureRect("button",sf::IntRect(0,0,156,40));

        }

    }

};
