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
    this->spriteMap.insert(std::pair<std::string,sf::Sprite>(name,newSprite));

}
void RenderObject::addText(sf::Font* fontPtr, std::string name,std::string content, sf::Color colourIn, int sizeIn){
    sf::Text newText;
    newText.setFont(*fontPtr);
    newText.setColor(colourIn);
    newText.setCharacterSize(sizeIn);
    newText.setString(content);
    this->textMap.insert(std::pair<std::string,sf::Text>(name,newText));
}
int RenderObject::getTextWidth(std::string key){
    return textMap.at(key).getGlobalBounds().width;
}

std::map<std::string,sf::Sprite> RenderObject::getSpriteMap(){
    return spriteMap;
}

void RenderObject::setSpriteMap(std::map<std::string,sf::Sprite> spriteMapIn){
    this->spriteMap = spriteMapIn;
}

void RenderObject::setSpritePosition(std::string name, float x, float y){
    spriteMap.at(name).setPosition(x,y);
}
void RenderObject::setTextPosition(std::string name, float x, float y){
    textMap.at(name).setPosition(x,y);
}

sf::IntRect RenderObject::getPos(){
    return this->pos;
}
void RenderObject::setPos(sf::IntRect posIn){
    this->pos = posIn;
}
void RenderObject::setPos(sf::Vector2i posInXY){
    this->pos.top = posInXY.x;
    this->pos.left = posInXY.y;
}


void RenderObject::draw(sf::RenderWindow &window){
    std::map<std::string,sf::Sprite>::iterator it;
    for(it = spriteMap.begin(); it != spriteMap.end(); it++){
        window.draw(it->second);
    }

    std::map<std::string,sf::Text>::iterator it2;
    for(it2 = textMap.begin(); it2 != textMap.end(); it2++){
        window.draw(it2->second);
    }
}

//Changes texture rectangle of sprite
void RenderObject::setTextureRect(std::string name, sf::IntRect textRect){
    spriteMap.at(name).setTextureRect(textRect);

}

//TEMPORARILY DISABLED IN ATTEMPT TO TEST THIS FUNCTION IN CLICKABLE CLASS
////Set true when mouse hovers over an object, false when it hovers off of the object
//void RenderObject::setHovered(bool setHovered){
//    if(setHovered){
//        std::cout << "Generic object hovered" << std::endl;
//    }else{
//       std::cout << "Object un-hovered" << std::endl;
//    }
//
//}



