#ifndef CLICKMANAGER_H
#define CLICKMANAGER_H

    #include "renderobject.hpp"
    #include <SFML/graphics.hpp>
    #include <map>

class ClickManager
{
    public:
        ClickManager();
        virtual ~ClickManager();

        virtual void addObject(RenderObject* objectIn);
        virtual void checkHover(sf::Vector2i mousePos);

    protected:

    private:
        bool somethingHovered = false;
        RenderObject* hoveredObject = nullptr;
        std::vector<RenderObject*> visibleObjects;
        RenderManager* mgrPtr;
};

#endif // CLICKMANAGER_H
