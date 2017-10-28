#include "RenderManager.hpp"
#include <iostream>
RenderManager::RenderManager()
{
    //ctor
}

RenderManager::~RenderManager()
{
    //dtor
}

sf::Sprite* RenderManager::addObject(sf::Sprite spriteIn){
    sf::Sprite newSprite;
    newSprite = spriteIn;
    this->renderVector.push_back(newSprite);
    return &renderVector.back();

}

std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> RenderManager::addMultiObjects(std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>> mapIn){

    std::map<std::string,std::pair<sf::Sprite,sf::Sprite*>>::iterator it;
    for(it = mapIn.begin(); it != mapIn.end(); it++){
        it->second.second = addObject(it->second.first);
    }
    return mapIn;
}

void RenderManager::updateSprite(sf::Sprite* spritePosition, sf::Sprite spriteIn){
    sf::Sprite newSprite;
    newSprite = spriteIn;
    addObject(newSprite);
}

void RenderManager::render(sf::RenderWindow &window){

    for(sf::Sprite& sprite : renderVector){
        window.draw(sprite);
    }


}
