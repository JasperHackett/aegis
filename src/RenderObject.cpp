#include "RenderObject.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

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
    sf::Sprite* spritePtr; //Pointer that holds the position in the render vector
    std::pair<sf::Sprite,sf::Sprite*> pairIn = {newSprite,spritePtr};

    this->spriteMap.insert(std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>>::value_type(name,pairIn));

}

std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> RenderObject::getSpriteMap(){
    return spriteMap;
}

void RenderObject::setSpriteMap(std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> spriteMapIn){
    this->spriteMap = spriteMapIn;
}

void RenderObject::setSpritePosition(std::string name, float x, float y){
    spriteMap.at(name).first.setPosition(x,y);
}

sf::IntRect RenderObject::getPos(){
    return this->pos;
}
void RenderObject::setPos(sf::IntRect posIn){
    this->pos = posIn;
}

void RenderObject::setHovered(bool isHovered){
    if(isHovered == true){
        std::cout << "object hovered" << std::endl;
    }else{
        std::cout << "object not hovered" << std::endl;
    }

}

void RenderObject::updateSprite(std::string name, RenderManager* rendMgr){
    rendMgr->updateSprite(spriteMap[name].second,spriteMap[name].first);
}
