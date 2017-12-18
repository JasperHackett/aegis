#ifndef CLICKMANAGER_H
#define CLICKMANAGER_H

    #include <global.hpp>
    #include <SFML/graphics.hpp>
    #include <Clickable.hpp>
    #include <Game.hpp>
    #include <map>
    #include <buttons/GenericBtn.hpp>
<<<<<<< HEAD
    #include <GameController.hpp>
    #include <BoardController.hpp>

class Clickable; //Forward declaration
class Game;
class GameController;
=======
    #include <BoardController.hpp>


class Clickable; //Forward declaration
class Game;
>>>>>>> 5ab01b6a44594a9c060eae5a5931b1b6a356bc9c
class BoardController;

class ClickManager
{
    public:
        ClickManager();
<<<<<<< HEAD
        ClickManager(GameController* gameMgrPtr, BoardController* boardMgrPtr);
=======
        ClickManager(BoardController* boardMgrPtr);
>>>>>>> 5ab01b6a44594a9c060eae5a5931b1b6a356bc9c
        virtual ~ClickManager();

        //Adds object to vector of objects that interact with the mouse (hovering & clicking)
        virtual void addObject(Clickable* objectIn);

        //Removes object from visibleObjects
        virtual void removeObject(Clickable* objectToBeRemoved);

        //Called each frame to check if the mouse position is inside the bounds of any visibleObject
        virtual void checkHover(sf::Vector2i mousePos);

        //Called when a left mouse event occurs. True when left mouse is pressed, false when released
        virtual void leftMouseClick(bool mouseDown);

        //Checks the nestedObject vector for a click
        virtual bool checkNested();

        virtual void addNested(Clickable* objectIn);

        //Receives value from nested object and passes it to parent
        virtual void returnNestedValue(std::string valueIn);

        virtual void setWindowPtr(sf::RenderWindow* window);

        virtual void sendGameMgr(std::string data);
        virtual void sendMove(std::string moveIn);


        virtual void startGame();
        virtual void exitGame();
        gameStates currentGameState;

    protected:

    private:
        std::vector<Clickable*> visibleObjects;  //Stores all objects with hover properties
        std::vector<Clickable*> nestedObjects; //Stores objects nested in another objec

        bool somethingHovered = false; //True if mouse is hovering over an object in visibleObjects/nestedObjects vector

        sf::Vector2i mousePos; //mouse position updated each frame

<<<<<<< HEAD
        GameController *gameMgrPtr;
=======
>>>>>>> 5ab01b6a44594a9c060eae5a5931b1b6a356bc9c
        BoardController *boardMgrPtr;
        Game* activeGame; //Stores a ptr to the active game
        sf::RenderWindow* windowPtr;

        //Stores active object in several states. (mousePressedObject is an object that has been pressed but not released on)
        Clickable* hoveredObject = nullptr;
        Clickable* mousePressedObject = nullptr;
        Clickable* clickedObject = nullptr;



        Clickable* parentObject = nullptr; //Stores the parent of an object with nested clicks.



};

#endif // CLICKMANAGER_H
