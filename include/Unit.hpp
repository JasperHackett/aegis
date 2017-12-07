#ifndef UNIT_H
#define UNIT_H

#include <Clickable.hpp>
#include <ClickManager.hpp>
#include <sstream>
#include <string>
#include <buttons.hpp>
#include <ObjectManager.hpp>
#include <ClickManager.hpp>
#include <list>

class Unit : public Clickable
{
    public:
        Unit();
        Unit(ObjectManager *objectMgrIn, ClickManager *clickMgrIn); // Constructer to assign pointers to ObjectMgr and ClickMgr
        virtual ~Unit();


        virtual void isClicked(bool toggleClick);



    //MEANT FOR TRANSFER TO CHARACTER CLASS
        virtual void addMove(actions actionTypeIn);
        virtual void addMove(actions actionTypeIn, std::string label);

        void draw(sf::RenderWindow &window);

        int actionCount = 0; //How many actions this unit can take
        std::list<std::pair<actions,Clickable*>> displayedActions; // Stores visible action buttons (actions = {attack,block,stance,movepos,item,special})

        virtual void positionActions();


        actions actionType;

        AttackBtn attackButton;
        AttackBtn testAttackButton;



        //Unit stats
        int health = 10;
        int simpleAttack = 5;


        sf::Sprite abilityBtnSprite;
        ObjectManager* objectMgrPtr; // Stores pointer to main object manager
        ClickManager* clickMgrPtr;


    protected:

    private:


};

#endif // UNIT_H
