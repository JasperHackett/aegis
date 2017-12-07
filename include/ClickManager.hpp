#ifndef CLICKMANAGER_H
#define CLICKMANAGER_H

    #include "Clickable.hpp"
    #include <SFML/graphics.hpp>
    #include <map>

class ClickManager
{
    public:
        ClickManager();
        virtual ~ClickManager();

        //Adds object to vector of objects that interact with the mouse (hovering & clicking)
        virtual void addObject(Clickable* objectIn);
        virtual void checkHover(sf::Vector2i mousePos);

        //True when left mouse is pressed. False when released
        void leftMouseClick(bool mouseDown);

    protected:

    private:
        bool somethingHovered = false;
        sf::Vector2i mousePos;
        Clickable* hoveredObject = nullptr;
        Clickable* mousePressedObject = nullptr;
        Clickable* clickedObject = nullptr;
        std::vector<Clickable*> visibleObjects;
        sf::IntRect reserveSpace; /*When an object is clicked that creates further click options this stores the area in which
        those options appear (e.g When using character ability the areea with actions */
};

#endif // CLICKMANAGER_H
