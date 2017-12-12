#include <Unit.hpp>

Unit::Unit()
{
    //ctor
}


Unit::~Unit()
{
    //dtor
}

Unit::Unit(ObjectManager* objectMgrPtr, ClickManager* clickMgrPtr){
    this->clickMgrPtr = clickMgrPtr;
    this->objectMgrPtr = objectMgrPtr;
}

     //Called when object is clicked
void Unit::isClicked(bool toggleClick){

        std::list<AbilityButton>::iterator iterator;
        if(toggleClick){

            //Read value into string and output to main text log
            std::string output;
            std::ostringstream str1;
            str1 << simpleAttack;
            output = str1.str();
            mainTextLog->addText(output);
            //Reset string stream
            str1.str("");
            str1.clear();

            if(clicked == false){
                for(iterator = displayedActions.begin(); iterator != displayedActions.end(); ++iterator){
                        objectMgrPtr->addVisible(&*iterator);
                        clickMgrPtr->addObject(&*iterator);
                        clickMgrPtr->addNested(&*iterator);

                }
            }

            this->clicked = true;

        }else{
            this->clicked = false;

            if(clicked == false){

                for(iterator = displayedActions.begin(); iterator != displayedActions.end(); ++iterator){
                    iterator->rendered = false;
                }
                objectMgrPtr->removeObjects();
            }


        }
}

void Unit::draw(sf::RenderWindow &window){
    std::map<std::string,sf::Sprite>::iterator it;
    for(it = spriteMap.begin(); it != spriteMap.end(); it++){
        window.draw(it->second);
    }
}



//Distributes the action buttons evenly adjacent to the characters position.
void Unit::positionActions(){

    int startingY = this->getPos().top - (this->actionCount*32)/2;

    std::list<AbilityButton>::iterator iterator;

    int i = 0;
    for(iterator = displayedActions.begin(); iterator != displayedActions.end(); ++iterator){
        iterator->setPos(sf::IntRect(this->getPos().left + 40,startingY + 32*i,122,32));
        iterator->setSpritePosition("abilityBtn",this->getPos().left + 40,startingY + 32*i);
        iterator->setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));
        i++;
    }

}

//Adds a move to displayedActions
void Unit::addMove(actions actionTypeIn){

    AbilityButton attackButton("test",objectMgrPtr,"Attack");

    this->actionCount ++;

    switch(actionTypeIn){

        case attack :
            attackButton.addSprite(objectMgrPtr->getTexture("abilityBtn"),"abilityBtn");
            attackButton.setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));
            this->displayedActions.push_back(attackButton);

            break;

        default :
            break;


    }

    positionActions();

}
//Adds a move to displayedActions defining the label
void Unit::addMove(actions actionTypeIn, std::string label){


}
