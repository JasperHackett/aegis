#include <Unit.hpp>

Unit::Unit()
{
    //ctor
}

Unit::Unit(ObjectManager* objectMgrIn, ClickManager* clickMgrIn){
    this->objectMgrPtr = objectMgrIn;
    this->clickMgrPtr = clickMgrIn;

//    this->attackButton.addSprite(objectMgrPtr->getTexture("abilityBtn"),"abilityBtn");
//    this->testAttackButton.addSprite(objectMgrPtr->getTexture("abilityBtn"),"abilityBtn");
//    this->attackButton.setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));
//    this->testAttackButton.setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));
//
//    this->attackButton.setMainTextLog(this->mainTextLog);
//    this->testAttackButton.setMainTextLog(this->mainTextLog);
//
//    this->displayedActions[0] = &attackButton;
//    this->displayedActions[1] = &testAttackButton;
//
//    this->reserveSpace = sf::IntRect(0,0,122,32);

}


Unit::~Unit()
{
    //dtor
}


void Unit::isClicked(bool toggleClick){
        if(toggleClick){
            this->reserveSpace = sf::IntRect(0,0,1200,1200);
            std::string output;
            std::ostringstream str1;
            str1 << simpleAttack;
            output = str1.str();
            mainTextLog->addText(output);
            str1.str("");
            str1.clear();
            this->clicked = true;
            for(int i = 0; i < actionCount; i++){
//                if(displayedActions[i] != nullptr){
//                    clickMgrPtr->addObject(displayedActions[i]);
//                    std::cout << "test" << std::endl;
//                }
            }

        }else{
            this->clicked = false;

        }
}

void Unit::draw(sf::RenderWindow &window){
    std::map<std::string,sf::Sprite>::iterator it;
    for(it = spriteMap.begin(); it != spriteMap.end(); it++){
        window.draw(it->second);
    }
    /*
        NOTE that this implementation where each unit checks if clicked on each draw call is inefficient,
        ideally implement this in ClickManager (this implementation makes multi-click objects simpler)
    */
    if(clicked){
        for(int i = 0; i < actionCount; i++){
            if(displayedActions[i] != nullptr){
                displayedActions[i]->draw(window);
            }
        }
    }

}




void Unit::positionActions(){

    int startingY = this->getPos().top - (this->actionCount*32)/2;

    for(int i = 0; i < this->actionCount; i++){
        displayedActions[i]->setPos(sf::IntRect(this->getPos().left + 40,startingY + 32*i,122,32));
        displayedActions[i]->setSpritePosition("abilityBtn",this->getPos().left + 40,startingY + 32*i);
    }



}

//Adds a move to displayedActions
void Unit::addMove(actions actionTypeIn){
    this->actionCount ++;


    switch(actionTypeIn){

        case attack :
            this->attackButton.addSprite(objectMgrPtr->getTexture("abilityBtn"),"abilityBtn");
            this->attackButton.setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));
            this->attackButton.setMainTextLog(this->mainTextLog);
            this->displayedActions.insert(std::pair<actions,Clickable*>(actionTypeIn&attackButton));
            break;

        default :
            break;


    }

}
void Unit::addMove(actions actionTypeIn, std::string label){


}
