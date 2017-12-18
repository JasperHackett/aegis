<<<<<<< HEAD
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include<TextLog.hpp>
#include<Unit.hpp>
#include<global.hpp>
class BoardController {
=======
#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H

#include <Game.hpp>
#include <TextLog.hpp>
#include <Unit.hpp>
#include <string>

class BoardController
{
>>>>>>> 5ab01b6a44594a9c060eae5a5931b1b6a356bc9c
    public:
        BoardController();
        BoardController(ObjectManager* objectMgrPtr,TextLog* mainEventLog);
        virtual ~BoardController();
<<<<<<< HEAD

        virtual BoardController* startGame(ClickManager* clickMgrPtr);

    private:

    protected:
=======
        virtual BoardController* startGame(ClickManager* clickMgrPtr);

>>>>>>> 5ab01b6a44594a9c060eae5a5931b1b6a356bc9c

        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
        TextLog* mainTextLog;

<<<<<<< HEAD

};

#endif
=======
    protected:

    private:
};

#endif // BOARDCONTROLLER_H
>>>>>>> 5ab01b6a44594a9c060eae5a5931b1b6a356bc9c
