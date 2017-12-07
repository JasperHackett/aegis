#ifndef HEADER_HPP
#define HEADER_HPP


#include <SFML/Graphics.hpp>
#include <ClickManager.hpp>
#include <iostream>
#include <TextLog.hpp>
#include <ObjectManager.hpp>
#include <buttons.hpp>
#include <Unit.hpp>
//Constants
float resHeight;
float resWidth;
bool fullscreen;
sf::Vector2i mousePos;


//Core UI data strctures
ObjectManager objectMgr;
ClickManager clickMgr;
TextLog mainEventLog(6);


//Other



#endif // HEADER_HPP





