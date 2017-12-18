#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include <TextLog.hpp>
#include <global.hpp>
#include <Game.hpp>
#include <Unit.hpp>
#include <string>

class BoardController
{
    public:
        BoardController();
        BoardController(ObjectManager* objectMgrPtr,TextLog* mainEventLog);
        virtual ~BoardController();

        virtual BoardController* startGame(ClickManager* clickMgrPtr);


        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
        TextLog* mainTextLog;



    protected:

    private:
};

#endif // BOARDCONTROLLER_H
