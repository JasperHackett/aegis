#ifndef CLICKMANAGER_H
#define CLICKMANAGER_H

    #include <SFML/graphics.hpp>
    #include <map>

class Clickable; //Forward declaration

class ClickManager
{
    public:
        ClickManager();
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

        virtual void exitGame();

    protected:

    private:
        bool somethingHovered = false;
        sf::RenderWindow* windowPtr;
        sf::Vector2i mousePos;
        Clickable* hoveredObject = nullptr;
        Clickable* mousePressedObject = nullptr;
        Clickable* clickedObject = nullptr;
        Clickable* parentObject = nullptr; //Stores the parent of an object with nested clicks.
        std::vector<Clickable*> visibleObjects;

        std::vector<Clickable*> nestedObjects; //Stores objects nested in another object
};

#endif // CLICKMANAGER_H
