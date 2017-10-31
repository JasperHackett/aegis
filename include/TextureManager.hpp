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

        //Load font and add to map
        void loadFont(const std::string &name, const std::string &filename);

        //Returns a reference to a font in map
        sf::Font *getFont(const std::string &name);

    protected:

    private:

        //Map of textures
        std::map<std::string, sf::Texture> textureMap;

        //Map of fonts
        std::map<std::string, sf::Font> fontMap;
};

#endif // TEXTUREMANAGER_H
