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
        sf::Sprite* addObject(sf::Sprite spriteIn);

        //Adds a vector of sprites and updates the sprite in each pair with the index in main render vertex
        std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> addMultiObjects(std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> mapIn);



        void removeObject();

        void updateSprite(sf::Sprite* spritePosition, sf::Sprite spriteIn);

        std::vector<sf::Sprite> renderVector;

    protected:

    private:

};

#endif // RENDERMANAGER_H
