#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <vector>
#include <utility>
#include <SFML/graphics.hpp>
#include <functional>

class RenderObject{
    public:
        RenderObject();
        virtual ~RenderObject();

        //Get & set sprite map
        virtual std::map<std::string,sf::Sprite> getSpriteMap();
        virtual void setSpriteMap(std::map<std::string,sf::Sprite> spriteMapIn);

        //Add sprite to map, key:name
        virtual void addSprite(sf::Texture *textureIn, std::string name);

        //Sets individual sprite position
        virtual void setSpritePosition(std::string name, float x, float y);

        //Get & set object position and size
        virtual sf::IntRect getPos();
        virtual void setPos(sf::IntRect posIn);
        virtual void setPos(sf::Vector2i posInXY); //Sets only X&Y position of object, does not change size

        //Changes texture rectangle of sprite
        virtual void setTextureRect(std::string name,sf::IntRect textRect);


        //Renders object
        virtual void draw(sf::RenderWindow &window);

//        //Set true when mouse hovers over an object, false when it hovers off of the object
//        virtual void setHovered(bool isHovered);

        bool rendered = false;
        sf::IntRect pos; //Stores object position
        std::map<std::string,sf::Sprite> spriteMap; //Key: name (e.g. "head") Value: sprite


    protected:

    private:

};


#endif // RENDEROBJECT_H
