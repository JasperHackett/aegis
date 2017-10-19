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

std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> RenderManager::addMultiObjects(
                                                                                         std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>> mapIn){

    std::map<std::string,std::pair<sf::Sprite,std::vector<sf::Sprite>::iterator>>::iterator it;
    for(it = mapIn.begin(); it != mapIn.end(); it++){
        it->second.second = addObject(it->second.first);

    }
    return mapIn;
}

void RenderManager::render(sf::RenderWindow &window){

    for(sf::Sprite& sprite : renderVector){
        window.draw(sprite);
    }


}
