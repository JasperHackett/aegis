#include "RenderObject.hpp"
#include <SFML/Graphics.hpp>

RenderObject::RenderObject()
{
    //ctor
}

RenderObject::~RenderObject()
{
    //dtor
}

void RenderObject::addSprite(sf::Texture *textureIn, std::string name){
    sf::Sprite newSprite;
    newSprite.setTexture((*textureIn));
    std::vector<sf::Sprite>::iterator iter;
    std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator> pairIn = {newSprite,iter};

    this->spriteMap.insert(std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::value_type(name,pairIn));

}

std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> RenderObject::getSpriteMap(){
    return spriteMap;
}

void RenderObject::setSpriteMap(std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> spriteMapIn){
    this->spriteMap = spriteMapIn;
}

//void RenderObject::setSpriteVector(std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> vecIn){
//    this->spriteVector = vecIn;
//}
//
//
//
//
//
//std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator RenderObject::getSpriteVecIter(std::string name){
//    return spriteNameIteratorMap[name];
//}
//
//void RenderObject::setSpriteVecIter(std::string name, std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator iterIn){
//    spriteNameIteratorMap[name] = iterIn;
//
//}
//
void RenderObject::setSpritePosition(std::string name, float x, float y){
    spriteMap.at(name).first.setPosition(x,y);
}

