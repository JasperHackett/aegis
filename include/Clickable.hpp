#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <iostream>
#include <RenderObject.hpp>
#include <TextLog.hpp>

class ObjectManager;
class ClickManager;


class Clickable : public RenderObject{

    public:
        Clickable();
        Clickable(ObjectManager* objectMgrPtr, std::string labelText); //Constructer for giving a text label to the object. Useful for buttons
        virtual ~Clickable();

        /*Methods*/
        // Constructer to assign pointers to ObjectMgr and ClickMgr
        Clickable(ObjectManager* objectMgrIn, ClickManager* clickMgrIn);

        virtual void isClicked(bool toggleClick);

        //Set true when mouse hovers over an object, false when it hovers off of the object
        virtual void setHovered(bool setHovered);

        //Sets main text output for this instance of class
        virtual void setMainTextLog(TextLog* TextLogIn);

        //Called when this clickable requires you to select another object (e.g. A unit choosing an enemy to attack)
        //virtual std::string targetObject();

        void setHoverValue(sf::IntRect hoverValIn);
        void setDefaultPos(sf::IntRect defaultValIn);
        void setClickedPos(sf::IntRect clickedValIn);

        virtual std::string returnID();

        /*Variables*/
        bool hasNestedClickable = false;
        bool clicked = false;
        bool hovered = false;
        bool hoverable = false;


        sf::IntRect hoverPos;
        sf::IntRect defaultPos;
        sf::IntRect clickedPos;


        TextLog* mainTextLog;//Main destination for text outputs from this object
        std::string actionID;

        // Stores pointer to main object manager and main click manager
        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;

    protected:

    private:

};

#endif // CLICKABLE_H
