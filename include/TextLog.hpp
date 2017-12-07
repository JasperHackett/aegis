#ifndef TEXTLOG_H
#define TEXTLOG_H

#include <SFML/Graphics.hpp>
#include <RenderObject.hpp>


class TextLog : public RenderObject {
    public:
        TextLog(int displayedLines);
        virtual ~TextLog();

        void setFieldWidth(int fieldWidth); //sets width of line
        int getFieldWidth();

        void setNewLinePos(sf::Vector2f newLinePos); //sets bottom left corner of where text will appear
        sf::Vector2f getNewLinePos();

        void setFont(sf::Font* fontIn);

        void draw(sf::RenderWindow &window);

        //Add text, fits to line width
        void addText(std::string textIn);



    protected:

    private:


        std::vector<sf::Text> textVector;     //Stores a vector of each line of text
        int fieldWidth = 0;     //Stores width of text field
        int lineCount = 0;  //Stores amount of lines in text entry
        int displayedLines;
        sf::Vector2f newLinePos; //stores position of each new line (bottom of text log)

        int textSize = 12;
        sf::Color textColour = sf::Color::Red;
        sf::Font textFont;




};

#endif // TEXTLOGENTRY_H
