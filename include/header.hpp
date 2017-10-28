#ifndef HEADER_HPP
#define HEADER_HPP


#include <SFML/Graphics.hpp>
#include <RenderManager.hpp>
#include <TextureManager.hpp>
#include <RenderObject.hpp>
#include <ClickManager.hpp>


//Temporarily static values
float resHeight = 900;
float resWidth = 1600;
bool fullscreen = false;
sf::Vector2i mousePos;


//Core UI data strctures
TextureManager textureMgr;
RenderManager renderMgr;



#endif // HEADER_HPP





