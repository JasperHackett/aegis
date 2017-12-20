#include <ObjectManager.hpp>
#include <iostream>

ObjectManager::ObjectManager(){
    //ctor
}

ObjectManager::~ObjectManager(){
    //dtor
}


//Iterates through visibleObjects drawing each object to window (using SFML draw call)
void ObjectManager::render(sf::RenderWindow &window){
    for(RenderObject *object : visibleObjects){
        object->draw(window);
    }
}
//Adds instance of RenderObject class to visibleObjects
void ObjectManager::addVisible(RenderObject* objectIn){
    objectIn->rendered = true;
    this->visibleObjects.push_back(objectIn);
}
void ObjectManager::addVisible(RenderObject* objectIn, bool backOfVector){
    if(backOfVector){
        objectIn->rendered = true;
        this->visibleObjects.push_back(objectIn);
    }else{
        objectIn->rendered = true;
        visibleObjects.push_back(*visibleObjects.begin());
        visibleObjects.insert(visibleObjects.begin(),objectIn);
    }
}


//Load a texture from file and insert into textureMap with name as key
void ObjectManager::loadTexture(const std::string &name, const std::string &filename){
    sf::Texture texIn;
    texIn.loadFromFile(filename);
    this->textureMap[name] = texIn;
}


//Load a font from file and insert into fontMap with name as key
void ObjectManager::loadFont(const std::string &name, const std::string &filename){
    sf::Font fontIn;
    fontIn.loadFromFile(filename);
    this->fontMap[name] = fontIn;
}




//Gets pointer to texture from map for assigning to sprite object
sf::Texture *ObjectManager::getTexture(const std::string& name){
    sf::Texture* textPtr = &this->textureMap.at(name);
    return textPtr;
}

//Gets pointer to font from map for assigning to text object
sf::Font *ObjectManager::getFont(const std::string& name){
    sf::Font* fontPtr = &this->fontMap.at(name);
    return fontPtr;
}



//Removes objects from visibleObjects
void ObjectManager::removeObjects(){
//    this->visibleObjects.erase(std::remove(visibleObjects.begin(),visibleObjects.end(),objectToBeRemoved), visibleObjects.end());

    std::vector<RenderObject*> newVisibleObjects;

    std::vector<RenderObject*>::iterator iter;
    for(iter = visibleObjects.begin(); iter != visibleObjects.end(); ++iter){
        if((*iter)->rendered){
            newVisibleObjects.push_back(*iter);
        }
    }

    visibleObjects = newVisibleObjects;
}

