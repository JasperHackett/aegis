#include <GameController.hpp>
#include <iostream>
GameController::GameController(){
}

GameController::GameController(ObjectManager* objectMgrPtr, TextLog* mainEventLog){
    this->objectMgrPtr = objectMgrPtr;
    this->mainTextLog = mainEventLog;
}

GameController::~GameController()
{
    //dtor
}

///*FOR TESTING THIS CREATES A BASIC ARMY AND OPPONENT*/
GameController* GameController::startGame(ClickManager *clickMgrPtr){

    this->clickMgrPtr = clickMgrPtr;


    topMenuBar.addSprite(objectMgrPtr->getTexture("topbar"),"topbar");
    topMenuBar.setPos(sf::IntRect(0,0,1600,20));
    topMenuBar.setSpritePosition("topbar",0,0);
    topMenuBar.setTextureRect("topbar",sf::IntRect(0,0,1600,20));
    objectMgrPtr->addVisible(&topMenuBar);

    DropDownMenu controlMenu(objectMgrPtr,clickMgrPtr);
    controlMenu.addSprite(objectMgrPtr->getTexture("menubtn"),"primary");
    controlMenu.setTextureRect("primary",sf::IntRect(0,0,200,20));
    controlMenu.addBtn("dropdownbtn","Exit game","dropdownbtn");
    controlMenu.addBtn("dropdownbtn","Exit game","dropdownbtn");
    controlMenu.addBtn("dropdownbtn","Exit game","dropdownbtn");
    controlMenu.setPos(sf::IntRect(0,0,60,20));
    gameMenuDropdowns.push_back(controlMenu);

    objectMgrPtr->addVisible(&gameMenuDropdowns.back());
    clickMgrPtr->addObject(&gameMenuDropdowns.back());





    /*Basic combat*/
//    currentGameState = combat;
//    currentGameState = board;
//    Unit meleeChar(objectMgrPtr, clickMgrPtr);
//    meleeChar.hasNestedClickable = true; //Should not be defined here
//    meleeChar.addSprite(objectMgrPtr->getTexture("meleeUnit"),"body");
//    meleeChar.setTextureRect("body",sf::IntRect(40,0,40,60));
//    meleeChar.setSpritePosition("body",550,490);
//    meleeChar.setSpritePosition("healthbar",540,555);
//    meleeChar.setSpritePosition("healthoutline",540,555);
//
//
//    meleeChar.setPos(sf::IntRect(550,490,40,60));
//    meleeChar.addMove();
//
//    playerArmy.insert(std::pair<std::string,Unit>("main",meleeChar));
//
//    Unit enemy(objectMgrPtr, clickMgrPtr);
//    enemy.addSprite(objectMgrPtr->getTexture("frog"),"body");
//    enemy.setSpritePosition("body",950,490);
//    enemy.setPos(sf::IntRect(950,490,80,60));
//    enemy.setSpritePosition("healthbar",940,555);
//    enemy.setSpritePosition("healthoutline",940,555);
//
//    enemyArmy.insert(std::pair<std::string,Unit>("frog",enemy));
//    addArmyToRender(false);
//    addArmyToRender(true);
    return this;
}

//void GameController::sendTurn(bool isPlayerArmy, std::string targetUnit, std::string actionID){
//
//    if(isPlayerArmy){
//        if(actionID == "atk_melee");
//            //playerArmy.at(targetUnit).
//            srand(time(NULL));
//            int attackOut = (playerArmy.at("main").strength  / (rand()%3 + 2)) + (playerArmy.at("main").weaponAtk / (rand()%2 + 1));
//
//            //Generate output
//            std::string dmgString;
//            std::ostringstream str1;
//            str1 << attackOut;
//            dmgString = str1.str();
//            std::string output = "You attack the frog for: " + dmgString;
//            playerArmy.at("main").setHealth(attackOut);
//            mainTextLog->addText(output);
//
//            str1.str("");
//            dmgString = "";
//
//            attackOut = (enemyArmy.at("frog").weaponAtk);
//            str1 << attackOut;
//            dmgString = str1.str();
//            output = "The frog attacks you for: " + dmgString;
//            enemyArmy.at("frog").setHealth(attackOut);
//            mainTextLog->addText(output);
//            //GameController::generateMove
//
//    }
//
//}

//int GameController::calculateAttack(*playerArmy.at(targetUnit),)

//void GameController::addArmyToRender(bool isPlayerArmy){
//    if(isPlayerArmy){
//        std::map<std::string,Unit>::iterator it;
//        for(it = playerArmy.begin(); it != playerArmy.end(); it++){
//            objectMgrPtr->addVisible(&it->second);
//            clickMgrPtr->addObject(&it->second);
//        }
//    }else{
//        std::map<std::string,Unit>::iterator it;
//        for(it = enemyArmy.begin(); it != enemyArmy.end(); it++){
//            objectMgrPtr->addVisible(&it->second);
//            clickMgrPtr->addObject(&it->second);
//        }
//
//    }
//
//}
//
//actionID GameController::generateMove(//UNIT){}
