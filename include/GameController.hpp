#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H


#include <Game.hpp>
#include <TextLog.hpp>
#include <string>
#include <Unit.hpp>
#include <DropDownMenu.hpp>
class DropDownMenu;
class Unit;

class GameController
{
    public:
        GameController();
        GameController(ObjectManager* objectMgrPtr,TextLog* mainEventLog);
        virtual ~GameController();

//        virtual void sendTurn(bool isPlayerArmy, std::string targetUnit, std::string actionID);

       // virtual void addArmyToRender(bool isPlayerArmy);
        virtual GameController* startGame(ClickManager* clickMgrPtr);

        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
        std::map<std::string,Unit> playerArmy;
        std::map<std::string,Unit> enemyArmy;
        TextLog* mainTextLog;

        RenderObject topMenuBar;
        std::list<DropDownMenu> gameMenuDropdowns;

    protected:

    private:

};

#endif // GAMECONTROLLER_H
