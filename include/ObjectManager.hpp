#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <SFML/Graphics.hpp>
#include <RenderObject.hpp>

class ObjectManager{
    public:
        ObjectManager();
        virtual ~ObjectManager();

        //Iterates through visibleObjects drawing each object to window (using SFML draw call)
        void render(sf::RenderWindow &window);

        //Adds instance of RenderObject class to visibleObjects
        void addVisible(RenderObject* renderObjectIn);
        void addVisible(RenderObject* objectIn, bool backOfVector);

        //Load a texture from file and insert into textureMap with name as key
        void loadTexture(const std::string &name, const std::string &filename);

        //Load a font from file and insert into fontMap with name as key
        void loadFont(const std::string &name, const std::string &filename);

        //Gets pointer to font from map for assigning to text object
        sf::Font* getFont(const std::string& name);


       //Gets pointer to font from map for assigning to text object
        sf::Texture* getTexture(const std::string& name);


        //Removes all objects marked for removal and resizes vector
        virtual void removeObjects();




    protected:

    private:

        std::vector<RenderObject*> visibleObjects; //Stores all objects that are rendered
        std::map<std::string, sf::Texture> textureMap; //Stores textures with string as map (e.g. "exitbtn")
        std::map<std::string, sf::Font> fontMap; //Stores fonts with string as name (e.g. "trebuc")

};


#endif //OBJECTMANAGER_H
