
#include <Clickable.hpp>




class AttackBtn : public Clickable{

public:


    AttackBtn(){}
    ~AttackBtn(){}

//    void setButtonText(std::string textIn){
//        this->buttonText.Text(textIn,sf::Font)
//    }


    void isClicked(bool toggleClick){

        if(toggleClick){
            this->clicked = true;
        }else{
            this->clicked = false;


            //Disable clicked properties
        }
}

    void setHovered(bool setHovered){
        if(setHovered){
            hovered = true;
            std::cout << "calling remove Object" << std::endl;
            this->setTextureRect("abilityBtn",sf::IntRect(122,0,122,32));
        }else{
            hovered = false;
            this->setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));

        }

    }


};
