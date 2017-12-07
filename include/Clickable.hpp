#ifndef CLICKABLE_H
#define CLICKABLE_H
#include <iostream>
#include <RenderObject.hpp>
#include <TextLog.hpp>

class Clickable : public RenderObject
{
    public:
        Clickable();
        virtual ~Clickable();

        virtual void isClicked(bool toggleClick);

        //Set true when mouse hovers over an object, false when it hovers off of the object
        virtual void setHovered(bool setHovered);

        //Sets main text output for this instance of class
        virtual void setMainTextLog(TextLog* TextLogIn);

        bool clicked = false;

        TextLog* mainTextLog;//Main destination for text outputs from this object

        sf::IntRect reserveSpace; // Used for reserving space for objects created when this object is clicked or hovered

    protected:

    private:
};

#endif // CLICKABLE_H
