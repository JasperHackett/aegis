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

        //Get & set object position
        virtual sf::IntRect getPos();
        virtual void setPos(sf::IntRect posIn);

        //Changes texture rectangle of sprite
        virtual void setTextureRect(std::string name,sf::IntRect textRect);

        //Changes hovered state
        virtual void setHovered(bool isHovered);

        //Assign a function to be called when object is hovered
        virtual void assignHoverFunction(std::function<void(RenderObject*,bool)> hoverFunc);

        //Renders object
        virtual void draw(sf::RenderWindow &window);

    protected:

    private:

        sf::IntRect pos; //Stores object position
        std::map<std::string,sf::Sprite> spriteMap; //Key: name (e.g. "head") Value: sprite

        std::function<void(RenderObject*,bool)> hoverFunction;

};


#endif // RENDEROBJECT_H
