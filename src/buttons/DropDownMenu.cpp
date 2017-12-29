#include <DropDownMenu.hpp>

DropDownMenu::DropDownMenu()
{
    //ctor
}
//Passes pointers to the object. Required for most member functions to work
DropDownMenu::DropDownMenu(ObjectManager* objectMgrPtr, ClickManager* clickMgrPtr)
{
    this->objectMgrPtr = objectMgrPtr;
    this->clickMgrPtr = clickMgrPtr;
}

DropDownMenu::~DropDownMenu(){}

//Adds and a button to the menu using an existing buttonAssetID
void DropDownMenu::addBtn(std::string buttonID, std::string labelIn, std::string actionIDIn){
    GenericBtn newBtn(this->objectMgrPtr,this->clickMgrPtr, labelIn, actionIDIn);
    newBtn.addSprite(objectMgrPtr->getTexture(this->buttonAssetID),"button");
    newBtn.setDefaultPos(sf::IntRect(0,0,200,20));
    newBtn.setHoverValue(sf::IntRect(201,0,200,20));
    newBtn.addText(objectMgrPtr->getFont("trebuc"),"labelText",labelIn,sf::Color::Black,16);
    newBtn.setTextureRect("button",newBtn.defaultPos);
    this->buttons.push_back(newBtn);

    positionButtons();

}

//Adds and a button to the menu and sets the buttonAssetID
void DropDownMenu::addBtn(std::string buttonID, std::string labelIn,std::string buttonAssetID,std::string actionIDIn){
    this->buttonAssetID = buttonAssetID;
    GenericBtn newBtn(this->objectMgrPtr,this->clickMgrPtr, labelIn, actionIDIn);
    newBtn.addSprite(objectMgrPtr->getTexture(buttonAssetID),"button");
    newBtn.setDefaultPos(sf::IntRect(0,0,200,20));
    newBtn.setHoverValue(sf::IntRect(201,0,200,20));
    newBtn.addText(objectMgrPtr->getFont("trebuc"),"labelText",labelIn,sf::Color::Black,16);
    newBtn.setTextureRect("button",newBtn.defaultPos);
    this->buttons.push_back(newBtn);

    positionButtons();

}
//Positions the buttons in descending order vertically down
void DropDownMenu::positionButtons(){

    int startingY = 20;

    std::list<GenericBtn>::iterator iterator;

    int i = 0;
    for(iterator = buttons.begin(); iterator != buttons.end(); ++iterator){
        iterator->setPos(sf::IntRect(this->getPos().left,startingY + 20*i,200,20));
        iterator->setSpritePosition("button",this->getPos().left,startingY + 20*i);
        iterator->setTextureRect("button",sf::IntRect(0,0,200,20));
        iterator->setTextPosition("labelText",this->getPos().left +5,startingY + 20*i);
        i++;
    }

}

void DropDownMenu::setHovered(bool setHovered){
    if(setHovered){
        if(clicked == false){
             setTextureRect("primary",hoverPos);
        }
        hovered = true;
    }else{
        if(clicked == false){
            setTextureRect("primary",defaultPos);
        }

        hovered = false;
    }

}

void DropDownMenu::isClicked(bool toggleClick){
        std::list<GenericBtn>::iterator iterator;
        if(toggleClick){

            if(clicked == false){
                for(iterator = buttons.begin(); iterator != buttons.end(); ++iterator){
                        objectMgrPtr->addVisible(&*iterator);
                        clickMgrPtr->addObject(&*iterator);
                        clickMgrPtr->addNested(&*iterator);

                }
            }
            this->setTextureRect("primary",clickedPos);
            this->clicked = true;

        }else{
            this->setTextureRect("primary",defaultPos);
            this->clicked = false;


            if(clicked == false){
                for(iterator = buttons.begin(); iterator != buttons.end(); ++iterator){
                    iterator->rendered = false;
                }
                objectMgrPtr->removeObjects();
            }


        }
}

