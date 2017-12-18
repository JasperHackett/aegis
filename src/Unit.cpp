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
    this->addSprite(objectMgrPtr->getTexture("rings"),"aa");
    this->addSprite(objectMgrPtr->getTexture("healthbar"),"healthbar");
    this->setTextureRect("healthbar",sf::IntRect(0,0,50,10));
    this->addSprite(objectMgrPtr->getTexture("healthoutline"),"healthoutline");
    setTextureRect("aa",sf::IntRect(0,0,0,0));

    srand(time(NULL));
    int randomSeed = (rand() % 100 + 1);

    int statPool; //This is the amount of stats a unit is given to be distributed among strength,dexterity & intelligence
    srand(time(NULL));
    if(randomSeed >= 90){
        statPool = 50 + (rand()%40); //Case where unit rolls high and gets extra stats
    }else if(randomSeed <= 10){
        statPool = 20 + (rand()%40); //Case where unit rolls low and gets less stats with more random range
    }else{
        statPool = 40 + (rand()%30); //Standard unit distribution
    }

    //Splitting in the stats between strength,dexterity and intelligence with the aim of having an outlier stat frequently
    srand(time(NULL));
    int firstStat = (statPool/3) + (rand()%(statPool/3));
    statPool = statPool - firstStat;

    srand(time(NULL));
    int secondStat = (statPool/3) + (rand()%(statPool/3));
    statPool = statPool - secondStat;

    int thirdStat = statPool;
    srand(time(NULL));
    randomSeed = rand()%3;
    if(randomSeed == 0){
        this->strength = firstStat;
        if(secondStat%2 == 1){
            this->dexterity = secondStat;
            this->intelligence = thirdStat;
        }else{
            this->dexterity = thirdStat;
            this->intelligence = secondStat;
        }
    }else if(randomSeed == 1){
        this->dexterity = firstStat;
         if(firstStat%2 == 1){
            this->strength = secondStat;
            this->intelligence = thirdStat;
        }else{
            this->strength = thirdStat;
            this->intelligence = secondStat;
        }
    }else if (randomSeed ==2){
        this->intelligence = firstStat;
         if(firstStat%2 == 1){
            this->strength = secondStat;
            this->dexterity = thirdStat;
        }else{
            this->strength = thirdStat;
            this->dexterity = secondStat;
        }
    }

}


void Unit::setHovered(bool setHovered){
    if(setHovered){
        hovered = true;
        setSpritePosition("aa",this->getPos().left-12,this->getPos().top + 55);
        setTextureRect("aa",sf::IntRect(0,0,52,8));
    }else{
        hovered = false;
        if(clicked == false){
            setTextureRect("aa",sf::IntRect(0,0,0,0));
        }

    }

}

     //Called when object is clicked
void Unit::isClicked(bool toggleClick){

        std::list<AbilityButton>::iterator iterator;
        if(toggleClick){

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
                setTextureRect("aa",sf::IntRect(0,0,0,0));
                for(iterator = displayedActions.begin(); iterator != displayedActions.end(); ++iterator){
                    iterator->rendered = false;
                }
                objectMgrPtr->removeObjects();
            }


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

        int textInt = (122 - iterator->getTextWidth("labelText"))/2;
        iterator->setTextPosition("labelText",this->getPos().left + 40 + textInt,startingY + 32*i + 6);
        i++;
    }

}

//Adds a move to displayedActions
void Unit::addMove(){
    actions actionTypeIn;
    actionTypeIn = attack;
    AbilityButton newAbilBtn("atk_generic",objectMgrPtr,"Attack");

    this->actionCount ++;

    switch(actionTypeIn){

        case attack :
            newAbilBtn.addSprite(objectMgrPtr->getTexture("abilityBtn"),"abilityBtn");
            newAbilBtn.setTextureRect("abilityBtn",sf::IntRect(0,0,122,32));
            this->displayedActions.push_back(newAbilBtn);


            break;

        default :
            break;


    }

    positionActions();

}
//Adds a move to displayedActions defining the label
void Unit::addMove(actions actionTypeIn, std::string label){


}

void Unit::setHealth(int healthDeduction){
    this->health = health-healthDeduction;
    if(health > 50){
        int newHealthbarWidth = health/2;
        setTextureRect("healthbar",sf::IntRect(0,0,newHealthbarWidth,10));
    }else if (health > 10){
        int newHealthbarWidth = health/2;
        setTextureRect("healthbar",sf::IntRect(50,0,newHealthbarWidth,10));
    }else if(health > 0){
        int newHealthbarWidth = health/2;
        setTextureRect("healthbar",sf::IntRect(80,0,newHealthbarWidth,10));
    }

}
