
#include <Clickable.hpp>




class StartBtn : public Clickable{

public:

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
            this->setTextureRect("button",sf::IntRect(156,0,156,40));
        }else{
            this->setTextureRect("button",sf::IntRect(0,0,156,40));

        }

    }

};
