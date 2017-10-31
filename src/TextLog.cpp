#include "TextLogEntry.hpp"
#include <iostream>
TextLogEntry::TextLogEntry()
{

}

TextLogEntry::~TextLogEntry()
{
    //dtor
}

//void TextLogEntry::draw(sf::RenderWindow &window){
//    for(sf::Text textLine : textVector){
//        window.draw(textLine);
//    }
//}


 void TextLogEntry::setFont(sf::Font* fontIn){
    this->textFont = *fontIn;
 }

//Get and set field width
void TextLogEntry::setFieldWidth(int fieldWidth){
    this->fieldWidth = fieldWidth;
}
int TextLogEntry::getFieldWidth(){
    return fieldWidth;
}

//Adds text and fits to line width
void TextLogEntry::addText(std::string textIn){
    sf::Text newText;
    newText.setString(textIn);
    newText.setFont(textFont);
    newText.setFillColor(textColour);
    newText.setCharacterSize(textSize);

    if(fieldWidth > 0){
        int lineWidth = newText.getGlobalBounds().width;
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
                this->textVector.push_back(newText);
                remainderLine = " " + textIn.substr(lineBreakPos, textIn.length()-1);

               addText(remainderLine);

        }else{
            this->textVector.push_back(newText);
        }
    }



}
