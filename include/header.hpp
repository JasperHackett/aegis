#ifndef HEADER_HPP
#define HEADER_HPP


#include <SFML/Graphics.hpp>
#include <ClickManager.hpp>
#include <RenderObject.hpp>
#include <iostream>
#include <stdio.h>
#include <TextLog.hpp>
#include <ObjectManager.hpp>
#include <global.hpp>
#include <GameController.hpp>
#include <fstream>
#include <cstring>
#include <string>
//Constants


float resHeight = 1600;
float resWidth = 900;
bool fullscreen;


sf::Vector2i mousePos;

std::ifstream inFile;




//Core game manager.
sf::RenderWindow mainWindow;

//Core UI data strctures
TextLog mainEventLog(10);
ObjectManager objectMgr;
GameController gameControl(&objectMgr, &mainEventLog,&mainWindow);
BoardController boardControl(&objectMgr,&mainEventLog);
ClickManager clickMgr(&gameControl, &boardControl);




//Other



#endif // HEADER_HPP





