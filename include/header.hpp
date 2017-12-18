#ifndef HEADER_HPP
#define HEADER_HPP


#include <SFML/Graphics.hpp>
#include <ClickManager.hpp>
#include <RenderObject.hpp>
#include <iostream>
#include <TextLog.hpp>
#include <ObjectManager.hpp>
#include <global.hpp>
//#include <GameController.hpp>
//Constants
float resHeight;
float resWidth;
bool fullscreen;

sf::Vector2i mousePos;

//Core game manager.

//Core UI data strctures
TextLog mainEventLog(10);
ObjectManager objectMgr;
<<<<<<< HEAD
GameController gameControl(&objectMgr, &mainEventLog);
BoardController boardControl(&objectMgr,&mainEventLog);
ClickManager clickMgr(&gameControl, &boardControl);
=======
//GameController gameControl(&objectMgr, &mainEventLog);
BoardController boardControl(&objectMgr,&mainEventLog);

ClickManager clickMgr(&boardControl);
>>>>>>> 5ab01b6a44594a9c060eae5a5931b1b6a356bc9c




//Other



#endif // HEADER_HPP





