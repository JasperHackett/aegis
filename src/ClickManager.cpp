#include "ClickManager.hpp"
#include <iostream>

ClickManager::ClickManager()
{
    //ctor
}

ClickManager::~ClickManager()
{
    //dtor
}
void ClickManager::setWindowPtr(sf::RenderWindow* window){
    this->windowPtr = window;
}

ClickManager::ClickManager(GameController* gameMgrPtr){
    this->gameMgrPtr = gameMgrPtr;
}

//Adds object to vector of objects that interact with the mouse (hovering & clicking)
void ClickManager::addObject(Clickable* objectIn){
    objectIn->hoverable = true;
    visibleObjects.push_back(objectIn);
}
//Removes object from visibleObjects
void ClickManager::removeObject(Clickable* objectToBeRemoved){
    std::cout << "calling remove Object" << std::endl; //TESTING
    visibleObjects.erase(std::remove(visibleObjects.begin(),visibleObjects.end(),objectToBeRemoved), visibleObjects.end());

}


void ClickManager::addNested(Clickable* objectIn){
    objectIn->hoverable = true;
    nestedObjects.push_back(objectIn);
}


/*Called each frame to check if the mouse position is inside the bounds of any visibleObject*/
void ClickManager::checkHover(sf::Vector2i mousePos){

    this->mousePos = mousePos;
    somethingHovered = false;

    //Iterate through visibleObjects and update hoveredObject
    for(Clickable* object : visibleObjects){
        if(object->getPos().contains(mousePos)){
            somethingHovered = true;
            if(hoveredObject != object){
                if(hoveredObject != nullptr){
                    hoveredObject->setHovered(false);
                }
                hoveredObject = object;
                hoveredObject->setHovered(true);
            }
        }
    }
    //Check for nested clickables
//    if(clickedObject->hasNestedClickable){
//        for(Clickable* object : nestedObjects){
//            if(object->getPos().contains(mousePos)){
//                somethingHovered = true;
//                if(hoveredObject != object){
//                    if(hoveredObject != nullptr){
//                        hoveredObject->setHovered(false);
//                    }
//                    hoveredObject = object;
//                    hoveredObject->setHovered(true);
//                }
//            }
//        }
//    }



    //Case where nothing is hovered and an object is still in hovered state
    if(somethingHovered == false && hoveredObject != nullptr){
        hoveredObject->setHovered(false);
        hoveredObject = nullptr;
        somethingHovered = false;
    }


}

/*Called on left mouse event. mouseDown = true for pressed. mouseDown = false for released*/
void ClickManager::leftMouseClick(bool mouseDown){

    if(hoveredObject != nullptr){
        //Case where mouse pressed
        if(mouseDown){
            mousePressedObject = hoveredObject;
            if(clickedObject != nullptr){
                //Case where clicked object is not moused down object
                if(clickedObject != mousePressedObject){
                    if(clickedObject->hasNestedClickable == false){// ADD nestedClickable
                        clickedObject->isClicked(false);
                        clickedObject = nullptr;
                    }
                }
            }


        //Case where mouse released
        }else{
           //When mouse is released and something was pressed on
            if(mousePressedObject != nullptr){

                //Case where mouse is released while hovering over object that was moused down on (SUCCESSFUL CLICK)
                if(mousePressedObject == hoveredObject){

                    //Case where an object is already clicked that has nested clickables (e.g. clicking on a player character)
                    if(clickedObject != nullptr){

                        if(clickedObject->hasNestedClickable){
                            //Call on the Clickable to check if mousePRessedObject points to an object nested within it
                            parentObject = clickedObject;
                            if(this->checkNested()){
                                clickedObject->isClicked(false);
                                sendMove(mousePressedObject->returnID());
                                parentObject = nullptr;
                                clickedObject = nullptr;

                            }else{
                                 clickedObject->isClicked(false);
                                clickedObject = mousePressedObject;
                                clickedObject->isClicked(true);

                            }
                        }else{
                            clickedObject->isClicked(false);
                            clickedObject = mousePressedObject;
                            clickedObject->isClicked(true);
                        }


                    }else{
                        clickedObject = mousePressedObject;
                        clickedObject->isClicked(true);
                    }

                }

            //Nothing clicked on
            }else{
                if(clickedObject != nullptr){
                    clickedObject->isClicked(false);
                    clickedObject = nullptr;
                }

            }
        }


    //Case where nothing is hovered on press or release
    }else{
        if(clickedObject != nullptr){
            clickedObject->isClicked(false);
            clickedObject = nullptr;
        }
        if(mousePressedObject != nullptr){
            mousePressedObject = nullptr;
        }
    }

}


bool ClickManager::checkNested(){
    if(clickedObject != nullptr){
        for(Clickable* object : nestedObjects){

            if(mousePressedObject == object){
                    /* POTENTIAL SPOT TO RETURN actionID to clickedObject*/
                return true;
            }
        }
    }
    return false;
}


void ClickManager::returnNestedValue(std::string valueIn){
        parentObject->isClicked(false);
        //sendMove(parentObject->returnID(valueIn);
}

void ClickManager::exitGame(){
    windowPtr->close();
}

void ClickManager::startGame(){
    gameMgrPtr->startGame(this);
    currentGameState = playing;
}

void ClickManager::sendGameMgr(std::string data){
//    gameMgrPtr->sendMove

}

void ClickManager::sendMove(std::string moveIn){
    std::cout <<"test " <<std::endl;
    if(moveIn == "exit"){
        exitGame();
    }
    if(moveIn == "start"){
            std::cout <<"test " << std::endl;

        startGame();

    }
    if(moveIn == "atk_generic"){

        //parentObject->

         /*This function needs to pass the target and the caster*/
        gameMgrPtr->sendTurn(true,"frog","atk_generic");

    }

}




