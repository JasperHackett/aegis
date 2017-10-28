#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <vector>
#include <utility>
#include "RenderManager.hpp"
#include <SFML/graphics.hpp>

class RenderObject{
    public:
        RenderObject();
        virtual ~RenderObject();

        //Get & set sprite map
        virtual std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> getSpriteMap();
        virtual void setSpriteMap(std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> spriteMapIn);

        //Add sprite to map, sets iterator to null
        virtual void addSprite(sf::Texture *textureIn, std::string name);

        void updateSprite(std::string name, RenderManager* rendMgr);

        //Sets individual sprite position
        virtual void setSpritePosition(std::string name, float x, float y);

        //Get & set real position
        virtual sf::IntRect getPos();
        virtual void setPos(sf::IntRect posIn);

        //Set state to hovered
        virtual void setHovered(bool isHovered);

    protected:

    private:

        sf::IntRect pos;

        std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> spriteMap;



};


#endif // RENDEROBJECT_H
