#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <Game.hpp>
#include <TextLog.hpp>
#include <Unit.hpp>
#include <string>
class Unit;

class GameController
{
    public:
        GameController();
        GameController(ObjectManager* objectMgrPtr,TextLog* mainEventLog);
        virtual ~GameController();

        virtual void sendTurn(bool isPlayerArmy, std::string targetUnit, std::string actionID);

        virtual void addArmyToRender(bool isPlayerArmy);
        virtual GameController* startGame(ClickManager* clickMgrPtr);

        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
//        Game gameFile;
        std::map<std::string,Unit> playerArmy;
        std::map<std::string,Unit> enemyArmy;
        TextLog* mainTextLog;

    protected:

    private:

};

#endif // GAMECONTROLLER_H
