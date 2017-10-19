#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <vector>
#include <utility>
#include <SFML/graphics.hpp>

class RenderObject{
    public:
        RenderObject();
        virtual ~RenderObject();

        //Get & set sprite map
        virtual std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> getSpriteMap();
        virtual void setSpriteMap(std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> spriteMapIn);

        //Add sprite to map, sets iterator to null
        virtual void addSprite(sf::Texture *textureIn, std::string name);

        //Sets individual sprite position
        virtual void setSpritePosition(std::string name, float x, float y);

    protected:

    private:


        std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> spriteMap;



};


#endif // RENDEROBJECT_H
