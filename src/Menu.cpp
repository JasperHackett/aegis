
#include <Menu.hpp>



    Menu::Menu(){}

    Menu::Menu(ObjectManager* objectMgrPtr, ClickManager* hoverMgrPtr){
        this->objectMgrPtr = objectMgrPtr;
        this->clickMgrPtr = hoverMgrPtr;

    }


    Menu::~Menu(){}

    //Draws each clickable in the menu as well as enables hover checking
    void Menu::enableMenu(bool enable){

        std::map<std::string,Clickable>::iterator it;
        objectMgrPtr->addVisible(&attackButton);
        clickMgrPtr->addObject(&attackButton);
        for(it = menuMap.begin(); it != menuMap.end(); it++){

            //clickMgrPtr->addObject(&it->second);

        }


    }



    void Menu::addClickable(){

        //AttackBtn newClickable;
        attackButton.addSprite(objectMgrPtr->getTexture("abilityBtn"),"abilityBtn");
        attackButton.setSpritePosition("abilityBtn",300,300);
        attackButton.setPos(sf::IntRect(0,0,122,30));
        attackButton.setTextureRect("abilityBtn",sf::IntRect(0,0,122,30));
        //menuMap.insert(std::pair<std::string,Clickable>("abilityBtn",attackButton));


    }



