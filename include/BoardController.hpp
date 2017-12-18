#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include<TextLog.hpp>
#include<Unit.hpp>
#include<global.hpp>
class BoardController {
    public:
        BoardController();
        BoardController(ObjectManager* objectMgrPtr,TextLog* mainEventLog);
        virtual ~BoardController();

        virtual BoardController* startGame(ClickManager* clickMgrPtr);

    private:

    protected:

        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
        TextLog* mainTextLog;


};

#endif
