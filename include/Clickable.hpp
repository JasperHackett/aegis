#ifndef CLICKABLE_H
#define CLICKABLE_H
#include <iostream>
#include <RenderObject.hpp>
#include <TextLog.hpp>
#include <ObjectManager.hpp>
#include <ClickManager.hpp>

class Clickable : public RenderObject{

    public:
        Clickable();
        virtual ~Clickable();

        /*Methods*/
        // Constructer to assign pointers to ObjectMgr and ClickMgr
        Clickable(ObjectManager* objectMgrIn, ClickManager* clickMgrIn);

        virtual void isClicked(bool toggleClick);

        //Set true when mouse hovers over an object, false when it hovers off of the object
        virtual void setHovered(bool setHovered);

        //Sets main text output for this instance of class
        virtual void setMainTextLog(TextLog* TextLogIn);

        //virtual Clickable*


        virtual void returnID(std::string actionID);

        /*Variables*/
        bool hasNestedClickable = false;
        bool clicked = false;
        bool hovered = false;
        bool hoverable = false;

        TextLog* mainTextLog;//Main destination for text outputs from this object
        std::string actionID;

        // Stores pointer to main object manager and main click manager
        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;

    protected:

    private:

};

#endif // CLICKABLE_H
