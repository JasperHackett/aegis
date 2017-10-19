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
    this->spriteVector.push_back(std::make_pair(newSprite,std::vector<sf::Sprite>::iterator()));
    this->spriteNameIteratorMap[name] = spriteVector.end();

}

std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> RenderObject::getAllSprites(){
    return spriteVector;
}

void RenderObject::setSpriteVector(std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> vecIn){
    this->spriteVector = vecIn;
}





std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator RenderObject::getSpriteVecIter(std::string name){
    return spriteNameIteratorMap[name];
}

void RenderObject::setSpriteVecIter(std::string name, std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator iterIn){
    spriteNameIteratorMap[name] = iterIn;

}

void RenderObject::setSpritePosition(std::string name, float x, float y){
    sf::Sprite testSprite;
    std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator iter = spriteNameIteratorMap[name];
    spriteVector.at(iter)
}

