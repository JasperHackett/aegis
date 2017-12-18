#ifndef UNIT_H
#define UNIT_H

#include <Clickable.hpp>
#include <buttons/AbilityButton.hpp>
#include <sstream>
#include <string>
#include <list>
#include <ObjectManager.hpp>
#include <ClickManager.hpp>
#include <random>
#include <time.h>
//class ObjectManager;
//class ClickManager;



class Unit : public Clickable
{

    public:
        Unit();
        Unit(ObjectManager* objectMgrPtr, ClickManager* clickMgrPtr);
        virtual ~Unit();

        //Called when objects click state changes, true for clicked, false for disable clicked
        virtual void isClicked(bool toggleClick);

        //Adds a move to displayedActions
        enum actions {attack,block,stance,movepos,item,special};
        virtual void addMove();
        //Adds a move to displayedActions defining the label
        virtual void addMove(actions actionTypeIn, std::string label);

        virtual void setHovered(bool setHovered);

        virtual void setHealth(int healthDeduction);
        //Distributes the action buttons evenly adjacent to the characters position.
        virtual void positionActions();

        std::list<AbilityButton> displayedActions; // Stores visible action buttons (actions = {attack,block,stance,movepos,item,special})
        int actionCount = 0; //How many actions this unit can take
        actions actionType; //actions = {atta

        bool hasNestedClickables = true; //true if this object has multiple click options

        //Unit stats

        int health = 100;
        int strength;
        int dexterity;
        int intelligence;
        int weaponAtk = 10; /*Initialised for testing purposes */

         //ack,block,stance,movepos,item,special}




    protected:

    private:


};

#endif // UNIT_H
