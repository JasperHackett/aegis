#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <vector>
#include <utility>
#include <SFML/graphics.hpp>

class RenderObject{
    public:
        RenderObject();
        virtual ~RenderObject();

        //Returns vector of sprite and renderVector iterator pairings
        virtual std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> getAllSprites();

        //Updates the position each sprite is stored in in the render vector
        virtual void setSpriteVector(std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>);

        //Add sprite to vector, sets render iterator to null and assigns name for spriteNameIteratorMap
        virtual void addSprite(sf::Texture *textureIn, std::string name);

        //Get&set Iterator of sprite in pair vector
        virtual std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator getSpriteVecIter(std::string name);
        virtual void setSpriteVecIter(std::string name, std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator iterIn);

        //Sets individual sprite position
        virtual void setSpritePosition(std::string name, float x, float y);

    protected:

    private:
        //Vector of pairs holding the sprite and an iterator to the sprites position in renderVector
        std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> spriteVector;
        //Key is user defined name of sprite, value is an iterator of the  pair with the sprite  and renderVector iterator
        std::map<std::string,std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator> spriteNameIteratorMap;

};


#endif // RENDEROBJECT_H
