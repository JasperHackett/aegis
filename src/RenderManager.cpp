#include "RenderManager.hpp"

RenderManager::RenderManager()
{
    //ctor
}

RenderManager::~RenderManager()
{
    //dtor
}

std::vector<sf::Sprite>::iterator RenderManager::addObject(sf::Sprite spriteIn){
    sf::Sprite newSprite;
    newSprite = spriteIn;
    this->renderVector.push_back(newSprite);
    std::vector<sf::Sprite>::iterator iter = renderVector.end();
    return iter;

}

std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> RenderManager::addMultiObjects(std::vector<std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> vecIn){
    for(int i = 0; i < vecIn.size(); i++){
        vecIn.at(i).second = addObject(vecIn.at(i).first);
    }
    return vecIn;

}

void RenderManager::render(sf::RenderWindow &window){

    for(sf::Sprite& sprite : renderVector){
        window.draw(sprite);
    }


}
