#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/graphics.hpp>
#include <map>


class TextureManager
{
    public:
        TextureManager();
        virtual ~TextureManager();

        //Loads textures from file and adds to map
        void loadTexture(const std::string &name, const std::string &filename);

        //Returns a reference to a texture in the map
        sf::Texture *getTexture(const std::string &name);

    protected:

    private:

        //Map of textures
        std::map<std::string, sf::Texture> textureMap;
};

#endif // TEXTUREMANAGER_H
