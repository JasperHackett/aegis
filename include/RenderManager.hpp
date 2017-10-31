#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include<SFML/Graphics.hpp>
#include "RenderObject.hpp"

class RenderManager
{
    public:
        RenderManager();
        virtual ~RenderManager();
        //Main render function
        void render(sf::RenderWindow &window);

        //Adds object and returns position pointer in vector
        void addObject(RenderObject* renderObjectIn);

        void removeObject();



    protected:

    private:
          std::vector<RenderObject*> renderedGameObjects;

};

#endif // RENDERMANAGER_H
