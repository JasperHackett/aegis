#include "TextureManager.hpp"
#include <SFML/graphics.hpp>
#include <map>

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

//Loads textures and adds to map
void TextureManager::loadTexture(const std::string &name, const std::string &filename){
    sf::Texture texIn;
    texIn.loadFromFile(filename);
    this->textureMap[name] = texIn;
}

sf::Texture *TextureManager::getTexture(const std::string& name){
    sf::Texture* textPtr = &this->textureMap.at(name);
    return textPtr;
}
