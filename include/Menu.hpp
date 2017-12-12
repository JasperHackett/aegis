
#ifndef MENU_H
#define MENU_H

#include <Clickable.hpp>
#include <buttons.hpp>
#include <map>

/* This classed is used for displaying menus. A menu is a set of Clickables*/
class Menu{


    public:

        Menu(ObjectManager *objectMgrPtr, ClickManager *clickMgrPtr);
        Menu();
        ~Menu();

        //Draws each clickable in the menu as well as enables hover checking
        virtual void enableMenu(bool enable);


        //Adds an item to menu
        virtual void addClickable();






        ObjectManager *objectMgrPtr;
        ClickManager *clickMgrPtr;
        AttackBtn attackButton;
        std::map<std::string,Clickable> menuMap;



    protected:

    private:


};

#endif // MENU_H
