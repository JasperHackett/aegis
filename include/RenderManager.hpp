#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include<SFML/Graphics.hpp>


class RenderManager
{
    public:
        RenderManager();
        virtual ~RenderManager();
        //Main render function
        void render(sf::RenderWindow &window);

        //Adds object and returns position pointer in vector
        std::vector<sf::Sprite>::iterator addObject(sf::Sprite spriteIn);

        //Adds a vector of sprites and updates the sprite in each pair with the index in main render vertex
        std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> addMultiObjects(
                                                                                          std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> mapIn);

        void removeObject();

    protected:

    private:
        std::vector<sf::Sprite> renderVector;
};

#endif // RENDERMANAGER_H
