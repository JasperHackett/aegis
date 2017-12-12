#ifndef UNIT_H
#define UNIT_H


#include <buttons.hpp>
#include <sstream>
#include <string>
#include <buttons.hpp>
#include <list>
#include <Clickable.hpp>



class Unit : public Clickable
{

    public:
        Unit();
        Unit(ObjectManager* objectMgrPtr, ClickManager* clickMgrPtr);
        virtual ~Unit();

        //Called when objects click state changes, true for clicked, false for disable clicked
        virtual void isClicked(bool toggleClick);

        //Adds a move to displayedActions
        virtual void addMove(actions actionTypeIn);
        //Adds a move to displayedActions defining the label
        virtual void addMove(actions actionTypeIn, std::string label);

        //Re-declaration of draw method
        void draw(sf::RenderWindow &window);

        //Distributes the action buttons evenly adjacent to the characters position.
        virtual void positionActions();

        std::list<AbilityButton> displayedActions; // Stores visible action buttons (actions = {attack,block,stance,movepos,item,special})
        int actionCount = 0; //How many actions this unit can take
        actions actionType; //actions = {attack,block,stance,movepos,item,special}
        bool hasNestedClickables = true; //true if this object has multiple click options

        //Unit stats
        int health = 10;
        int simpleAttack = 5; /*testing*/




    protected:

    private:


};

#endif // UNIT_H
