#ifndef TEXTLOGENTRY_H
#define TEXTLOGENTRY_H

#include <SFML/Graphics.hpp>



class TextLogEntry {
    public:
        TextLogEntry();
        virtual ~TextLogEntry();

        void setFieldWidth(int fieldWidth);
        int getFieldWidth();

        void setFont(sf::Font* fontIn);

//        void draw(sf::RenderWindow &window);

        //Add text, fits to line width
        void addText(std::string textIn);



    protected:

    private:


        std::vector<sf::Text> textVector;     //Stores a vector of each line of text
        int fieldWidth = 0;     //Stores width of text field
        int lineCount = 0;  //Stores amount of lines in text entry

        int textSize = 12;
        sf::Color textColour = sf::Color::Red;
        sf::Font textFont;




};

#endif // TEXTLOGENTRY_H
