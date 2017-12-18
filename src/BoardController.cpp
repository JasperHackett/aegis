#include "BoardController.hpp"

BoardController::BoardController()
{
    //ctor
}

BoardController::BoardController(ObjectManager* objectMgrPtr,TextLog* mainEventLog){
    this->objectMgrPtr = objectMgrPtr;
    this->mainTextLog = mainEventLog;
}

BoardController::~BoardController()
{
    //dtor
}


BoardController* BoardController::startGame(ClickManager* clickMgrPtr){

    this->clickMgrPtr = clickMgrPtr;
    currentGameState = board;



    return this;
}
