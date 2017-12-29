#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H


#include <global.hpp>
#include <Game.hpp>
#include <TextLog.hpp>
#include <string>
#include <Unit.hpp>
#include <DropDownMenu.hpp>
#include <GenericBtn.hpp>
class DropDownMenu;
class Unit;
class GenericBtn;

class GameController
{
    public:
        GameController();
        GameController(ObjectManager* objectMgrPtr,TextLog* mainEventLog,sf::RenderWindow* mainWindow);
        virtual ~GameController();

        virtual GameController* startGame(ClickManager* clickMgrPtr);
        virtual void optionsMenu(bool enableMenu, ClickManager* clickMgrPtr);
        virtual void changeResolution(float heightIn, float widthIn);
        virtual void setFullscreen(bool fullscreen);
        virtual void applyOptions(std::list<std::string> optionChangeList);

        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
        std::map<std::string,Unit> playerArmy;
        std::map<std::string,Unit> enemyArmy;
        TextLog* mainTextLog;
        sf::RenderWindow* mainWindow;

        RenderObject topMenuBar;
        std::list<DropDownMenu> gameMenuDropdowns;
        std::list<GenericBtn> optionMenuButtons;
        RenderObject optionsMenuBackground;

    protected:

    private:

};

#endif // GAMECONTROLLER_H
