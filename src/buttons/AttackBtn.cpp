
#include <Clickable.hpp>




class AttackBtn : public Clickable{

public:

    sf::Text buttonText;

    AttackBtn(){}
    ~AttackBtn(){}

//    void setButtonText(std::string textIn){
//        this->buttonText.Text(textIn,sf::Font)
//    }


    void isClicked(bool toggleClick){

        if(toggleClick){
            //this->mainTextLog->addText("Attack Button Pressed");
            this->clicked = true;
        }else{
            this->clicked =  false;
            //Disable clicked properties
        }
}

    void setHovered(bool setHovered){
        if(setHovered){
            this->setTextureRect("abilityBtn",sf::IntRect(122,0,122,32));
        }else{
            this->setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));

        }

    }


};
