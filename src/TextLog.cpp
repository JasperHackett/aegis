#include "TextLog.hpp"
#include <iostream>
TextLog::TextLog(int displayedLines)
{
    this->displayedLines = displayedLines;
    for(int i = 0; i < displayedLines; i++){
        sf::Text newText;
        newText.setString(" ");
        this->textVector.push_back(newText);
    }
}

TextLog::~TextLog()
{
    //dtor
}

void TextLog::draw(sf::RenderWindow &window){

    std::map<std::string,sf::Sprite>::iterator it;
    for(it = spriteMap.begin(); it != spriteMap.end(); it++){
        window.draw(it->second);
    }

    std::vector<sf::Text>::iterator texIt;
    for(texIt = textVector.end() - displayedLines; texIt != textVector.end(); texIt++){
                window.draw(*texIt);
    }
}


 void TextLog::setFont(sf::Font* fontIn){
    this->textFont = *fontIn;
 }

//Get and set field width
void TextLog::setFieldWidth(int fieldWidth){
    this->fieldWidth = fieldWidth;
}
int TextLog::getFieldWidth(){
    return fieldWidth;
}

//Adds text and fits to line width
void TextLog::addText(std::string textIn){
    //Initialise newText object
    sf::Text newText;
    newText.setString(textIn);
    newText.setFont(textFont);
    newText.setFillColor(textColour);
    newText.setCharacterSize(textSize);
    newText.setPosition(newLinePos);

        //Push up all lines
        for(int i = 0; i < displayedLines; i++){
            sf::Vector2f tempTextPos = textVector[textVector.size() - i].getPosition();
            tempTextPos.y = tempTextPos.y - textSize;
            textVector[textVector.size()-i].setPosition(tempTextPos);
        }

    int lineWidth = newText.getGlobalBounds().width;

    if(fieldWidth > 0 && lineWidth > 0){


        if(fieldWidth < lineWidth){ //If length of line is larger than the text field begin cutting line

                int charCount = textIn.length();
                std::string newOriginalLine;
                std::string remainderLine;

                //Attempt to roughly break the line based on width. Not exact as width depends on characters, e.g "W" > "."
                int lineBreakPos = charCount * fieldWidth/lineWidth;

                while(textIn.at(lineBreakPos) != ' ' && lineBreakPos > 1){ // Parse left until space for break position
                    lineBreakPos--;
                }
                if(lineBreakPos == 0){
                    //Case where no spaces or blank line ??
                    std::cout << "error in string" << std::endl;
                    return;
                }

                newOriginalLine = textIn.substr(0,lineBreakPos); //First line is equal everything before break
                newText.setString(newOriginalLine);
                std::cout << newText.getGlobalBounds().width << std::endl; //TESTING
                this->textVector.push_back(newText);
                remainderLine = textIn.substr(lineBreakPos, textIn.length()-1);
                this->lineCount ++;
                addText(remainderLine);

        }else{
            this->textVector.push_back(newText);
        }
    }else{
            std::cout << "error in string" << std::endl;
            return;
    }



}

//sets bottom left corner of where text will appear
void TextLog::setNewLinePos(sf::Vector2f newLinePos){

    this->newLinePos = newLinePos;
}

sf::Vector2f TextLog::getNewLinePos(){
    return this->newLinePos;
}
